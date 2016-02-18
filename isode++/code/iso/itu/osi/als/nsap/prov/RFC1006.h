/*
 * RFC1006.h
 *
 *  Created on: 27 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_PROV_RFC1006_H_
#define ALS_NSAP_PROV_RFC1006_H_
/*
//
// Standard exception classes
//
POCO_DECLARE_EXCEPTION(Foundation_API, LogicException, Exception)
POCO_DECLARE_EXCEPTION(Foundation_API, AssertionViolationException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, NullPointerException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, NullValueException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, BugcheckException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, InvalidArgumentException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, NotImplementedException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, RangeException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, IllegalStateException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, InvalidAccessException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, SignalException, LogicException)
POCO_DECLARE_EXCEPTION(Foundation_API, UnhandledException, LogicException)

POCO_DECLARE_EXCEPTION(Foundation_API, RuntimeException, Exception)
POCO_DECLARE_EXCEPTION(Foundation_API, NotFoundException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, ExistsException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, TimeoutException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, SystemException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, RegularExpressionException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, LibraryLoadException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, LibraryAlreadyLoadedException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, NoThreadAvailableException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, PropertyNotSupportedException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, PoolOverflowException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, NoPermissionException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, OutOfMemoryException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, DataException, RuntimeException)

POCO_DECLARE_EXCEPTION(Foundation_API, DataFormatException, DataException)
POCO_DECLARE_EXCEPTION(Foundation_API, SyntaxException, DataException)
POCO_DECLARE_EXCEPTION(Foundation_API, CircularReferenceException, DataException)
POCO_DECLARE_EXCEPTION(Foundation_API, PathSyntaxException, SyntaxException)
POCO_DECLARE_EXCEPTION(Foundation_API, IOException, RuntimeException)
POCO_DECLARE_EXCEPTION(Foundation_API, ProtocolException, IOException)
POCO_DECLARE_EXCEPTION(Foundation_API, FileException, IOException)
POCO_DECLARE_EXCEPTION(Foundation_API, FileExistsException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, FileNotFoundException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, PathNotFoundException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, FileReadOnlyException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, FileAccessDeniedException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, CreateFileException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, OpenFileException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, WriteFileException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, ReadFileException, FileException)
POCO_DECLARE_EXCEPTION(Foundation_API, UnknownURISchemeException, RuntimeException)

POCO_DECLARE_EXCEPTION(Foundation_API, ApplicationException, Exception)
POCO_DECLARE_EXCEPTION(Foundation_API, BadCastException, RuntimeException)
*/
/*
POCO_DECLARE_EXCEPTION(Net_API, NetException, Poco::IOException)
POCO_DECLARE_EXCEPTION(Net_API, InvalidAddressException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, InvalidSocketException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, ServiceNotFoundException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, ConnectionAbortedException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, ConnectionResetException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, ConnectionRefusedException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, DNSException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, HostNotFoundException, DNSException)
POCO_DECLARE_EXCEPTION(Net_API, NoAddressFoundException, DNSException)
POCO_DECLARE_EXCEPTION(Net_API, InterfaceNotFoundException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, NoMessageException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, MessageException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, MultipartException, MessageException)
POCO_DECLARE_EXCEPTION(Net_API, HTTPException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, NotAuthenticatedException, HTTPException)
POCO_DECLARE_EXCEPTION(Net_API, UnsupportedRedirectException, HTTPException)
POCO_DECLARE_EXCEPTION(Net_API, FTPException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, SMTPException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, POP3Exception, NetException)
POCO_DECLARE_EXCEPTION(Net_API, ICMPException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, NTPException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, HTMLFormException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, WebSocketException, NetException)
POCO_DECLARE_EXCEPTION(Net_API, UnsupportedFamilyException, NetException)
*/
#include "Poco/Net/NetException.h"
#include "Poco/Net/StreamSocket.h"
#include "als/nsap/nsap.h"
using Poco::Net::StreamSocket;

namespace ALS { namespace BASE { namespace UTIL {
	class NetworkBuffer;
}
}
}
using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
	namespace NSAP {
		namespace PROV {
			POCO_DECLARE_EXCEPTION(NSAP_API, ProtocolException, Poco::Net::NetException)

			class NSAP_API RFC1006 {		// See RFC1006
			private:
				static const byte		SIZEOF_HEADER = 4;
				static const byte		TPKT_VERSION = 3;
				static const byte		TPKT_MBZ = 0;
				static const int		TPKT_MINLEN = 7;

			public:
				static const int		TPKT_MAXLEN = 0xFFFF;
				static const int		MAX1006 = 2048;
				static const int		TPDU_MAXLEN = TPKT_MAXLEN - SIZEOF_HEADER;


			private:
				byte			version;
				byte			mbz;
				unsigned short	length;

				StreamSocket 	socket;
				int				offset;
				NetworkBuffer*			buffer;

				void reset()	{ version = 0; mbz = 0; length = 0; offset = 0; }

			public:
				RFC1006(StreamSocket& socket);
				virtual ~RFC1006();

				int recv(NetworkBuffer*& buffer);
				int	send(const NetworkBuffer* buffer);
				int	send(int cc, const byte* data);
			};
		}
	}
}
#endif
