/*
 * FSM.cpp
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Poco/Format.h"
using Poco::format;

#include "fsmc/cmp/Keyword.h"
#include "fsmc/smc/FSM.h"
using ALS::SMC::PARSER::Keyword;

namespace ALS {
	namespace SMC {
		namespace MODEL {
			void FSM::print(Print& print) const {
				print(format("%s\t%s", string(Keyword::asString(Keyword::START)), startState()));
				print(format("%s\t%s", string(Keyword::asString(Keyword::FSMFILE)), fsmfile()));
				print(format("%s\t%s", string(Keyword::asString(Keyword::FSMCLASS)), fsmclass()));
				print(format("%s\t%s", string(Keyword::asString(Keyword::CLASS)), klass()));
//				print(format("%s\t%s", string(Keyword::asString(Keyword::DECLARE)), declare()));
//				print(format("%s\t%s", string(Keyword::asString(Keyword::ACCESS)), access()));
				print(format("%s\t%s", string(Keyword::asString(Keyword::HEADER)), header()));
				print(format("%s\t%s", string(Keyword::asString(Keyword::PACKAGE)), packages()[0]));

				for (const auto& map : maps()) {
				print(format("%s\t%s", string(Keyword::asString(Keyword::MAP)), map->Element::name()));
					map->print(print);
				}
			}
		}
	}
}
