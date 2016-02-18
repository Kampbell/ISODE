#ifndef ALS_SSAP_TOKEN_h
#define ALS_SSAP_TOKEN_h

#include "Poco/ByteOrder.h"
using Poco::ByteOrder;

namespace ALS {
	namespace SSAP {
			const string RELEASE_LITERAL = "release";
			const string MAJOR_LITERAL = "majorsync";
			const string MINOR_LITERAL = "minorsync";
			const string DATA_LITERAL = "data";

			/*
			8.3.1.11 The Token Setting Item PV field, if present, shall indicate the initial position of the tokens. The bits of the
			Token Setting Item PV field are defined as bit pairs:
				a) bits 8, 7: release token;
				b) bits 6, 5: major/activity token;
				c) bits 4, 3: synchronize-minor token;
				d) bits 2, 1: data token.
			The encoding for each bit pair shall be:
				e) 00: initiator’s side;
				f) 01: responder’s side;
				g) 10: called SS user’s choice;
				h) 11: reserved.
			*/
			class Token {
				/** 0x00 TOKEN INITIATOR's SIDE. */
			protected:
				static const byte		INITIATOR_VALUE					= 0x00;	// initiator's side

				/** 0x01 TOKEN RESPONDER's SIDE. */
				static const byte		RESPONDER_VALUE					= 0x01;	// responder's side

				/** 0x02 CALLED SS User's CHOICE. */
				static const byte		CALLED_VALUE					= 0x02;	// called SS-user's choice

				/** 0x03 RESERVED. */
				static const byte		RESERVED_VALUE					= 0x03;	// reserved

				/** 0x03 TOKEN CHOICE MASK. */
				static const byte		CHOICE_MASK						= 0x03;

				/** 6 RELEASE TOKEN SHIFT. */
				static const int		RELEASE_SHIFT					= 6;	// release token

				/** 4 MAJOR/ACTIVITY TOKEN SHIFT. */
				static const int		MAJOR_SHIFT						= 4;	// major/activity token

				/** 4 ACTIVITY TOKEN SHIFT. */
				static const int		ACTIVITY_SHIFT					= MAJOR_SHIFT;

				/** 2 MINOR SYNC TOKEN SHIFT. */
				static const int		MINOR_SHIFT						= 2;	// synchronize-minor token

				/** 0 DATA TOKEN SHIFT . */
				static const int		DATA_SHIFT						= 0;	// data token

				/** The Constant RELEASE_TOKEN_FOR_INITIATOR. */
				static const byte		RELEASE_TOKEN_FOR_INITIATOR		= INITIATOR_VALUE << RELEASE_SHIFT;

				/** The Constant RELEASE_TOKEN_FOR_RESPONDER. */
				static const byte		RELEASE_TOKEN_FOR_RESPONDER		= RESPONDER_VALUE << RELEASE_SHIFT;

				/** The Constant RELEASE_TOKEN_AS_CALLED_CHOICE. */
				static const byte		RELEASE_TOKEN_AS_CALLED_CHOICE	= CALLED_VALUE << RELEASE_SHIFT;

				/** The Constant MAJOR_TOKEN_FOR_INITIATOR. */
				static const byte		MAJOR_TOKEN_FOR_INITIATOR		= INITIATOR_VALUE << MAJOR_SHIFT;

				/** The Constant MAJOR_TOKEN_FOR_RESPONDER. */
				static const byte		MAJOR_TOKEN_FOR_RESPONDER		= RESPONDER_VALUE << MAJOR_SHIFT;

				/** The Constant MAJOR_TOKEN_AS_CALLED_CHOICE. */
				static const byte		MAJOR_TOKEN_AS_CALLED_CHOICE	= CALLED_VALUE << MAJOR_SHIFT;

				/** The Constant MINOR_TOKEN_FOR_INITIATOR. */
				static const byte		MINOR_TOKEN_FOR_INITIATOR		= INITIATOR_VALUE << MINOR_SHIFT;

				/** The Constant MINOR_TOKEN_FOR_RESPONDER. */
				static const byte		MINOR_TOKEN_FOR_RESPONDER		= RESPONDER_VALUE << MINOR_SHIFT;

				/** The Constant MINOR_TOKEN_AS_CALLED_CHOICE. */
				static const byte		MINOR_TOKEN_AS_CALLED_CHOICE	= CALLED_VALUE << MINOR_SHIFT;

				/** The Constant DATA_TOKEN_FOR_INITIATOR. */
				static const byte		DATA_TOKEN_FOR_INITIATOR		= INITIATOR_VALUE << DATA_SHIFT;

				/** The Constant DATA_TOKEN_FOR_RESPONDER. */
				static const byte		DATA_TOKEN_FOR_RESPONDER		= RESPONDER_VALUE << DATA_SHIFT;

				/** The Constant DATA_TOKEN_AS_CALLED_CHOICE. */
				static const byte		DATA_TOKEN_AS_CALLED_CHOICE		= CALLED_VALUE << DATA_SHIFT;
				//
			public:
				/** 01000000 RELEASE TOKEN. */
				static const byte		RELEASE_TOKEN					= (0x01 << RELEASE_SHIFT);

				/** 00010000 MAJOR/ACTIVITY TOKEN. */
				static const byte		MAJOR_TOKEN						= (0x01 << MAJOR_SHIFT);

				/** 00010000 ACTIVITY TOKEN. */
				static const byte		ACTIVITY_TOKEN					= (0x01 << ACTIVITY_SHIFT);

				/** 00000100 MINOR SYNC TOKEN. */
				static const byte		MINOR_TOKEN						= (0x01 << MINOR_SHIFT);

				/** 00000001 DATA TOKEN. */
				static const byte		DATA_TOKEN						= (0x01 << DATA_SHIFT);
			protected:
				/** 512 PLEASE TOKEN only MAXIMUM DATA SIZE. */
				static const int		ST_SIZE							= 512;

				static int clearReleaseToken(int settings) {
					settings &= ~(CHOICE_MASK << RELEASE_SHIFT);
					return settings;
				}

				static int clearMajorToken(int settings) {
					settings &= ~(CHOICE_MASK << MAJOR_SHIFT);
					return settings;
				}

				static int clearActivityToken(int settings) {
					settings &= ~(CHOICE_MASK << ACTIVITY_SHIFT);
					return settings;
				}

				static int clearMinorToken(int settings) {
					settings &= ~(CHOICE_MASK << MINOR_SHIFT);
					return settings;
				}

				static int clearDataToken(int settings) {
					settings &= ~(CHOICE_MASK << DATA_SHIFT);
					return settings;
				}

				static int addCalledChoiceRelease(int settings) {
					settings |= CALLED_VALUE << RELEASE_SHIFT;
					return settings;
				}

				static int addCalledChoiceMajor(int settings) {
					settings |= CALLED_VALUE << MAJOR_SHIFT;
					return settings;
				}

				static int addCalledChoiceActivity(int settings) {
					settings |= CALLED_VALUE << ACTIVITY_SHIFT;
					return settings;
				}

				static int addCalledChoiceMinor(int settings) {
					settings |= CALLED_VALUE << MINOR_SHIFT;
					return settings;
				}

				static int addCalledChoiceData(int settings) {
					settings |= CALLED_VALUE << DATA_SHIFT;
					return settings;
				}

				static int addInitiatorRelease(int settings) {
					settings |= INITIATOR_VALUE << RELEASE_SHIFT;
					return settings;
				}

				static int addInitiatorMajor(int settings) {
					settings |= INITIATOR_VALUE << MAJOR_SHIFT;
					return settings;
				}

				static int addInitiatorActivity(int settings) {
					settings |= INITIATOR_VALUE << ACTIVITY_SHIFT;
					return settings;
				}

				static int addInitiatorMinor(int settings) {
					settings |= INITIATOR_VALUE << MINOR_SHIFT;
					return settings;
				}

				static int addInitiatorData(int settings) {
					settings |= INITIATOR_VALUE << DATA_SHIFT;
					return settings;
				}

				static int addResponderRelease(int settings) {
					settings |= RESPONDER_VALUE << RELEASE_SHIFT;
					return settings;
				}

				static int addResponderMajor(int settings) {
					settings |= RESPONDER_VALUE << MAJOR_SHIFT;
					return settings;
				}

				static int addResponderActivity(int settings) {
					settings |= RESPONDER_VALUE << ACTIVITY_SHIFT;
					return settings;
				}

				static int addResponderMinor(int settings) {
					settings |= RESPONDER_VALUE << MINOR_SHIFT;
					return settings;
				}

				static int addResponderData(int settings) {
					settings |= RESPONDER_VALUE << DATA_SHIFT;
					return settings;
				}

				static int selectReleaseToken(int setting) {
					return setting & (CHOICE_MASK << RELEASE_SHIFT);
				}

				static int selectMajorToken(int setting) {
					return setting & (CHOICE_MASK << MAJOR_SHIFT);
				}

				static int selectActivityToken(int setting) {
					return setting & (CHOICE_MASK << ACTIVITY_SHIFT);
				}

				static int selectMinorToken(int setting) {
					return setting & (CHOICE_MASK << MINOR_SHIFT);
				}

				static int selectDataToken(int setting) {
					return setting & (CHOICE_MASK << DATA_SHIFT);
				}

				private:
				static bool owns(int owned, int tokens) {
					return (owned & tokens) != 0;
				}

				static int add(int owned, int tokens) {
					owned |= tokens;
					return owned;
				}

				static int rem(int owned, int tokens) {
					owned &= ~tokens;
					return owned;
				}

				public:
				static bool hasReleaseToken(int tokens) {
					return owns(tokens, RELEASE_TOKEN);
				}

				static int addReleaseToken(int tokens) {
					return add(tokens, RELEASE_TOKEN);
				}

				static int remReleaseToken(int tokens) {
					return rem(tokens, RELEASE_TOKEN);
				}

				static bool hasMajorToken(int tokens) {
					return owns(tokens, MAJOR_TOKEN);
				}

				static int addMajorToken(int tokens) {
					return add(tokens, MAJOR_TOKEN);
				}

				static int remMajorToken(int tokens) {
					return rem(tokens, MAJOR_TOKEN);
				}

				static bool hasActivityToken(int tokens) {
					return owns(tokens, ACTIVITY_TOKEN);
				}

				static int addActivityToken(int tokens) {
					return add(tokens, ACTIVITY_TOKEN);
				}

				static int remActivityToken(int tokens) {
					return rem(tokens, ACTIVITY_TOKEN);
				}

				static bool hasMinorToken(int tokens) {
					return owns(tokens, MINOR_TOKEN);
				}

				static int addMinorToken(int tokens) {
					return add(tokens, MINOR_TOKEN);
				}

				static int remMinorToken(int tokens) {
					return rem(tokens, MINOR_TOKEN);
				}

				static bool hasDataToken(int owned) {
					return owns(owned, DATA_TOKEN);
				}

				static int addDataToken(int tokens) {
					return add(tokens, DATA_TOKEN);
				}

				static int remDataToken(int tokens) {
					return rem(tokens, DATA_TOKEN);
				}

				static string initiator(int tokens) {
					string sb;
					if ((getRelease(tokens) & INITIATOR_VALUE) == INITIATOR_VALUE) {
						sb.append("RELEASE");
					}
					if ((getMajor(tokens) & INITIATOR_VALUE) == INITIATOR_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MAJORSYNC");
					}
					if ((getMinor(tokens) & INITIATOR_VALUE) == INITIATOR_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MINORSYNC");
					}
					if ((getData(tokens) & INITIATOR_VALUE) == INITIATOR_VALUE) {
						if (!sb.empty())
						sb.append(",");
							sb.append("DATA");
					}
					return sb;
				}

				static string responder(int tokens) {
					string sb;
					if ((getRelease(tokens) & RESPONDER_VALUE) == RESPONDER_VALUE) {
						sb.append("RELEASE");
					}
					if ((getMajor(tokens) & RESPONDER_VALUE) == RESPONDER_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MAJORSYNC");
					}
					if ((getMinor(tokens) & RESPONDER_VALUE) == RESPONDER_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MINORSYNC");
					}
					if ((getData(tokens) & RESPONDER_VALUE) == RESPONDER_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("DATA");
					}
					if (sb.length() == 0) {
						sb.append("<none>");
					}
					return sb;
				}

				static string callerChoice(int tokens) {
					string sb;
					if ((getRelease(tokens) & CALLED_VALUE) == CALLED_VALUE) {
						sb.append("RELEASE");
					}
					if ((getMajor(tokens) & CALLED_VALUE) == CALLED_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MAJORSYNC");
					}
					if ((getMinor(tokens) & CALLED_VALUE) == CALLED_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MINORSYNC");
					}
					if ((getData(tokens) & CALLED_VALUE) == CALLED_VALUE) {
						if (!sb.empty())
							sb.append(",");
						sb.append("DATA");
					}
					if (sb.length() == 0) {
						sb.append("<none>");
					}
					return sb;
				}

				static string token(int tokens) {
					string sb;
					if (hasRelease(tokens)) {
						sb.append("RELEASE");
					}
					if (hasMajor(tokens)) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MAJORSYNC");
					}
					if (hasMinor(tokens)) {
						if (!sb.empty())
							sb.append(",");
						sb.append("MINORSYNC");
					}
					if (hasData(tokens)) {
						if (!sb.empty())
							sb.append(",");
						sb.append("DATA");
					}
					if (sb.length() == 0) {
						sb.append("<none>");
					}
					return sb;
				}

				private:
				static int getToken(int token, int shift) {
					int i = (token >> shift) & CHOICE_MASK;
					return i;
				}

				static int getRelease(int token) {
					return getToken(token, RELEASE_SHIFT);
				}

				static int getMajor(int token) {
					return getToken(token, MAJOR_SHIFT);
				}

				static int getMinor(int token) {
					return getToken(token, MINOR_SHIFT);
				}

				static int getData(int token) {
					return getToken(token, DATA_SHIFT);
				}

				static bool hasRelease(int tokens) {
					return (getRelease(tokens) & 0x01) != 0;
				}

				static bool hasMajor(int tokens) {
					return (getMajor(tokens) & 0x01) != 0;
				}

				static bool hasMinor(int tokens) {
					return (getMinor(tokens) & 0x01) != 0;
				}

				static bool hasData(int tokens) {
					return (getData(tokens) & 0x01) != 0;
				}

			};
			enum Tokens {
				mi = Token::MINOR_TOKEN,	// the synchronize - minor token;
				ma = Token::MAJOR_TOKEN,	// the major / activity token;
				tr = Token::RELEASE_TOKEN,	// the release token;
				dk = Token::DATA_TOKEN,	// the data token.
			};
	}
}
#endif
