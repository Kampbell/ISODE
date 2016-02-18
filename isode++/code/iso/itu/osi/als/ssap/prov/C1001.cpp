#include <wincrypt.h>
namespace ALS {
	namespace SSAP {
		namespace PROV {
			class SyncOption;
		}
		using PROV::SyncOption;
		namespace SERV {

			class SynchronizeRequest  {
			public:
				virtual ~SynchronizeRequest() {}
				virtual int SSyncMinorRequest(const SyncOption& type) = 0;
			};

		}
	}
}

namespace ALS {
	namespace SSAP {
		namespace PROV {
			enum SyncOption {
				NOCONFIRM = 0,	
			};
		}
	}
}


