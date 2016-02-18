/*
 * SourceDelimiterToken.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_TOKENIZER_H_
#define ALS_SMC_PARSER_TOKENIZER_H_
#include "Poco/StreamTokenizer.h"
using Poco::StreamTokenizer;

#include "fsmc/cmp/Token.h"

namespace ALS { namespace SMC {
namespace PARSER {

class  Tokenizer : public StreamTokenizer
{
public:
	Tokenizer(istream& istr);
	~Tokenizer();
	const Poco::Token* nextToken() { return StreamTokenizer::next(); }
};

}
}
}

#endif
