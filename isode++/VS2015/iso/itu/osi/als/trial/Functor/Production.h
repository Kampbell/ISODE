#ifndef Production_h_
#define Production_h_

template < typename _Tp,
  typename _ChannelTp = Channel<_Tp>, 
  typename _ProducerTp = Producer<_Tp, _ChannelTp>, 
  typename _ConsumerTp = Consumer<_Tp, _ChannelTp> >
class Production
{
public:
	void operator()()
	{
		_ChannelTp chan(queueLen_);
		Latch theLatch, noLatch(true);
		_ProducerTp* producer = new _ProducerTp(chan, noLatch);
		_ConsumerTp* consumer = new _ConsumerTp(chan, syncStart_ ?	theLatch : noLatch);
		std::auto_ptr<_ProducerTp> prodClean(producer);
		std::auto_ptr<_ConsumerTp> consClean(consumer);
		consumer->mayStop(false);
		// callback function for derived classes...
		pcModelCreated(*producer, *consumer);
		try {
			boost::thread_group pthreads, cthreads;
			int i;
			for (i = 0; i < nProducers_; ++i)
				pthreads.create_thread(*producer);
			for (i = 0; i < nConsumers_; ++i)
				cthreads.create_thread(*consumer);
			theLatch.release();
			beforeJoin();
			pthreads.join_all();
			while (chan.size() > 0) sleep(0, 10);
			// producers are done, consumers *may* stop...
			consumer->mayStop(true);
			cthreads.join_all();
			afterJoin();
		}
		catch (boost::lock_error& err) {
			Logger::log(err.what());
		}
		catch (std::exception& err) {
			Logger::log(err.what());
		}
		catch (...) {
			Logger::log("catched...");
		}
	}
};

#endif