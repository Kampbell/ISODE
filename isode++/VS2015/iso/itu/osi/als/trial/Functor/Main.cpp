#include <iostream>
#include <string>
#include <thread>
#include "Poco/StringTokenizer.h"
#include "Poco/Format.h"
using Poco::format;
using Poco::StringTokenizer;


#include "atomicops.h"
#include "readerwriterqueue.h"

using namespace std;
using namespace moodycamel;

class Sender {
public:
	virtual int  operator()(int cc = 0, const void* data = NULL) = 0;
};
class Receiver {
public:
	virtual int  operator()(int cc = 0, void* data = NULL) = 0;
};


class Buffer {
public:
	int  len;
	char bytes[256];
};

class BufferSender : public Sender {
private:
	Buffer& buffer;

public:
	BufferSender(Buffer& buffer) : buffer(buffer) {}

	virtual int  operator()(int cc = 0, const void* data = NULL) {
		memcpy(buffer.bytes, data, buffer.len = cc); return buffer.len; 
	}
};
class BufferReceiver : public Receiver {
private:
	Buffer& buffer;

public:
	BufferReceiver(Buffer& buffer) : buffer(buffer) {}

	virtual int  operator()(int cc = 0, void* data = NULL) {
		memcpy(data, buffer.bytes, buffer.len); return buffer.len; 
	}
};
class BufferChannel {
public:
	BufferChannel(Buffer& buffer) : send(buffer), recv(buffer) {}
	BufferSender send;
	BufferReceiver recv;

};
class FixedBuffer {
	char	buffer[32];
public:

	bool operator==(const FixedBuffer& b) { return memcmp(buffer, b.buffer, sizeof(buffer)) == 0; }

};
int main(int argc, char** argv) {
	{
		StringTokenizer st("+alpha", "+", StringTokenizer::TOK_IGNORE_EMPTY);
		cout << "count=" << st.count() << endl;
		for (int no = 0; no < st.count(); no++) {
			cout << "token[" << no << "]=" << st[no] << endl;
		}
	}
	{
		StringTokenizer st("alpha+", "+", StringTokenizer::TOK_IGNORE_EMPTY);
		cout << "count=" << st.count() << endl;
		for (int no = 0; no < st.count(); no++) {
			cout << "token[" << no << "]=" << st[no] << endl;
		}
	}
	{
		StringTokenizer st("alpha+beta+", "+", StringTokenizer::TOK_IGNORE_EMPTY);
		cout << "count=" << st.count() << endl;
		for (int no = 0; no < st.count(); no++) {
			cout << "token[" << no << "]=" << st[no] << endl;
		}
	}

	return 0;

    int j = 0;
    printf("0x%.8X = %#08X = %#.8X = %#010x\n", j, j, j, j);

	string hexa = format("0x%8X = %#08X = %#.8X = %#02x\n", j, j, j, j);
	cout << hexa << endl;

	return 0;

    for (int i = 0; i < 8; i++)
    {
        j = (j << 4) | (i + 6);
        printf("0x%.8X = %#08X = %#.8X = %#010x\n", j, j, j, j);
    }
    return(0);

	Buffer buffer;
	BufferChannel bc(buffer);
	string s;
	char data[256];
	int send = bc.send(4, "abcd");
	int recv = bc.recv(256, data);


	cout << string(data, recv) << endl;

	ReaderWriterQueue<FixedBuffer> q(100);       // Reserve space for at least 100 elements up front

	FixedBuffer fb1;
	FixedBuffer fb2;
	q.enqueue(fb1);                       // Will allocate memory if the queue is full
	bool succeeded = q.try_enqueue(fb2);  // Will only succeed if the queue has an empty slot (never allocates)
	assert(succeeded);

	FixedBuffer number;
	succeeded = q.dequeue(number);  // Returns false if the queue was empty

	assert(succeeded && number == fb1);

	// You can also peek at the front item of the queue (consumer only)
	FixedBuffer* front = q.peek();              // Returns nullptr if the queue was empty
	assert(*front == fb2);
	succeeded = q.dequeue(number);
	assert(succeeded && number == fb2);
	front = q.peek();
	assert(front == nullptr);


	BlockingReaderWriterQueue<int> brwq;

	std::thread reader([&]() {
		int item;
		for (int i = 0; i != 100; ++i) {
			brwq.wait_dequeue(item);
		}
	});
	std::thread writer([&]() {
		for (int i = 0; i != 100; ++i) {
			brwq.enqueue(i);
		}
	});
	writer.join();
	reader.join();

	assert(brwq.size_approx() == 0);
	return 0;
}

#if 0
#include "Channel.h"
#include "Production.h"

struct NetworkService
{
  // sub-classes overwrite this method and close socket 
  virtual void ServiceHandler(int socket) = 0;
  virtual bool stop() { return false; } 
  void operator()()
  {
    int server = createServerSocket(sourcePort, lengthWaitList+1);
    if(server < 0)
    {
      std::cout << "Can't bind to port " 
        << sourcePort << std::endl;
      return;
    }
    RunPool<SocketHandler> pool(numThreads);
    ThreadPool<SocketHandler> thpool(pool, 
      numThreads > 256 ? 256 : numThreads);
    // start the pool...
    boost::thread thrd(thpool);
    std::cout << "Ready... service at port " 
      << sourcePort << std::endl;
    while (!stop())
    {
      struct   sockaddr_in pin;
      int source = acceptClientSocket(server, pin);
      if(source < 0) continue;
      // put handler on the heap so we can delete this later...
      SocketHandler * linkage = new SocketHandler(*this, source);
      thpool.execute(linkage);
    }
    thrd.join();
    CloseConnection(server);  
    std::cout << "Shutting down network service " 
      << serviceId << " at port " << sourcePort 
      << std::endl; 
  }
};
void SocketHandler::operator()() 
{
  try 
  {
    ns_.ServiceHandler(client_);
  } catch (...) {}
  delete this;
}
#endif
