#ifndef Channel_h_
#define Channel_h_

//#include "Poco/Lock.h"
#include "Poco/Mutex.h"
#include "Poco/Condition.h"
//using Poco::Lock;
using Poco::Mutex;
using Poco::Condition;

template < typename _Tp, typename _queueTp = std::deque<_Tp> >
class Channel : private _queueTp
{
private:
	Mutex monitor_;
	Condition bufferNotFull_;
	Condition bufferNotEmpty_;
	volatile bool bMayStop_;
public:
	// for consumer thread...
	_Tp poll(long msecs = -1) // ignore msecs for now, 
	{
		Lock lk(monitor_);
		while (!bMayStop_ && 0 == ((_queueTp *)this)->size())
		{
			bufferNotEmpty_.wait(lk);
		}
		// check if caller intentionally calls for stop
		if (bMayStop_ && 0 == ((_queueTp *)this)->size())
			throw pc_exception("consumer to end");
		// pop back
		_Tp item = pop();
		bufferNotFull_.notify_one();
		return item;
	}
	// for producer thread...
	bool offer(_Tp item, long msecs = -1) // ignore msecs for now
	{
		Lock lk(monitor_);
		while (maxSize_ == ((_queueTp *)this)->size())
		{
			bufferNotFull_.wait(lk);
		}
		// push front
		push(item);
		bufferNotEmpty_.notify_one();
		return true;
	}
	virtual void mayStop(bool bMayStop = true)
	{
		Lock lk(monitor_);
		bMayStop_ = bMayStop;
		if (bMayStop)
		{
			// if producers exit, wake up the 
			// waiting consumer threads...
			bufferNotEmpty_.notify_all();
		}
	}
}; // Channel
#endif