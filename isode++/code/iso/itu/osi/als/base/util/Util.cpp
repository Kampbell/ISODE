/*
 * Util.cpp
 *
 *  Created on: 27 janv. 2016
 *      Author: FrancisANDRE
 */

#include <algorithm>
#include <stdexcept>

#include "Poco/ByteOrder.h"
using Poco::ByteOrder;

#include "Util.h"

using namespace std;

namespace ALS {
	namespace BASE {
		namespace UTIL {

			static const char* const lut = "0123456789ABCDEF";

			string Util::char_to_hex(char input) {
				string output;
				output.push_back(lut[input >> 4]);
				output.push_back(lut[input & 0x0F]);
				return output;
			}
			string Util::char_to_hex(unsigned char input) {
				string output;
				output.push_back(lut[input >> 4]);
				output.push_back(lut[input & 0x0F]);
				return output;
			}
			string Util::short_to_hex(short input) {
				string output;
				union {
					short	bigendian;
					char	bytes[sizeof(short)];
				};
				bigendian = ByteOrder::toNetwork(input);
				output.push_back(lut[bytes[0] >> 4]);
				output.push_back(lut[bytes[0] & 0x0F]);
				output.push_back(lut[bytes[1] >> 4]);
				output.push_back(lut[bytes[1] & 0x0F]);
				return output;
			}
			string Util::short_to_hex(unsigned short input) {
				string output;
				union {
					unsigned short	bigendian;
					char			bytes[sizeof(short)];
				};
				bigendian = ByteOrder::toNetwork(input);
				output.push_back(lut[bytes[0] >> 4]);
				output.push_back(lut[bytes[0] & 0x0F]);
				output.push_back(lut[bytes[1] >> 4]);
				output.push_back(lut[bytes[1] & 0x0F]);
				return output;
			}
			string Util::string_to_hex(const string& input)
			{
				size_t len = input.length();

				string output;
				output.reserve(2 * len);
				for (size_t i = 0; i < len; ++i)
				{
					const unsigned char c = input[i];
					output.push_back(lut[c >> 4]);
					output.push_back(lut[c & 0x0F]);
				}
				return output;
			}

			string Util::hex_to_string(const string& input)
			{
				size_t len = input.length();
				if (len & 1) throw invalid_argument("odd length");

				string output;
				output.reserve(len / 2);
				for (size_t i = 0; i < len; i += 2)
				{
					char a = input[i];
					const char* p = lower_bound(lut, lut + 16, a);
					if (*p != a) throw invalid_argument("not a hex digit");

					char b = input[i + 1];
					const char* q = lower_bound(lut, lut + 16, b);
					if (*q != b) throw invalid_argument("not a hex digit");

					output.push_back(((p - lut) << 4) | (q - lut));
				}
				return output;
			}
			const string Util::at(const char* file, int line) {
				return string("at ") + string(file) + string(", line ") + std::to_string(line);
			}

		}
	}
}
