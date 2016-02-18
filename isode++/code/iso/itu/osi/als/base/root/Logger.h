/*
 * Logger.h
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_ROOT_LOGGER_H_
#define ALS_BASE_ROOT_LOGGER_H_

#include <string>
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/Format.h"
#include "als/base/base.h"

using std::string;
using Poco::Message;
using Poco::Exception;
using Poco::Any;

namespace ALS {
namespace BASE {
namespace ROOT {

class BASE_API Logger  {
protected:
//	static const int MAX_LITERAL_LENGTH = 30;
	static const string REQUEST;
	static const string RESPONSE;
	static const string INDICATION;
	static const string CONFIRMATION;
	static const string prefix;

private:
	Poco::Logger&	tl_logger;

protected:
	Logger() = delete;
	Logger(const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
	Logger(const string& name) :
		tl_logger(Poco::Logger::get(name)){
	}
	virtual ~Logger() {
	}
public:
	int getLevel() const { return tl_logger.getLevel(); }

	void log(const Message& msg);
	void log(const Exception& exc);
	void log(const Exception& exc, const char* file, int line);

	void fatal(const std::string& msg);
	void fatal(const std::string& msg, const char* file, int line);
	void fatal(const std::string& fmt, const Any& value1);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void critical(const std::string& msg);
	void critical(const std::string& msg, const char* file, int line);
	void critical(const std::string& fmt, const Any& value1);
	void critical(const std::string& fmt, const Any& value1, const Any& value2);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void error(const std::string& msg);
	void error(const std::string& msg, const char* file, int line);
	void error(const std::string& fmt, const Any& value1);
	void error(const std::string& fmt, const Any& value1, const Any& value2);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void warning(const std::string& msg);
	void warning(const std::string& msg, const char* file, int line);
	void warning(const std::string& fmt, const Any& value1);
	void warning(const std::string& fmt, const Any& value1, const Any& value2);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void notice(const std::string& msg);
	void notice(const std::string& msg, const char* file, int line);
	void notice(const std::string& fmt, const Any& value1);
	void notice(const std::string& fmt, const Any& value1, const Any& value2);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void information(const std::string& msg);
	void information(const std::string& msg, const char* file, int line);
	void information(const std::string& fmt, const Any& value1);
	void information(const std::string& fmt, const Any& value1, const Any& value2);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void debug(const std::string& msg);
	void debug(const std::string& msg, const char* file, int line);
	void debug(const std::string& fmt, const Any& value1);
	void debug(const std::string& fmt, const Any& value1, const Any& value2);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void trace(const std::string& msg);
	void trace(const std::string& msg, const char* file, int line);
	void trace(const std::string& fmt, const Any& value1);
	void trace(const std::string& fmt, const Any& value1, const Any& value2);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7);
	void trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8);

	void dump(const std::string& msg, const void* buffer, std::size_t length, Message::Priority prio = Message::PRIO_DEBUG);

	static string expand(const char* literal);

};

}
}
}

#endif
