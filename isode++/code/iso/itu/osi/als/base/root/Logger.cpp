/*
 * Logger.cpp
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#include <vector>
using std::vector;

#include "als/base/root/Logger.h"

namespace ALS {
namespace BASE {
namespace ROOT {

const string Logger::REQUEST = ">>>";
const string Logger::RESPONSE = REQUEST;
const string Logger::INDICATION = "<<<";
const string Logger::CONFIRMATION = INDICATION;
const string Logger::prefix = "%s %-30s: ";

void Logger::log(const Message& msg){
	tl_logger.log(msg);
}
void Logger::log(const Exception& exc){
	tl_logger.log(exc);
}

void Logger::log(const Exception& exc, const char* file, int line){
	tl_logger.log(exc, file, line);
}
void Logger::fatal(const std::string& msg){
	tl_logger.fatal(msg);
}
void Logger::fatal(const std::string& msg, const char* file, int line){
	tl_logger.fatal(msg, file, line);
}
#define FORMAT1(level,a)	tl_logger.level(fmt, a)
#define FORMAT2(level,a,b)	tl_logger.level(fmt, a, b)
#define FORMAT3(level,a,b,c)	tl_logger.level(fmt, a, b, c)
#define FORMAT4(level,a,b,c,d)	tl_logger.level(fmt, a, b, c, d)
#define FORMAT5(level,a,b,c,d,e)	tl_logger.level(fmt, a, b, c, d, e)
#define FORMAT6(level,a,b,c,d,e,f)	tl_logger.level(fmt, a, b, c, d, e, f)
#define FORMAT7(level,a,b,c,d,e,f,g)	tl_logger.level(fmt, a, b, c, d, e, f, g)
#define FORMAT8(level,a,b,c,d,e,f,g,h)	tl_logger.level(fmt, a, b, c, d, e, f, g, h)
#define FORMAT9(level,a,b,c,d,e,f,g,h,i)	tl_logger.level(fmt, a, b, c, d, e, f, g, h, i)
#define FORMAT10(level,a,b,c,d,e,f,g,h,i,j)	tl_logger.level(fmt, a, b, c, d, e, f, g, h, i, j)

void Logger::fatal(const std::string& fmt, const Any& value1){
	FORMAT1(fatal, value1);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(fatal, value1, value2);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(fatal, value1, value2, value3);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(fatal, value1, value2, value3, value4);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(fatal, value1, value2, value3, value4, value5);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(fatal, value1, value2, value3, value4, value5, value6);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(fatal, value1, value2, value3, value4, value5, value6);
}
void Logger::fatal(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(fatal, value1, value2, value3, value4, value5, value6);
}

void Logger::critical(const std::string& msg){
	tl_logger.critical(msg);
}
void Logger::critical(const std::string& msg, const char* file, int line){
	tl_logger.critical(msg, file, line);
}
void Logger::critical(const std::string& fmt, const Any& value1){
	FORMAT1(critical, value1);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(critical, value1, value2);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(critical, value1, value2, value3);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(critical, value1, value2, value3, value4);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(critical, value1, value2, value3, value4, value5);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(critical, value1, value2, value3, value4, value5, value6);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(critical, value1, value2, value3, value4, value5, value6);
}
void Logger::critical(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(critical, value1, value2, value3, value4, value5, value6);
}

void Logger::error(const std::string& msg){
	tl_logger.error(msg);
}
void Logger::error(const std::string& msg, const char* file, int line){
	tl_logger.error(msg, file, line);
}
void Logger::error(const std::string& fmt, const Any& value1){
	FORMAT1(error, value1);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(error, value1, value2);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(error, value1, value2, value3);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(error, value1, value2, value3, value4);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(error, value1, value2, value3, value4, value5);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(error, value1, value2, value3, value4, value5, value6);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(error, value1, value2, value3, value4, value5, value6);
}
void Logger::error(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(error, value1, value2, value3, value4, value5, value6);
}

void Logger::warning(const std::string& msg){
	tl_logger.warning(msg);
}
void Logger::warning(const std::string& msg, const char* file, int line){
	tl_logger.warning(msg, file, line);
}
void Logger::warning(const std::string& fmt, const Any& value1){
	FORMAT1(warning, value1);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(warning, value1, value2);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(warning, value1, value2, value3);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(warning, value1, value2, value3, value4);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(warning, value1, value2, value3, value4, value5);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(warning, value1, value2, value3, value4, value5, value6);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(warning, value1, value2, value3, value4, value5, value6);
}
void Logger::warning(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(warning, value1, value2, value3, value4, value5, value6);
}

void Logger::notice(const std::string& msg){
	tl_logger.notice(msg);
}
void Logger::notice(const std::string& msg, const char* file, int line){
	tl_logger.notice(msg, file, line);
}
void Logger::notice(const std::string& fmt, const Any& value1){
	FORMAT1(notice, value1);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(notice, value1, value2);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(notice, value1, value2, value3);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(notice, value1, value2, value3, value4);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(notice, value1, value2, value3, value4, value5);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(notice, value1, value2, value3, value4, value5, value6);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(notice, value1, value2, value3, value4, value5, value6);
}
void Logger::notice(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(notice, value1, value2, value3, value4, value5, value6);
}

void Logger::information(const std::string& msg){
	tl_logger.information(msg);
}
void Logger::information(const std::string& msg, const char* file, int line){
	tl_logger.information(msg, file, line);
}
void Logger::information(const std::string& fmt, const Any& value1){
	FORMAT1(information, value1);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(information, value1, value2);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(information, value1, value2, value3);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(information, value1, value2, value3, value4);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(information, value1, value2, value3, value4, value5);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(information, value1, value2, value3, value4, value5, value6);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(information, value1, value2, value3, value4, value5, value6);
}
void Logger::information(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(information, value1, value2, value3, value4, value5, value6);
}

void Logger::debug(const std::string& msg){
	tl_logger.debug(msg);
}
void Logger::debug(const std::string& msg, const char* file, int line){
	tl_logger.debug(msg, file, line);
}
void Logger::debug(const std::string& fmt, const Any& value1){
	FORMAT1(debug, value1);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(debug, value1, value2);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(debug, value1, value2, value3);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(debug, value1, value2, value3, value4);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(debug, value1, value2, value3, value4, value5);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(debug, value1, value2, value3, value4, value5, value6);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(debug, value1, value2, value3, value4, value5, value6);
}
void Logger::debug(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(debug, value1, value2, value3, value4, value5, value6);
}

void Logger::trace(const std::string& msg){
	tl_logger.trace(msg);
}
void Logger::trace(const std::string& msg, const char* file, int line){
	tl_logger.trace(msg, file, line);
}
void Logger::trace(const std::string& fmt, const Any& value1){
	FORMAT1(trace, value1);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2){
	FORMAT2(trace, value1, value2);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3){
	FORMAT3(trace, value1, value2, value3);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4){
	FORMAT4(trace, value1, value2, value3, value4);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5){
	FORMAT5(trace, value1, value2, value3, value4, value5);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6){
	FORMAT6(trace, value1, value2, value3, value4, value5, value6);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7){
	FORMAT6(trace, value1, value2, value3, value4, value5, value6);
}
void Logger::trace(const std::string& fmt, const Any& value1, const Any& value2, const Any& value3, const Any& value4, const Any& value5, const Any& value6, const Any& value7, const Any& value8){
	FORMAT6(trace, value1, value2, value3, value4, value5, value6);
}

void Logger::dump(const std::string& msg, const void* buffer, std::size_t length, Message::Priority prio){
	tl_logger.dump(msg, buffer, length, prio);
}

}
}
}
