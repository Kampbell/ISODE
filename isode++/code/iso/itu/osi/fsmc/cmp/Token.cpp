/*
 * Token.cpp
 *
 *  Created on: 3 ao�t 2014
 *      Author: FrancisANDRE
 */

#include "Poco/Ascii.h"

#include "Poco/StreamTokenizer.h"
#include "Poco/Exception.h"
using Poco::StreamTokenizer;
using Poco::Token;
using Poco::InvalidToken;
using Poco::EOFToken;
using Poco::WhitespaceToken;
using Poco::Ascii;
using Poco::SyntaxException;

#include "fsmc/cmp/Token.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {

			Token::Token()
			{
			}


			Token::~Token()
			{
			}


			void Token::syntaxError(const std::string& expected, const std::string& actual)
			{
				std::string msg("expected: ");
				msg.append(expected);
				msg.append(", got: ");
				msg.append(actual);
				throw SyntaxException(msg);
			}

		}
	}
}
