/*
 * Tokenizer.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#include "Poco/Token.h"
using Poco::WhitespaceToken;
#include "fsmc/cmp/Tokenizer.h"
#include "fsmc/cmp/Identifier.h"
#include "fsmc/cmp/Number.h"
#include "fsmc/cmp/Keyword.h"
#include "fsmc/cmp/Comment.h"
#include "fsmc/cmp/Character.h"
#include "fsmc/cmp/Operator.h"
#include "fsmc/cmp/String.h"


namespace ALS { namespace SMC {
namespace PARSER {
Tokenizer::Tokenizer(std::istream& istr):
	StreamTokenizer(istr)	
{
	addToken(new WhitespaceToken());
	addToken(new Comment());
	addToken(new Identifier());
	addToken(new Number());
	addToken(new Keyword());
	addToken(new Operator());
	addToken(new Character());
	addToken(new String());

}


Tokenizer::~Tokenizer()
{
}

}
}
}
