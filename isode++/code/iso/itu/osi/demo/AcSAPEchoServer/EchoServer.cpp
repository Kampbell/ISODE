#include "als/ssap/SyncOption.h"
using ALS::SSAP::SyncOption;
#include "EchoServer.h"

namespace ALS {
namespace ASAP {
EchoServer::EchoServer() {
}
EchoServer::~EchoServer() {
}

ReturnCode EchoServer::AAssociateIndication(
	const Application_context_name& 					applicationContext,
	const Application_context_name_list& 				applicationContexts,
	const AP_title&										callingAPtitle,
	const AE_qualifier&									callingAEqualifier,
	const AP_invocation_identifier&						callingAPInvocationIdentifier,
	const AE_invocation_identifier&						callingAEInvocationIdentifier,
	const AP_title&										calledAPtitle,
	const AE_qualifier&									calledAEqualifier,
	const AP_invocation_identifier&						calledAPInvocationIdentifier,
	const AE_invocation_identifier&						calledAEInvocationIdentifier,
	const ACSE_requirements& 							senderACSERequirements,
	const Mechanism_name& 								mechanism,
	const Authentication_value&							authentification,
	const Implementation_data& 							implementation,
	const PresentationAddress& 							callingPresentationAddress,
	const PresentationAddress& 							calledPresentationAddress,
	const Presentation_context_definition_list&			presentationContexts,
	const Presentation_context_definition_result_list&	presentationContextResults,
	const Default_context_name& 						defaultContext,
	int 												defaultContextResult,
	const Presentation_requirements& 					presentationRequirements,
	const User_session_requirements&					sessionRequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference,
	const QualityOfService&								qualityOfService,
	const Association_information* 						userInformation
	) {
	return DONE;
}
ReturnCode EchoServer::AReleaseConfirmation(bool affirmative, const Release_response_reason& responseReason, const Association_information* userInformation) {
	return DONE; 
}
ReturnCode EchoServer::AAbortIndication(const ABRT_source& source, const ABRT_diagnostic& diagnostic, const Association_information* userInformation) {
	return DONE; 
}
ReturnCode EchoServer::APAbortIndication(int reason, int extension, const Association_information* userInformation) {
	return DONE; 
}
ReturnCode EchoServer::AReleaseIndication(const Release_request_reason& requestReason, const Association_information* userInformation) {
	return DONE; 
}
ReturnCode EchoServer::PActivityStartIndication(const ActivityId& aid, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityResumeIndication(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldReference, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityDiscardIndication(int reason, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityDiscardConfirmation(const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityEndIndication(const SSN& ssn, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityEndConfirmation(const SSN& secondSSN, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityInterruptIndication(int reason, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PActivityInterruptConfirmation(const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PAlterContextIndication(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const Presentation_context_addition_result_list& presentationAdditionResults, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PAlterContextConfirmation(const Presentation_context_addition_result_list& presentationAdditionResults, const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PDataIndication(const User_data& userData) {
	switch(userData.get_selection()) {
		case User_data::simply_encoded_data_chosen: {
				const Simply_encoded_data* sed = userData.get_simply_encoded_data();
		}
		break;
		case User_data::fully_encoded_data_chosen: {
			const Fully_encoded_data* fed = userData.get_fully_encoded_data();
			PDV_list* pdvList =  (PDV_list*)fed->at(0);
			PDV_list::transfer_syntax_name* tsn = pdvList->get_transfer_syntax_name();
			int pci = pdvList->get_presentation_context_identifier();
			PDV_list::presentation_data_values values = pdvList->get_presentation_data_values();
			switch(values.get_selection()) {
				case PDV_list::presentation_data_values::single_ASN1_type_chosen: {
					PDV_list::presentation_data_values::single_ASN1_type* sat;
					 OssOpen open;
					OssString octets;
					sat = values.get_single_ASN1_type();
//					sat->decode();
//					sat->get_decoded(octets);
//					sat->get_decoded_data();
//					open.decode(octets);
//					open.get_decoded_data(octets);
				}
				break;
				case PDV_list::presentation_data_values::octet_aligned_chosen: {
				}
				break;
				case PDV_list::presentation_data_values::arbitrary_chosen: {
				}
				default:
					break;
			}
		}
		break;
	}
	return DONE; 
}
ReturnCode EchoServer::PExpeditedDataIndication(const User_data& userData) {
	return DONE; 
}
ReturnCode EchoServer::PTypedDataIndication(const User_data& userData) {
	return DONE; 
}
ReturnCode EchoServer::PCapabilityDataIndication(const User_data& userData) {
	return DONE; 
}
ReturnCode EchoServer::PCapabilityDataConfirmation(const User_data& userData) {
	return DONE; 
}
ReturnCode EchoServer::PPExceptionReportIndication(int reason) {
	return DONE; 
}
ReturnCode EchoServer::PUExceptionReportIndication(int reason, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PSyncMajorIndication(SSN ssn, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PSyncMajorConfirmation(const SSN& ssn, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PSyncMinorIndication(SyncOption type, const SSN& ssn, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PSyncMinorConfirmation(const SSN& ssn, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PResynchronizeIndication(SyncOption type, const SSN& ssn, byte tokens, const Presentation_context_identifier_list& presentationIdentifications, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PResynchronizeConfirmation(const SSN& ssn, byte tokens, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PTokenGiveIndication(byte tokens, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PControlGiveIndication(byte tokens, const User_data* userData) {
	return DONE; 
}
ReturnCode EchoServer::PTokenPleaseIndication(byte tokens, const User_data* userData) {
	return DONE; 
}

}}