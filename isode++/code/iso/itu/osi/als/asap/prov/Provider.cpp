/*
 * Provider.cpp
 *
 *  Created on: 18 déc. 2014
 *      Author: FrancisANDRE
 */

#include "als/asap/prov/Provider.h"
#include "als/asap/prov/Logger.h"

namespace ALS {
namespace ASAP {
namespace PROV {
ReturnCode Provider::AAssociateRequest(
	const Mode_selector&								mode,
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
	const Authentication_value& 						authentification,
	const Implementation_data& 							implementation,
	const PresentationAddress&							callingPresentationAddress,
	const PresentationAddress& 							calledPresentationAddress,
	const Presentation_context_definition_list&			presentationContexts,
	const Default_context_name& 						defaultContext,
	const Presentation_requirements& 					presentationRequirements,
	const User_session_requirements& 					sessionRequirements,
	const SSN& 											isn,
	byte 												settings,
	const Reference& 									reference,
	const QualityOfService&				 				qualityOfService,
	const Association_information* 						userInformation) {
	acb_logger->AAssociateRequest(mode, applicationContext, applicationContexts, callingAPtitle, callingAEqualifier, callingAPInvocationIdentifier, callingAEInvocationIdentifier, calledAPtitle, calledAEqualifier, calledAPInvocationIdentifier, calledAEInvocationIdentifier, senderACSERequirements, mechanism, authentification,	implementation,	callingPresentationAddress, calledPresentationAddress, presentationContexts, defaultContext, presentationRequirements,	sessionRequirements, isn, settings, reference, qualityOfService, userInformation);
	acb_fsm.A_ASCreq();
	return OK;
}
ReturnCode Provider::AAssociateResponse(
	const Associate_result&								result,
	const Associate_source_diagnostic&					diagnostic,
	const Application_context_name&						applicationContext,
	const Application_context_name_list&				applicationContexts,
	const AP_title&										respondingAPtitle,
	const AE_qualifier&									respondingAEqualifier,
	const AP_invocation_identifier&						respondingAPInvocationIdentifier,
	const AE_invocation_identifier&						respondingAEInvocationIdentifier,
	const ACSE_requirements&							senderACSERequirements,
	const Mechanism_name&								mechanism,
	const Authentication_value&							authentification,
	const PresentationAddress&							respondingPresentationAddress,
	const Presentation_context_definition_result_list&	presentationContextResults,
	int													defaultContextResult,
	const QualityOfService&								qualityOfService,
	const Presentation_requirements&					presentationRequirements,
	const User_session_requirements&					sessionRequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference,
	const Association_information*						userInformation) {
	acb_logger->AAssociateResponse(result, diagnostic, applicationContext, applicationContexts, respondingAPtitle, respondingAEqualifier, respondingAPInvocationIdentifier, respondingAEInvocationIdentifier, senderACSERequirements, mechanism, authentification, respondingPresentationAddress, presentationContextResults, defaultContextResult,	qualityOfService, presentationRequirements, sessionRequirements, isn, settings,	reference, userInformation	);
	acb_fsm.A_ASCrsp(true);
	return OK;
}
ReturnCode Provider::AReleaseRequest(
	const Release_request_reason&						requestReason,
	const Association_information*						userInformation) {
	acb_logger->AReleaseRequest(requestReason, userInformation);
	return OK;
}
ReturnCode Provider::AReleaseResponse(
	bool												result,
	const Release_response_reason&						responseReason,
	const Association_information*						userInformation) {
	acb_logger->AReleaseResponse(result, responseReason, userInformation);
	return OK;
}
ReturnCode Provider::AAbortRequest(
	const ABRT_diagnostic&								diagnostic,
	const Association_information*						userInformation) {
	acb_logger->AAbortRequest(diagnostic, userInformation);
	return OK;
}
ReturnCode Provider::PConnectIndication(
	const PresentationAddress&							callingPresentationAddress,
	const PresentationAddress&							calledPresentationAddress,
	const Presentation_context_definition_list&			presentationContexts,
	const Presentation_context_definition_result_list&	presentationContextResults,
	const Default_context_name&							defaultContext,
	const Presentation_requirements&					presentationRequirements,
	const Mode_selector&								mode,
	const User_session_requirements&					sessionRequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference, 
	const QualityOfService&								qualityOfService,
	const User_data*									userData) {
	int defaultContextResult = 0;
	int ctx = 0;
	ReturnCode rc = NOTOK;
	try {
		if (userData == nullptr) {
			return NOTOK;//FIXME aca.asaplose(ACS_PROTOCOL, nullptr, "no user-data on P-CONNECT.INDICATION");
		}

//		addState(ACB_ACS);
		acb_sversion = qualityOfService.version();
		ACSE_apdu_PDU acsePDU;
		switch(userData->get_selection()) {
			case User_data::simply_encoded_data_chosen: {
				const Simply_encoded_data* sed = userData->get_simply_encoded_data();
				const char* data = sed->get_buffer();
				int datal = sed->length();
			}
			break;

			case User_data::fully_encoded_data_chosen: {
				const Fully_encoded_data* fed = userData->get_fully_encoded_data();
				//FIXME if (fed->size() > 1) {
				//	return NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "too many user-data on P-CONNECT.INDICATION");
				//}
				const Fully_encoded_data::component* element = fed->at(0);
				const Transfer_syntax_name* tsn = element->get_transfer_syntax_name();
				ctx = element->get_presentation_context_identifier();
				//element.presentation_data_values().single_ASN1_type().resolveContent(acse);
				const PDV_list::presentation_data_values& pdvs = element->get_presentation_data_values();
				
				switch(pdvs.get_selection()) {
				case PDV_list::presentation_data_values::octet_aligned_chosen: {
					const PDV_list::presentation_data_values::octet_aligned* oa = pdvs.get_octet_aligned();
					//oa->
				}
				break;
				case PDV_list::presentation_data_values::single_ASN1_type_chosen: {
					const PDV_list::presentation_data_values::single_ASN1_type* sat = pdvs.get_single_ASN1_type();
					sat->get_decoded_data(acsePDU);
				}
				break;
				case PDV_list::presentation_data_values::arbitrary_chosen: {
				}
				break;
				default:
					poco_assert(false);
					break;
				}
			}
			break;

			case User_data::unselected:
				poco_assert(false);
			break;
			default:
				poco_assert(false);
		}

		if (acsePDU.get_data() == nullptr)
			;//FIXME

		ACSE_apdu& acse = *acsePDU.get_data();
		if (acse.get_selection() != acse.aarq_chosen) {
			return NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "PDU on " + P_CONNECT_INDICATION + " is not AARQ-apdu");
		}
		
		if (acse.get_aarq() == nullptr)
			;//FIXME
		AARQ_apdu& aarq = *acse.get_aarq();

		AARQ_apdu::application_context_name& acb_context = aarq.get_application_context_name();
		for(OssIndex no = presentationContexts.first(); no != OSS_NOINDEX; no = presentationContexts.next(no)) {
			const Presentation_context_definition_list::component*		context =	presentationContexts.at(no);
			const Presentation_context_definition_result_list::component* result = presentationContextResults.at(no);
			if (ctx == context->get_presentation_context_identifier()) {
				Abstract_syntax_name asn = context->get_abstract_syntax_name();
				if (acse_as_id != asn) {
					return NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "wrong ASN for ACSE");
				}
				if (result != accepted) {
					return NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "PCI for ACSE not accepted");
				}
				acb_acse_as_id = ctx;
//				} else
//				if (acb_roseid == DEFAULT_CONTEXT) {
//					acb_roseid = (int) context.getPresentation_context_identifier();
			}
		}

		if (acb_acse_as_id == DEFAULT_CONTEXT) {
			return NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "unable to find PCI for ACSE");
		}

		if (aarq.user_information_is_present())
			userInformation = aarq.get_user_information();

		if (aarq.called_AP_title_is_present()) {
			callingAPtitle = *aarq.get_calling_AP_title();
		}
		if (aarq.calling_AE_qualifier_is_present()) {
			callingAEqualifier = *aarq.get_calling_AE_qualifier();
		}
		if (aarq.calling_AP_invocation_identifier_is_present()) {
			callingAPInvocationIdentifier = *aarq.get_calling_AP_invocation_identifier();
		}
		if (aarq.calling_AE_invocation_identifier_is_present()) {
			callingAEInvocationIdentifier = *aarq.get_calling_AE_invocation_identifier();
		}
#if 0
		AEI callingAEI = nullptr;
		if (title != nullptr && qualifier != nullptr) {
			callingAEI = new AEI(title, apInvocationIdentifier, qualifier, aeInvocationIdentifier);
			callingAEI.resolve();
		} else {
			//TODO
		}
#endif
		if (aarq.called_AP_title_is_present()) {
			calledAPtitle = *aarq.get_called_AP_title();
		}
		if (aarq.called_AE_qualifier_is_present()) {
			calledAEqualifier = *aarq.get_called_AE_qualifier();
		}
		if (aarq.called_AP_invocation_identifier_is_present()) {
			calledAPInvocationIdentifier = *aarq.get_called_AP_invocation_identifier();
		}
		if (aarq.called_AE_invocation_identifier_is_present()) {
			calledAEInvocationIdentifier = *aarq.get_called_AE_invocation_identifier();
		}
#if 0
		AEI calledAEI = nullptr;
		if (title != nullptr && qualifier != nullptr) {
			calledAEI = new AEI(title, apInvocationIdentifier, qualifier, aeInvocationIdentifier);
			calledAEI.resolve();
		} else {
			//TODO
		}
#endif

#if 0
		Class<?> application = nullptr;
		String[] arguments = nullptr;
		if (calledAEI != nullptr) {
			if (calledAEI.title() == nullptr && calledAEI.qualifier() == nullptr) {
				;//FIXME error
			}
			if (calledAEI.title().isAp_title_form1() && calledAEI.qualifier().isAe_qualifier_form1()) {
				application = calledAEI.getJavaClass();
				arguments = calledAEI.getArguments();
			} else

			if (calledAEI.title().isAp_title_form2() && calledAEI.qualifier().isAe_qualifier_form2()) {
//TODO
				Type type = Reflection.type(MSAPStarter);
				application = type.load();
//					responder().PConnectResponse(provider_rejection, nullptr, presentationResults, defaultContextResult,
//						nullptr, nullptr, new SSN(SERIAL_NONE), 0, reference, nullptr, pa);
//					return NOTOK;
			} else {
				;//FIXME
			}
		}
		if (application == nullptr) {
			responder().PConnectResponse(provider_rejection, nullptr, presentationResults, defaultContextResult, nullptr, nullptr,
				new SSN(SERIAL_NONE), 0, reference, nullptr, pa);
			return NOTOK;
		}
		rc = NOTOK;
		List<Class<?>> interfaces = getInterfaces(application);
		boolean hasRoSAPRespondations = false;
		boolean hasRoSAPResponder1 = false;
		boolean hasRoSAPResponder2 = false;
		boolean hasRoSAPResponder3 = false;
		boolean hasRtSAPResponder = false;
		boolean hasASAPRespondations = false;
		boolean hasASAPStacker = false;
		boolean hasCSAPIndications = false;
		boolean hasPSAPActivityIndications = false;
		boolean hasPSAPContextIndications = false;
		boolean hasPSAPDataIndications = false;
		boolean hasPSAPReportIndications = false;
		boolean hasPSAPSyncIndications = false;
		boolean hasPSAPTokenIndications = false;

//			RoSAPStacker,
//			RoSAPRespondations,
//			RoSAPIndications,
//			RoSAPPerformations,
//			CSAPIndications

		for (Class<?> itface : interfaces) {
			String name = itface.getCanonicalName();
			if (name.equals(RoSAPRespondations)) {
				hasRoSAPRespondations = true;
			} else

//				if (name.equals(RoSAPAssociationClass1Responder.class.getCanonicalName())) {
//					hasRoSAPResponder1 = true;
//				} else
//
//				if (name.equals(RoSAPAssociationClass2Responder.class.getCanonicalName())) {
//					hasRoSAPResponder2 = true;
//				} else
//
//				if (name.equals(RoSAPAssociationClass3Responder.class.getCanonicalName())) {
//					hasRoSAPResponder3 = true;
//				} else
//
			if (name.equals(RtSAPResponder)) {
				hasRtSAPResponder = true;
			} else

			if (name.equals(ASAPRespondations)) {
				hasASAPRespondations = true;
			} else

			if (name.equals(ASAPStacker)) {
				hasASAPStacker = true;
			} else

			if (name.equals(CSAPIndications)) {
				hasCSAPIndications = true;
//				} else
//					
//				if (name.equals(PSAPActivityIndications.class.getCanonicalName())) {
//					hasPSAPActivityIndications = true;
//				} else
//					
//				if (name.equals(PSAPContextIndications.class.getCanonicalName())) {
//					hasPSAPContextIndications = true;
//				} else
//					
//				if (name.equals(PSAPDataIndications.class.getCanonicalName())) {
//					hasPSAPDataIndications = true;
//				} else
//					
//				if (name.equals(PSAPReportIndications.class.getCanonicalName())) {
//					hasPSAPReportIndications = true;
//				} else
//					
//				if (name.equals(PSAPSyncIndications.class.getCanonicalName())) {
//					hasPSAPSyncIndications = true;
//				} else
//					
//				if (name.equals(PSAPTokenIndications.class.getCanonicalName())) {
//					hasPSAPTokenIndications = true;
			}
		}
		Object instance = nullptr;

		if (hasRoSAPRespondations) {
			ASAPResponder asapResponder = new ASAPServer(state, psap());
			Type type = Reflection.type("iso.itu.osi.als.rosap.provider.RoSAPStarter");
			Class<?> rosapStarterClass = type.load();
			Object rosapStarter;
			rosapStarter = Reflection.constructor().withParameterTypes(Class.class, ASAPResponder.class, String[].class).in(
				rosapStarterClass).newInstance(application, asapResponder, arguments);
			// TODO check RoSAPStarter implements ASAPStacker interface
//				RoSAPStarter rosapStarter = new RoSAPStarter(application, asapResponder, arguments);
			instance = rosapStarter;
			asapStacker = (ASAPStacker) rosapStarter;
			asapStacker.setASAPServices(asapResponder);
			asapStacker.setPSAPServices(psap);
		} else

		if (hasRoSAPResponder1) {
//				RoSAP rosap = nullptr;//new RoSAP(this);
//				acb_psap.setPSAPIndications(rosap);
//				instance = Reflection.constructor().withParameterTypes(RoSAPPerformer.class, ASAPResponder.class).in(
//					application).newInstance(rosap, this);
//				RoSAPAssociationClass1Responder rosap_responder = (RoSAPAssociationClass1Responder) instance;
//				rosap.setRoSAPResponder(rosap_responder);
		} else

		if (hasRoSAPResponder2) {
		} else

		if (hasRoSAPResponder3) {
		} else

		if (hasRtSAPResponder) {
			ASAPResponder asapResponder = new ASAPServer(state, psap);
//				RtSAP rtsap = new RtSAP(asapResponder, psap());
			Type type = Reflection.type("iso.itu.osi.als.rtsap.provider.RtSAP");
			Class<?> rtsapClass = type.load();
			Object rtsap;
			rtsap = Reflection.constructor().withParameterTypes(Class.class, ASAPResponder.class, PSAPServices.class).in(rtsapClass)
				.newInstance(application, asapResponder, psap());
			instance = rtsap;
			asapStacker = (ASAPStacker)rtsap;
			asapStacker.setASAPServices(asapResponder);
			asapStacker.setPSAPServices(psap);
		} else

		if (hasASAPRespondations && hasASAPStacker) {
			ASAPResponder asapResponder = new ASAPServer(state, psap);
			instance = Reflection.constructor().withParameterTypes(ASAPResponder.class, String[].class).in(application)
				.newInstance(asapResponder, arguments);
			asapStacker = (ASAPStacker) instance;
			asapStacker.setASAPServices(asapResponder);
			asapStacker.setPSAPServices(psap);
		} else {
			// XXX: should do AARE APDU, but can't given any useful info...
			responder().PConnectResponse(user_rejection, nullptr, presentationResults, defaultContextResult, nullptr, nullptr,
				new SSN(SERIAL_NONE), 0, reference, nullptr, pa);
			rc = NOTOK;
			return rc;
		}
		asapRespondations = (ASAPRespondations) instance;
		Application_context_name_list applicationContexts = nullptr;
		Mechanism_name mechanism = nullptr;
		Authentication_value authentification = nullptr;
		Implementation_data implementation = nullptr;
		ACSE_requirements senderACSERequirements = nullptr;

		if (logger() != nullptr) {
			logger().AcAssociateIndication(aarq.application_context_name(), applicationContexts, calledAEI, callingAEI,
				senderACSERequirements, mechanism, authentification, implementation, ascinfos, callingAddr, calledAddr,
				presentationContexts, presentationResults, defaultContext, defaultContextResult, prequirements, srequirements,
				isn, settings, reference, qos);
		}

		rc = asapRespondations.AcAssociateIndication(aarq.application_context_name(), applicationContexts, callingAEI,
			calledAEI, senderACSERequirements, mechanism, authentification, implementation, ascinfos, callingAddr, calledAddr,
			presentationContexts, presentationResults, defaultContext, defaultContextResult, prequirements, srequirements, isn,
			settings, reference, qos);

		if (rc == OK || rc == DONE) {
			//FIXME do setIndication upon AAssociateResponse.. and not now
			PSAPGetIndications psapIndications = nullptr;
			psapIndications = asapStacker.getPSAPIndications();
			for (int no = 0; no < presentationContexts.size(); no++) {
				Context_list._element_ context = presentationContexts.get(no);
				Result_list._element_ resulte = presentationResults.get(no);
				int pci = (int) context.getPresentation_context_identifier();
				if (pci != acb_acse_as_id) {
					Abstract_syntax_name asn = context.abstract_syntax_name();
					psapMapper.setPSAPActivityIndications(pci, psapIndications.getPSAPActivityIndications(asn));
					psapMapper.setPSAPContextIndications(pci, psapIndications.getPSAPContextIndications(asn));
					psapMapper.setPSAPDataIndications(pci, psapIndications.getPSAPDataIndications(asn));
					psapMapper.setPSAPReportIndications(pci, psapIndications.getPSAPReportIndications(asn));
					psapMapper.setPSAPSyncIndications(pci, psapIndications.getPSAPSyncIndications(asn));
					psapMapper.setPSAPTokenIndications(pci, psapIndications.getPSAPTokenIndications(asn));
					psapMapper.setPSAPReleaseIndications(pci, this);
					psapMapper.setPSAPAbortIndications(pci, this);
				}
			}
			asapIndications = asapStacker.getASAPIndications();
		}
		return rc;

	} catch (OutOfMemoryError e) {
		rc = NOTOK;//FIXMEaca.asaplose(ACS_CONGEST, nullptr, "out of memory");
	} catch (Asn1Exception e) {
		rc = NOTOK;//FIXMEaca.asaplose(ACS_PROTOCOL, nullptr, "expecting AARQ-pdu on " + P_CONNECT_INDICATION);
	} catch (IllegalArgumentException e) {
		e.printStackTrace();
	} catch (SecurityException e) {
		e.printStackTrace();
	}
	pa = new PSAPAbortImpl();

	responder().PConnectResponse(user_rejection, nullptr, presentationResults, defaultContextResult, nullptr, nullptr,
		new SSN(SERIAL_NONE), 0, reference, nullptr, pa);
	return NOTOK;
#endif
	} catch(...) {
	}
	acb_fsm.AARQ();
	return DONE;
}
ReturnCode Provider::PConnectConfirmation(
	const PresentationAddress&							respondingPresentationAddress,
	const Presentation_context_definition_list&			presentationContexts,
	const Presentation_context_definition_result_list&	presentationContextResults,
	int													defaultContextResult,
	const Presentation_requirements&					presentationRequirements, 
	const User_session_requirements&					sessionRequirements,
	int													settings, 
	const SSN&											isn,
	const Reference&									reference, 
	int													ssdusize,
	const QualityOfService&								qualityOfService, 
	int													result,
	const User_data*									userData) {
	acb_fsm.AARE(true);
	return DONE;
}
ReturnCode Provider::PReleaseIndication(const User_data* userData) {
	return DONE;
}
ReturnCode Provider::PReleaseConfirmation(bool affirmative, const User_data* userData) {
	return DONE;
}
ReturnCode Provider::PUAbortIndication(int reason, int extension, const User_data* userData) {
	return DONE;
}
ReturnCode Provider::PPAbortIndication(int reason, int extension, const User_data* userData) {
	return DONE;
}

// Outgoing events
// ------------------------------------------------------------------
// Abbreviated name 			Target Name and description
void Provider::A_ASCind() {		// AC-user A-ASSOCIATE indication primitive
		acb_logger->AAssociateIndication(
		 	applicationContext,
		 	applicationContexts,
			callingAPtitle,
			callingAEqualifier,
			callingAPInvocationIdentifier,
			callingAEInvocationIdentifier,
			calledAPtitle,
			calledAEqualifier,
			calledAPInvocationIdentifier,
			calledAEInvocationIdentifier,
		 	senderACSERequirements,
		 	mechanism,
			authentification,
		 	implementation,
		 	callingPresentationAddress,
		 	calledPresentationAddress,
			presentationContexts,
			presentationContextResults,
		 	defaultContext,
		 	defaultContextResult,
		 	presentationRequirements,
			sessionRequirements,
			isn,
			settings,
			reference,
			qualityOfService,
		 	userInformation
			);

		asap_user_responder->AAssociateIndication(
		 	applicationContext,
		 	applicationContexts,
			callingAPtitle,
			callingAEqualifier,
			callingAPInvocationIdentifier,
			callingAEInvocationIdentifier,
			calledAPtitle,
			calledAEqualifier,
			calledAPInvocationIdentifier,
			calledAEInvocationIdentifier,
		 	senderACSERequirements,
		 	mechanism,
			authentification,
		 	implementation,
		 	callingPresentationAddress,
		 	calledPresentationAddress,
			presentationContexts,
			presentationContextResults,
		 	defaultContext,
		 	defaultContextResult,
		 	presentationRequirements,
			sessionRequirements,
			isn,
			settings,
			reference,
			qualityOfService,
		 	userInformation
			);
}				

void Provider::A_ASCcnf(bool accepted) {//+AC-user A-ASSOCIATE confirm primitive (Result = accepted)
										//-AC-user A-ASSOCIATE confirm primitive (Result = rejected (permanent) or rejected (transient)) 
	Associate_result							result;
	Associate_source_diagnostic					diagnostic;

	acb_logger->AAssociateConfirmation(
		result,
		diagnostic,
		applicationContext,
		applicationContexts,
		respondingAPtitle,
		respondingAEqualifier,
		respondingAPInvocationIdentifier,
		respondingAEInvocationIdentifier,
		senderACSERequirements,
		mechanism,
		authentification,
		respondingPresentationAddress,
		presentationContextResults,
		defaultContextResult,
		qualityOfService,
		presentationRequirements,
		sessionRequirements,
		isn,
		settings,
		reference,
		userInformation
		);
	asap_user_initiator->AAssociateConfirmation(
		result,
		diagnostic,
		applicationContext,
		applicationContexts,
		respondingAPtitle,
		respondingAEqualifier,
		respondingAPInvocationIdentifier,
		respondingAEInvocationIdentifier,
		senderACSERequirements,
		mechanism,
		authentification,
		respondingPresentationAddress,
		presentationContextResults,
		defaultContextResult,
		qualityOfService,
		presentationRequirements,
		sessionRequirements,
		isn,
		settings,
		reference,
		userInformation
		);
		
}	
void Provider::AARQ() {					// AC-peer A-ASSOCIATE-REQUEST APDU The AARQ is sent as user data on a P-CONNECT request primitive
}					
void Provider::AARE(bool accepted) {	//+AC-peer A-ASSOCIATE-RESPONSE APDU (Result = accepted) The AARE+ is sent as user data on a P-CONNECT+ response primitive (Result = acceptance)
										//-AC-peer A-ASSOCIATE-RESPONSE APDU (Result = rejected (permanent) or rejected (transient)) The AARE- is sent as user data on a P-CONNECT- response primitive (Result = user-rejection)
}		
void Provider::A_RLSind() {				// AC-user A-RELEASE indication primitive
	Release_request_reason		requestReason;
	acb_logger->AReleaseIndication(requestReason);
}				
void Provider::A_RLScnf(bool affirmative) {	//+AC-user A-RELEASE confirm primitive (Result = affirmative)
											//-AC-user A-RELEASE confirm primitive (Result = negative)
	Release_response_reason		responseReason;
	acb_logger->AReleaseConfirmation(affirmative, responseReason, userInformation);
}		
void Provider::RLRQ() {					// AC-peer A-RELEASE-REQUEST ADPU The RLRQ is sent as user data on a P-RELEASE request primitive
}					
void Provider::RLRE(bool result) {		//+AC-peer A-RELEASE-RESPONSE APDU The RLRE+ is sent as user data on a P-RELEASE response primitive (Result = affirmative)
										//-AC-peer A-RELEASE-RESPONSE APDU The RLRE- is sent as user data on a P-RELEASE response primitive (Result = negative)
}			
void Provider::A_ABRind() {				// AC-user A-ABORT indication primitive (Source = ACSE service user or ACSE service-provider)
	ABRT_source					source;
	ABRT_diagnostic				diagnostic;
	acb_logger->AAbortIndication(source, diagnostic, userInformation);
}				
void Provider::ABRT() {					// AC-peer A-ABORT APDU (Source = ACSE service-user or ACSE service-provider) The ABRT is sent as user data on a P-U-ABORT request primitive
}					
void Provider::P_PABind() {				// AC-user A-P-ABORT indication primitive
	int						reason = 0;
	int						extension = 0;
	acb_logger->APAbortIndication(reason, extension, userInformation);
}				

// Predicate
// ------------------------------------------------------------------
bool Provider::p1() const {	// ACPM can support requested connection
	return true; 
}
bool Provider::p2() const { // ACPM originated this association
	return false; 
}	
}
}
}
