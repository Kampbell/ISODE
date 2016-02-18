/*
 * ElementForCpp.h
 *
 *  Created on: 2 f�vr. 2016
 *      Author: FrancisANDRE
 */

#ifndef ELEMENTFORCPP_H_
#define ELEMENTFORCPP_H_

#include <algorithm>
using std::replace;

#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class ElementForCpp : public virtual MODEL::Element {
				private:
					string _cppname;

				public:
					ElementForCpp(const string& name, int lineno = 0) :
						MODEL::Element(name, lineno) {
						_cppname = name;
						replace(_cppname.begin(), _cppname.end(), '-', '_');
					}
					virtual ~ElementForCpp() {
					}
				protected:
					const string&		  cppname() const { return _cppname; }
				};

			}
		}
	}
}

#endif
