/*
 * Provider.cpp
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#include "als/psap/prov/Logger.h"
#include "als/psap/prov/Provider.h"
#include "als/psap/TransfertSyntaxes.h"
using ALS::PSAP::TransfertSyntaxes;

namespace ALS {
namespace PSAP {
namespace PROV {
Provider::Provider() : pb_fsm(*this) {
	reset();
}
void Provider::reset() {
}
Provider::Provider(ALS::PSAP::USER::Initiator* initiator) : pb_fsm(*this) {
	reset();
}
Provider::~Provider() {
}
ALS::SSAP::USER::Initiator*		Provider::initiator() const {
	return static_cast<ALS::SSAP::USER::Initiator*>((Provider*)this);
}
ALS::SSAP::USER::Responder*		Provider::responder() const {
	return static_cast<ALS::SSAP::USER::Responder*>((Provider*)this);
}
ALS::SSAP::SERV::Responder*&	Provider::provider() {
	return ssap_serv_responder;
}
ReturnCode Provider::PConnectRequest(const PresentationAddress& callingPresentationAddress, const PresentationAddress& calledPresentationAddress, const Presentation_context_definition_list& presentationContexts,	const Default_context_name& defaultContext,	const Presentation_requirements& presentationRequirements,	const Mode_selector& mode, const User_session_requirements& sessionRequirements, const SSN& isn, const int settings, const Reference& reference, const QualityOfService& qualityOfService, const User_data* userData) {
	ReturnCode rc = OK;
	return rc; 
}
ReturnCode Provider::PConnectResponse(int status, const PresentationAddress& respondingAddr,const Presentation_context_definition_result_list& results, int defaultContextResult, const Presentation_requirements& presentationRequirements, const User_session_requirements& sessionRequirements,	const SSN& isn, byte settings, const Reference& reference, const User_data* userData) {
	ReturnCode rc = OK;
	return rc; 
}
ReturnCode Provider::PActivityDiscardRequest(int reason) {
	ReturnCode rc = OK;
	pb_logger->PActivityDiscardRequest(reason);
	try {
		pb_fsm.P_ACTDreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityDiscardResponse() {
	ReturnCode rc = OK;
	pb_logger->PActivityDiscardResponse();
	try {
		pb_fsm.P_ACTDrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityInterruptRequest(int reason) {
	ReturnCode rc = OK;
	pb_logger->PActivityInterruptRequest(reason);
	try {
		pb_fsm.P_ACTIreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityInterruptResponse() {
	ReturnCode rc = OK;
	pb_logger->PActivityInterruptResponse();
	try {
		pb_fsm.P_ACTIrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityStartRequest(const ActivityId& activityId, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PActivityStartRequest(activityId, userData);
	try {
		pb_fsm.P_ACTSreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& ssn, const Reference& oldReference,	const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PActivityResumeRequest(activityId, oldActivityId, ssn, oldReference, userData);
	try {
		pb_fsm.P_ACTRreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityEndRequest(const SSN& ssn, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PActivityEndRequest(ssn, userData);
	try {
		pb_fsm.P_ACTEreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PActivityEndResponse(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PActivityEndResponse(userData);
	try {
		pb_fsm.P_ACTErsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PAlterContextRequest(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const User_data* userData) {
	ReturnCode rc = OK;
	try {
		pb_fsm.P_ALTERreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PAlterContextResponse(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData) {
	ReturnCode rc = OK;
	try {
		pb_fsm.P_ALTERrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PCapabilityDataRequest(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PCapabilityDataRequest(userData);
	try {
		pb_fsm.P_CDreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PDataRequest(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PDataRequest(userData);
	try {
		pb_fsm.P_DTreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PExpeditedDataRequest(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PExpeditedDataRequest(userData);
	try {
		pb_fsm.P_EXreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PTypedDataRequest(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PTypedDataRequest(userData);
	try {
		pb_fsm.P_TDreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PExpeditedDataIndication(const User_data& userData) {
	ReturnCode rc = OK;
	pb_logger->PExpeditedDataIndication(userData);
	try {
//FIXME
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PResynchronizeRequest(const ResyncOption& type, const SSN& ssn, byte tokens, const User_data* userData) {
	ReturnCode rc = OK;
	try {
		pb_fsm.P_RSYNreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PSyncMajorRequest(const SSN& ssn, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PSyncMajorRequest(ssn, userData);
	try {
		pb_fsm.P_SYNMrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PSyncMinorRequest(const SyncOption& type, const SSN& ssn, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PSyncMinorRequest(type, ssn, userData);
	try {
		pb_fsm.P_SYNmreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PResynchronizeResponse(const SSN& ssn, int tokens, const Presentation_context_identifier_list& presentationIdentififiers, const User_data* userData) {
	ReturnCode rc = OK;
	try {
//FIXME		pb_fsm.P_ACTDreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PSyncMajorResponse(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PSyncMajorResponse(userData);
	try {
		pb_fsm.P_SYNMrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PSyncMinorResponse(const SSN& ssn, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PSyncMinorResponse(ssn, userData);
	try {
		pb_fsm.P_SYNmrsp();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PControlGiveRequest() {
	ReturnCode rc = OK;
	pb_logger->PControlGiveRequest();
	try {
		pb_fsm.P_CGreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PTokenGiveRequest(int tokens, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PTokenGiveRequest(tokens, userData);
	try {
		pb_fsm.P_GTreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PTokenPleaseRequest(int tokens, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PTokenPleaseRequest(tokens, userData);
	try {
		pb_fsm.P_PTreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PUExceptionReportRequest(int reason, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PUExceptionReportRequest(reason, userData);
	try {
		pb_fsm.P_UERreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PUAbortRequest(const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PUAbortRequest(userData);
	try {
		pb_fsm.P_UABreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PReleaseRequest(int secs, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PReleaseRequest(secs, userData);
	try {
		pb_fsm.P_RELreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::PReleaseResponse(int status, const User_data* userData) {
	ReturnCode rc = OK;
	pb_logger->PReleaseResponse(status, userData);
	try {
		pb_fsm.P_RELrsp(true);
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc; 
}
ReturnCode Provider::SConnectIndication(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, int result, const QualityOfService& qualityOfService, const Requirement& requirements, SSN& firstInitialSSN,	SSN& secondInitialSSN, 	int settings, int ssdusize, int cc, const void* data) {
		ReturnCode rc = NOTOK;
		CP_type cp;
		try {
			pb_srequirements = requirements;
			pb_ssdusize = ssdusize;

#if 0
			BERDecode(data, cp);

			Mode_selector mode = cp.get_mode_selector();
			if (mode.get_mode_value() != normal_mode) {
				;//FIXME return ppktlose(Abort_reason.invalid_ppdu_parameter_value, PPDU_CP, nullptr, "X.410-mode not supported");
			}
			CP_type::normal_mode_parameters& cp_normal = *cp.get_normal_mode_parameters();

			PresentationAddress::pSelector* pSelector;
			PresentationAddress::sSelector* sSelector;
			PresentationAddress::tSelector* tSelector;
			PresentationAddress::nAddresses* nAddresses;

			PresentationAddress* callingPSAP;
			nAddresses = new PresentationAddress::nAddresses();
			if (cp_normal.calling_presentation_selector_is_present()) {
				pSelector = cp_normal.get_calling_presentation_selector();
				const Selector& ssapSelector = calling.selector();
				sSelector = new PresentationAddress::sSelector(ssapSelector.length(), ssapSelector.data());
				const Selector& tsapSelector = calling.tsapaddr.selector();
				tSelector = new PresentationAddress::tSelector(tsapSelector.length(), tsapSelector.data());
				callingPSAP = new PresentationAddress(pSelector, sSelector, tSelector, nAddresses);
			} else {
				callingPSAP = new PresentationAddress(nAddresses);
			}


			PresentationAddress* calledPSAP;
			nAddresses = new PresentationAddress::nAddresses();
			if (cp_normal.called_presentation_selector_is_present()) {
				pSelector = cp_normal.get_called_presentation_selector();
				const Selector& ssapSelector = called.selector();
				sSelector = new PresentationAddress::sSelector(ssapSelector.length(), ssapSelector.data());
				const Selector& tsapSelector = called.tsapaddr.selector();
				tSelector = new PresentationAddress::tSelector(tsapSelector.length(), tsapSelector.data());
				calledPSAP = new PresentationAddress(pSelector, sSelector, tSelector);
			} else {
				calledPSAP = new PresentationAddress(called);
			}

			if (cp_normal.presentation_context_definition_list_is_present()) {
				pb_pcdl = cp_normal.get_presentation_context_definition_list();
			}

			if (pb_pcdl != nullptr) {
				pb_pcdrl = new Presentation_context_definition_result_list();

				
				for (OssIndex pcdlno = 0; pcdlno != OSS_NOINDEX; pcdlno = pb_pcdl->next(pcdlno)) {
					const Context_list::component& context = *pb_pcdl->at(pcdlno);
					Abstract_syntax_name asn = context.get_abstract_syntax_name();
					int pci = (int) context.get_presentation_context_identifier();
					Context_list::component::transfer_syntax_name_list tsnl;
					tsnl = context.get_transfer_syntax_name_list();

					Result_list::component resultContext;
					for (OssIndex tsnno = 0; tsnno != OSS_NOINDEX; tsnno = tsnl.next(tsnno)) {
						const Transfer_syntax_name& atn = *tsnl.at(tsnno);
						if (TransfertSyntaxes::isSupported(atn)) {
							resultContext.set_result(Presentation_context_deletion_result_list_acceptance);
							resultContext.set_transfer_syntax_name(atn);
							break;
						} else {
							resultContext.set_result(provider_rejection);
							resultContext.set_transfer_syntax_name(atn);
							resultContext.set_provider_reason(proposed_transfer_syntaxes_not_supported);
							break;
						}
					}
					pb_pcdrl->(resultContext);
				}
			}

			if (pb_pcdl != nullptr && pb_pcdrl != nullptr) {
				assert (pb_pcdl.size() == pb_pcdrl.size());
			}

			int ppno;

			User_data* infos = nullptr;
			if (cp_normal.user_data_is_present()) {
				infos = cp_normal.get_user_data();
			}

			pb_asn = DEFAULT_ABSTRACT_SYNTAX_NAME;
			pb_atn = DEFAULT_TRANSFERT_SYNTAX_NAME;
			if (cp_normal.default_context_name_is_present()) {
				pb_asn = cp_normal.get_default_context_name()->get_abstract_syntax_name();
				pb_atn = cp_normal.get_default_context_name()->get_transfer_syntax_name();
				pb_defaultContext = cp_normal.get_default_context_name();
				pb_defaultContextResult = 0;

				//FIXME pb_flags |= PB_DFLT;

				for (OssIndex ppno = 0; ppno != OSS_NOINDEX; ppno = pb_pcdl.next(ppno) {
					Context_list::component context;
					context = pb_pcdl.at(ppno);
// 					if ((pp.asn() == pb_state.pb_asn) && (pp.atn() == pb_state.pb_atn)) {
// 						pb_state.pb_dctxid = pp.id();
// 						break;
// 					}
				}
			}
			pb_result = pb_defaultContextResult;

			if (cp_normal.presentation_requirements_is_present()) {
				if (!pb_srequirements[SSAP::TYPEDATA]) {
					OssBitString	preq;
					preq.assign(restoration, true);
					cp_normal.set_presentation_requirements(preq);
				}
				pb_prequirements = cp_normal.presentation_requirements();
			}

			if (cp_normal.user_session_requirements_is_present()) {
				pair pps;

				BitSet usr = cp_normal.get_user_session_requirements().bitSetValue();
				for (ppno = 0; ppno < sreq_pairs.length; ppno++) {
					pps = sreq_pairs[ppno];
					if (usr.get(pps.bitno()))
						pb_urequirements |= pps.mask();
				}
			} else {
				pb_urequirements = pb_srequirements;
			}
			User_session_requirements srequirements = getSessionRequirements(pb_urequirements
				& pb_srequirements);
			SSN ssn = new SSN(firstInitialSSN);

			if (pb_logger != nullptr) {
				pb_logger->PConnectIndication(callingPSAP, calledPSAP, pb_pcdl, pb_pcdrl,
					pb_defaultContext, pb_prequirements, mode, srequirements, ssn, settings,
					reference, infos, qualityOfService);
			}
			string provider;
			ISOService psapservice = nullptr;
			if (calledPSAP.selector() != nullptr && calledPSAP.selector().length() > 0) {
				psapservice = PSAP_SERVICES.getServiceBySelector(calledPSAP.selector());
			}
			if (psapservice != nullptr) {
				provider = psapservice.klass();
			} else {
				provider = ASAP_PROVIDER;
			}
			rc = NOTOK;
			try {
				Class<?> providerClass = nullptr;
				providerClass = Reflection.type(provider).load();
				Class<?>[] interfaces = providerClass.getInterfaces();
				boolean hasPSAPRespondations = false;
				for (int no = 0; no < interfaces.length; no++) {
					String name = interfaces[no].getCanonicalName();
					if (name.equals(PSAPRespondations.class.getCanonicalName())) {
						hasPSAPRespondations = true;
						break;
					}
				}

				if (hasPSAPRespondations) {
					PSAPResponder responder;
					responder = new PSAPServer(this, ssap());

					Object instance;
					instance = Reflection.constructor().withParameterTypes(PSAPResponder.class,
						PSAPMapper.class).in(providerClass).newInstance(responder, this);

					psapRespondations = (PSAPRespondations) instance;
					rc = psapRespondations.PConnectIndication(callingPSAP, calledPSAP, pb_pcdl,
						pb_pcdrl, pb_defaultContext, pb_prequirements, mode, srequirements,
						ssn, settings, reference, infos, qualityOfService);

					psapIndications = (PSAPIndications)instance;
//					SSAPIndications ssapIndications = new PSAPIndicator(pb_state, psapIndications);
//					pb_state.pb_ssap_setter.setSSAPIndications(ssapIndications);

//					instance = Reflection.constructor().withParameterTypes(ASAPRespondations.class, PSAP.class).in(
//						providerClass).newInstance(pb_state.pb_responder, this);
//					pb_state.pb_responder = (PSAPRespondations) instance;
//					rc = pb_state.pb_responder.PConnectIndication(callingPSAP, calledPSAP, pb_state.pb_pcdl, pb_state.pb_pcdrl, pb_state.pb_defaultContext,
//						pb_state.pb_prequirements, mode, srequirements, ssn, settings, reference, infos, qualityOfService);
				} else {
					;//FIXME return error;
				}
				return rc;
			} catch (Exception e) {
				rc = NOTOK;
			}
		} catch (Asn1Exception e) {
			//FIXME rc = ppktlose(Abort_reason.unrecognized_ppdu, PPDU_CP, nullptr, "%s");
		} catch (OutOfMemoryError e) {
			//FIXME rc = pa.psaplose(Provider_reason.temporary_congestion, nullptr, nullptr);
			// rc = SC_CONGESTION;
		}
#else
		} catch(...) {
			//FIXME
		}

#endif
	return rc; 
}
ReturnCode Provider::SConnectConfirmation(const Reference& reference, const SSAPAddr& responding,	int result,	const QualityOfService& qualityOfService,	const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize,	int cc, const void* data, int rdcc, const void* realdata) {
#if 0
	int no;
		ReturnCode rc = NOTOK;
		int reason;
		Asn1Type* pe;
		NetworkBuffer* qb;
		CPA_PPDU* cpa = nullptr;
		CPR_PPDU* cpr = nullptr;
		ARP_PPDU* arp = nullptr;
		CPA_PPDU::normal_mode_parameters cpa_normal = nullptr;
		CPR_PPDU::normal_mode_parameters cpr_normal = nullptr;
		PSAPAddr pc_responding; // address of peer responding
		Presentation_context_definition_list pc_contexts; // the list of negotiated contexts
		Presentation_context_definition_result_list pc_results;

		int pc_defctxresult; // rc for proposed default context name
		Presentation_requirements pc_prequirements; // presentation requirements
		User_session_requirements pc_srequirements; // session requirements
		int pc_result;

		try {
			pe = nullptr;
			pb_retry = nullptr;

			if (result == SC_ABORT) {
				sa.ss2psabort(pa);
				pc_result = PC_ABORTED;
				return DONE;
			}

//
// 			if (sc.rejected()) {
// 				sa.reason() = sc.rc();
// 				pa.ss2pslose ("SAsynConnRequest(pseudo)", sa);
// 				pc.pc_result = pa.pa_reason;
// 				rc = DONE;
// 				return rc;
// 			} else {
// 				rc = pa.ppktlose (rc != OKPS_ERR_NMEM ? PC_UNRECOGNIZED : PC_NOTSPECIFIED, sc.accepted() ?// PPDU_CPA : PPDU_CPR, nullptr, "%s");
// 				goto out2;
//			}

			if (result == SC_ACCEPT) {
				pe = cpa = new CPA_PPDU();
				BERDecode(data, pe);
				addState(PB_CONN);

				pb_srequirements = requirements;
				pb_urequirements &= pb_srequirements;

				if (hasSRequirements(RELEASE_UNIT_EXISTS)) {
					switch (selectReleaseToken(settings)) {
					case INITIATOR_VALUE << RELEASE_SHIFT:
						pb_owned = addReleaseToken(pb_owned);
						pb_avail = addReleaseToken(pb_avail);
						break;

					case RESPONDER_VALUE << RELEASE_SHIFT:
						pb_avail = addReleaseToken(pb_avail);
						break;
					}
				}

				if (hasSRequirements(MAJOR_UNIT_EXISTS) || hasSRequirements(ACTIVITY_UNIT_EXISTS)) {
					switch (selectMajorToken(settings)) {
					case INITIATOR_VALUE << MAJOR_SHIFT:
						pb_owned = addMajorToken(pb_owned);
						pb_avail = addMajorToken(pb_avail);
						break;

					case RESPONDER_VALUE << MAJOR_SHIFT:
						pb_avail = addMajorToken(pb_avail);
						break;
					}
				}

				if (hasSRequirements(MINOR_UNIT_EXISTS)) {
					switch (selectMinorToken(settings)) {
					case INITIATOR_VALUE << MINOR_SHIFT:
						pb_owned = addMinorToken(pb_owned);
						pb_avail = addMinorToken(pb_avail);
						break;

					case RESPONDER_VALUE << MINOR_SHIFT:
						pb_avail = addMinorToken(pb_avail);
						break;
					}
				}

				if (hasSRequirements(DATA_UNIT_EXISTS)) {
					switch (selectDataToken(settings)) {
					case INITIATOR_VALUE << DATA_SHIFT:
						pb_owned = addDataToken(pb_owned);
						pb_avail = addDataToken(pb_avail);
						break;

					case RESPONDER_VALUE << DATA_SHIFT:
						pb_avail = addDataToken(pb_avail);
						break;
					}
				}

				pb_ssdusize = ssdusize;
// 				if (decode_PS_CPA_PPDU (pe, 1, nullptr, nullptr, cpa) == NOTOK)
// 					pa.ppktlose (PC_UNRECOGNIZED, PPDU_CPA, nullptr, "%s");

				if (!cpa.hasNormal_mode_parameters()) {
					//FIXME rc = ppktlose(Abort_reason.invalid_ppdu_parameter_value, PPDU_CPA, nullptr, "X.410 mode mismatch");
					return rc;
				}
				cpa_normal = cpa.normal_mode_parameters();

			} else {
				pe = cpr = new CPR_PPDU();
				BERDecode(data, pe);
				if (result == SC_NOTSPECIFIED) {
					BERDecode(data, arp);

// 					if (decode_PS_ARP_PPDU (pe, 1, nullptr, nullptr, arp) == NOTOK) {
// 						rc = pa.ppktlose (PC_UNRECOGNIZED, PPDU_ARP, nullptr, "%s"); return rc;
// 					}
					if (arp.hasProvider_reason()) {
						if ((reason = (int) arp.getProvider_reason()) == 0)
							reason = Provider_reason.reason_not_specified;
						else
							reason += PC_ABORT_BASE;
					} else
						reason = Provider_reason.reason_not_specified;

					rc = pa.psaplose(reason, nullptr, nullptr);
					return rc;
				}

// 				if (decode_PS_CPR_PPDU (pe, 1, nullptr, nullptr, cpr) == NOTOK) {
// 					pa.ppktlose (PC_UNRECOGNIZED, PPDU_CPR, nullptr, "%s");
//					 goto out2;
// 				}

				if (!cpr.isNormal_mode_parameters()) {
					ppktlose(Abort_reason.invalid_ppdu_parameter_value, PPDU_CPR, nullptr, "X.410 mode mismatch");
					return rc;
				}
				cpr_normal = cpr.normal_mode_parameters();

			}

			pb_responding = new PSAPAddr(respondingAddr);
			Responding_presentation_selector rps;
			if (cpa != nullptr) {
				rps = cpa_normal.get_responding_presentation_selector();
			} else {
				rps = cpr_normal.get_responding_presentation_selector();
			}
			if (rps == nullptr) {
				//FIXME rc = ppktlose(Abort_reason.invalid_ppdu_parameter_value, PPDU_CPA, nullptr, "malformed PSAP selector");
				return rc;
			}

			pc_responding = pb_responding;

			if (cpa != nullptr) {
				pb_pcdrl = cpa_normal.get_presentation_context_definition_result_list();
			} else {
				pb_pcdrl = cpr_normal.get_presentation_context_definition_result_list();
			}

			if (cpa != nullptr && pb_pcdl.size() != pb_pcdrl.size()) {
				//FIXME rc = ppktlose(Abort_reason.invalid_ppdu_parameter_value, PPDU_CPA, nullptr, "proposed/resulting presentation contexts mismatch");
				return rc;
			}
			for (no = 0; no < pb_pcdl.size(); no++) {
				Context_list::element contextElement = pb_pcdl.get(no);
				Result_list::component resultElement = pb_pcdrl.get(no);
				switch ( resultElement.get_result()) {
				case Result_acceptance:
					break;

				case Result_user_rejection:
				case provider_rejection:
					break;
				default:
					break;
				}
			}

			pc_contexts = pb_pcdl;
			pc_results = pb_pcdrl;

			carry_on:
			;

			if (cpr == nullptr || !cpr_normal.hasDefault_context_result())
				pc_defctxresult = Result_acceptance;
			else
				switch (cpr_normal.default_context_result().intValue()) {
				case Result_acceptance:
				default:
					pc_defctxresult = acceptance;
					break;

				case Result_user_rejection:
					pc_defctxresult = user_rejection;
					break;

				case provider_rejection:
					pc_defctxresult = Provider_reason.reason_not_specified;
					break;
				}

			User_data userData;
			int ppdu;
			if (cpa != nullptr) {
				userData = cpa_normal.get_user_data();
				ppdu = ppdu_CPA;
			} else {
				userData = cpr_normal.get_user_data();
				ppdu = ppdu_CPR;
			}

			if (result == SC_ACCEPT) {
				if (cpa_normal.hasPresentation_requirements()) {
					pair pp;

// 			if (!(pb_state.pb_srequirements & SR_TYPEDATA)) {
// 				cpa_normal.presentation_fu.bit_off(bit_PS_Presentation_requirements_context_management);
// 				cpa_normal.presentation_fu.bit_off(bit_PS_Presentation_requirements_restoration);
// 			}
// 			 for (pp =preq_pairs; pp.p_mask; pp++) 
// 				if (!(pb_state.pb_prequirements & pp.p_mask)) {
// 					 if (cpa_normal.presentation_fu.bit_test(pp.p_bitno) == 1) {
// 						pa.ppktlose (PC_INVALID, PPDU_CPA, nullptr, "presentation-requirements negotiation botched");
// 						;//goto out2;
// 					 }
// 				 } else if (cpa_normal.presentation_fu.bit_test(pp.p_bitno) < 1)
// 					pb_state.pb_prequirements &= ~pp.p_mask;

				}
				pc_prequirements = pb_prequirements;

				if (cpa_normal.hasUser_session_requirements()) {
					int ppno;
					pair pp;

//					for (ppno = 0; ppno < preq_pairs.length; ppno++) {
//						pp = preq_pairs[ppno];
// 						if (cpa_normal.session_fu.bit_test( pp.p_bitno) < 1)
// 						pb_state.pb_urequirements &= ~pp.mask();
//					}
				}
				pc_srequirements = getSessionRequirements(pb_urequirements);
				pc_result = acceptance;

			} else {
				if (cpr_normal.hasProvider_reason())
					pc_result = cpr_normal.provider_reason().intValue() + PC_PROV_BASE;
				else
					pc_result = Provider_reason.reason_not_specified;
			}
			if (logger() != nullptr) {
				((PSAPLogger)logger()).PConnectConfirmation(pc_responding, pc_contexts, pc_results, pc_defctxresult,
					pc_prequirements, pc_srequirements, settings, firstInitialSSN, reference, ssdusize, qualityOfService, pc_result,
					userData);
			}
			psapProvider = new PSAPProvider(this, ssapServices);
			psapStacker.setPSAPServices(psapProvider);
//			psapProvider.setSSAPServices(ssapServices);

			psapInitiations = psapStacker.getPSAPInitiations();
			rc = psapInitiations.PConnectConfirmation(pc_responding, pc_contexts, pc_results, pc_defctxresult,
				pc_prequirements, pc_srequirements, settings, firstInitialSSN, reference, ssdusize, qualityOfService, pc_result,
				userData);

			psapIndicator = new PSAPIndicator(this);
			PSAPGetIndications psapIndications = psapStacker.getPSAPIndications();
			if (psapIndications != nullptr) {
				psapIndicator.setPSAPActivityIndications(1, psapIndications.getPSAPActivityIndications(nullptr));
				psapIndicator.setPSAPContextIndications(1, psapIndications.getPSAPContextIndications(nullptr));
				psapIndicator.setPSAPDataIndications(1, psapIndications.getPSAPDataIndications(nullptr));
				psapIndicator.setPSAPReportIndications(1, psapIndications.getPSAPReportIndications(nullptr));
				psapIndicator.setPSAPSyncIndications(1, psapIndications.getPSAPSyncIndications(nullptr));
				psapIndicator.setPSAPTokenIndications(1, psapIndications.getPSAPTokenIndications(nullptr));
			}
			ssapInitiator.setSSAPIndications(psapIndicator);
//			PSAPIndications psapIndications = psapStacker.getPSAPIndications();
			psapIndicator.setPSAPReleaseIndications(1, psapStacker.getPSAPReleaseIndications());
			psapIndicator.setPSAPAbortIndications(1, psapStacker.getPSAPAbortIndications());

		} catch (Asn1Exception e) {
			ppktlose(Abort_reason.unrecognized_ppdu, PPDU_CPR, nullptr, "%s", e.getMessage());
		}

		return rc;
#endif
		return DONE;
}
ReturnCode Provider::SUAbortIndication(int reason, int cc, const void* data) {
	ReturnCode rc = DONE;
	return rc; 
}
ReturnCode Provider::SPAbortIndication(int reason, int extension, int cc, const void* data) {
	ReturnCode rc = DONE;
	return rc; 
}
ReturnCode Provider::SActivityDiscardIndication(int reason, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTDind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityDiscardConfirmation(int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTDcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityEndIndication(const SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTEind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityEndConfirmation(const SSN& secondSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTEcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityInterruptIndication(int reason, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTIind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityInterruptConfirmation(int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTIcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTRind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SActivityStartIndication(const ActivityId&  activityId, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_ACTSind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.TD();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SCapabilityDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.TC();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SCapabilityDataConfirmation(const SharedNetworkBuffer& data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.TCC();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SExpeditedDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.TE();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::STypedDataIndication(const SharedNetworkBuffer& dataL) {
	ReturnCode rc = DONE;
	try {
		//FIXME pb_fsm
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SUExceptionReportIndication(int reason, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_UERind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SPExceptionReportIndication(int reason) {
	ReturnCode rc = DONE;
	try {
		//FIXME pb_fsm
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.RS();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.RSA();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SSyncMajorIndication(const SSN& firsSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_SYNMind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SSyncMajorConfirmation(int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_SYNMcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SSyncMajorConfirmation(const SSN& secondSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_SYNMcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_SYNmind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SSyncMinorConfirmation(const SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_SYNmcnf();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SControlGiveIndication( int tokens, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_CGind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::STokenGiveIndication(int tokens, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_GTind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::STokenPleaseIndication(int tokens, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_PTind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SReleaseIndication(int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_RELind();
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
ReturnCode Provider::SReleaseConfirmation(bool affirmative, int cc, const void* data) {
	ReturnCode rc = DONE;
	try {
		pb_fsm.S_RELcnf(affirmative);
	} catch (statemap::SmcException& e) {
		rc = userException(e);
	}
	return rc; 
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Special actions
//
void Provider::sa01() { // Mark presentation contexts proposed for definition which provider cannot support as provider-rejection.
}
void Provider::sa02() { // Set cr and rl to FALSE.
	cr = rl = false;
}
void Provider::sa03() { // Record abstract and transfer syntaxes for the presentation contexts of the agreed DCS and for the default context.
}
void Provider::sa04() { // Propose at least one transfer syntax for each presentation context.
}
void Provider::sa05() { // Propose a transfer syntax for the default context if one is named in the request service primitive.
}
void Provider::sa06() { // Select one transfer syntax for each presentation context agreed for definition and include the agreed presentation contexts in the DCS.
}
void Provider::sa07() { // Set rl to TRUE.
	rl = true;
}
void Provider::sa08() { // If rl is TRUE then set cr to TRUE.
	if (rl == true)
		cr = true;
}
void Provider::sa09() { // If aep is TRUE then:	a) set aep to FALSE{ and	b) if FU(CR) is TRUE then the synchronization points associated with the last activity no longer have associated DCSs.
}
void Provider::sa10() { // Record selected transfer syntax for each new presentation context and include new presentation
}
void Provider::sa11() { // Remove the presentation contexts agreed for deletion from the DCS.
}
void Provider::sa12() { // Record FU(f) for f in fu-dom according to the presentation requirements in the CPA PPDU.
}
void Provider::sa13() { // If FU(CR) then associate the DCS with the syncpoint identifier.
}
void Provider::sa14() { // If FU(CR) and an activity is in progress, set the DCS to the inter-activity DCS.
}
void Provider::sa15() { // Set aep to TRUE.
	aep = true;
}
void Provider::sa16() { // Set the DCS to that associated with the syncpoint identifier.
}
void Provider::sa17() { // If FU(CR) then remember the DCS as the inter-activity DCS.
}
void Provider::sa18() { // Set the DCS to that agreed during presentation-connection establishment.
}
void Provider::sa19() { // Eliminate any associations between syncpoint serial number and the DCS for the current activity.
}
void Provider::sa20() { // Set aep to FALSE.
	aep = false;
}
void Provider::sa21() { // Set the DCS as specified by the Presentation context identifier list parameter of the PPDU.
}
void Provider::sa22() { // If FU(CR), then eliminate any associations between syncpoint identifiers and DCSs.
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Predicates
//
bool Provider::p01() const { return false; } // The presentation-connection is acceptable to the PPM (local matter).
bool Provider::p02() const { return false; } //  If present, the named default context can be supported.
bool Provider::p03() const { return false; } //  Each presentation data value is from a presentation context of the DCS proposed in the presentation-connection establishment, or from the default context if this DCS is empty.
bool Provider::p04() const { return false; } //  Each presentation data value is from a presentations contexts of the DCS being accepted in the presentationconnection establishment, or from the default context if this DCS is empty.
bool Provider::p05() const { return false; } //  Each presentation data value is from presentation contexts of the DCS, or from the default context if the DCS isempty.
bool Provider::p06() const { return false; } //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion from the DCS by the peer PPM.
bool Provider::p07() const { return false; } //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion from the DCS by the local PPM.
bool Provider::p08() const { return false; } //  The value of cr is TRUE.
bool Provider::p09() const { return false; } //  Each presentation data value is from presentation contexts of the DCS not accepted for deletion from the DCS, or from presentation contexts accepted for addition to the DCS, or if no such presentation contexts are available, from the default context.
bool Provider::p11() const { return false; } //  FU(CM) is TRUE.
bool Provider::p13() const { return false; } //  Each presentation data value is from the default context.
bool Provider::p14() const { return false; } //  FU(CM) is false, or FU(CM) is true and typed data functional unit was selected as a User session requirement.
bool Provider::p15() const { return false; } //  Each presentation data value is from presentation contexts of the DCS which was agreed during presentationconnection establishment, or from the default context if this DCS is empty.
bool Provider::p16() const { return false; } //  Each presentation data value is from presentation contexts of the DCS associated with the pair of Old activity	identifier and Synchronization point serial number parameter values or from the default context when this DCS is empty.
bool Provider::p17() const { return false; } //  FU(CR) is TRUE.
bool Provider::p18() const { return false; } //  Each presentation data value is in presentation contexts of the DCS associated with the syncpoint identifier or from the default context if this DCS is empty.
bool Provider::p19() const { return false; } //  Either no syncpoint identifier is associated with a DCS or the resync identifier is not associated with a DCS and is greater than the lowest syncpoint identifier which has an associated DCS.
bool Provider::p20() const { return false; } //  The PPDU contains a Presentation context identifier list parameter.
bool Provider::p21() const { return false; } //  Each presentation data value is from presentation contexts specified in the PPDU, or from the default context if no presentation contexts are specified in the PPDU.
bool Provider::p22() const { return false; } //  For each presentation data value, an instance (chosen as a local matter) of encoding is supported by the PPM.
bool Provider::p23() const { return false; } //  For each presentation data value the encoding is supported by the PPM.
bool Provider::p24() const { return false; } //  Each presentation data value is from presentation contexts of the DCS, or from presentation contexts proposed for addition to the DCS by the local PPM, or from the default context if either the DCS is empty or all presentation	contexts of the DCS were proposed for deletion by the local PPM.
bool Provider::p25() const { return false; } //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion by the peer PPM or from presentation contexts proposed for addition to the DCS by the local PPM.
bool Provider::p26() const { return false; } //  The syncpoint identifier has an associated DCS.
bool Provider::p27() const { return false; } //  Old session connection identifier parameter present.
bool Provider::p28() const { return false; } //  There is a DCS associated with the pair of Old activity identifier and Synchronization point serial number	parameters values.
bool Provider::p29() const { return false; } //  Each presentation data value is from presentation contexts of the inter-activity DCS or from the default context if the inter-activity DCS is empty.
bool Provider::p30() const { return rs == true; } //  The value of rs is TRUE.

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Outgoing events
//
void Provider::AC() {					//	PPDU 			ALTER CONTEXT
}
void Provider::ACA() {					//	PPDU 			ALTER CONTEXT ACKNOWLEDGE
}
void Provider::ARP() {					//	PPDU 			PROVIDER ABORT
}
void Provider::ARU() {					//	PPDU 			USER ABORT
}
void Provider::CP() {					//	PPDU 			PRESENTATION CONNECT
}
void Provider::CPA() {					//	PPDU 			PRESENTATION CONNECT ACCEPT
	Mode_selector::mode_value mv = x410_1984_mode;
	CPA_PPDU::mode_selector ms(mv);
	CPA_PPDU::x410_mode_parameters x410mp;
	CPA_PPDU::normal_mode_parameters nmp;
	CPA_PPDU cpa;
	
}
void Provider::CPR() {					//	PPDU 			PRESENTATION CONNECT REJECT
}
void Provider::P_ACTDcnf() {			//	PS primitive	P-ACTIVITY-DISCARD confirm
}
void Provider::P_ACTDind() {			//	PS primitive	P-ACTIVITY-DISCARD indication
}
void Provider::P_ACTEcnf() {			//	PS primitive	P-ACTIVITY-END confirm
}
void Provider::P_ACTEind() {			//	PS primitive	P-ACTIVITY-END indication
}
void Provider::P_ACTIcnf() {			//	PS primitive	P-ACTIVITY-INTERRUPT confirm
}
void Provider::P_ACTIind() {			//	PS primitive	P-ACTIVITY-INTERRUPT indication
}
void Provider::P_ACTRind() {			//	PS primitive	P-ACTIVITY-RESUME indication
}
void Provider::P_ACTSind() {			//	PS primitive	P-ACTIVITY-START indication
}
void Provider::P_ALTERcnf() {			//	PS primitive	P-ALTER-CONTEXT confirm
}
void Provider::P_ALTERind() {			//	PS primitive	P-ALTER-CONTEXT indication
}
void Provider::P_CDcnf() {				//	PS primitive	P-CAPABILITY-DATA confirm
}
void Provider::P_CDind() {				//	PS primitive	P-CAPABILITY-DATA indication
}
void Provider::P_CGind() {				//	PS primitive	P-CONTROL-GIVE indication
}
void Provider::P_CONcnf(bool accept) {	// +PS primitive	P-CONNECT confirm accept
										// -PS primitive	P-CONNECT confirm reject
}
void Provider::P_CONind() {				//	PS primitive	P-CONNECT indication
}
void Provider::P_DTind() {				//	PS primitive	P-DATA indication
}
void Provider::P_EXind() {				//	PS primitive	P-EXPEDITED-DATA indication
}
void Provider::P_GTind() {				//	PS primitive	P-TOKEN-GIVE indication
}
void Provider::P_PABind() {				//	PS primitive	P-P-ABORT indication
}
void Provider::P_PERind() {				//	PS primitive	P-P-EXCEPTION-REPORT indication
}
void Provider::P_PTind() {				//	PS primitive	P-TOKEN-PLEASE indication
}
void Provider::P_RELcnf(bool accept) {	//+ PS primitive	P-RELEASE confirm accept
										//-	PS primitive	P-RELEASE confirm reject
}
void Provider::P_RELind() {				//	PS primitive	P-RELEASE indication
}
void Provider::P_RSYNcnf() {	// PS primitive	P-RESYNCHRONIZE confirm
}
void Provider::P_RSYNind() {	// PS primitive	P-RESYNCHRONIZE indication
}
void Provider::P_SYNMcnf() {	// PS primitive	P-SYNC-MAJOR confirm
}
void Provider::P_SYNMind() {	// PS primitive	P-SYNC-MAJOR indication
}
void Provider::P_SYNmcnf() {	// PS primitive	P-SYNC-MINOR confirm
}
void Provider::P_SYNmind() {	// PS primitive	P-SYNC-MINOR indication
}
void Provider::P_TDind() {		// PS primitive	P-TYPED-DATA indication
}
void Provider::P_UABind() {		// PS primitive 	P-U-ABORT indication
}
void Provider::P_UERind() {		// PS primitive 	P-U-EXCEPTION-REPORT indication
}
void Provider::RS() {			// PPDU 			RESYNCHRONIZE
}
void Provider::RSA() {			// PPDU 			RESYNCHRONIZE acknowledge
}
void Provider::S_ACTDreq() {	// SS primitive	S-ACTIVITY-DISCARD request
}
void Provider::S_ACTDrsp() {	// SS primitive	S-ACTIVITY-DISCARD response
}
void Provider::S_ACTEreq() {	// SS primitive	S-ACTIVITY-END request
}
void Provider::S_ACTErsp() {	// SS primitive	S-ACTIVITY-END response
}
void Provider::S_ACTIreq() {	// SS primitive	S-ACTIVITY-INTERRUPT request
}
void Provider::S_ACTIrsp() {	// SS primitive	S-ACTIVITY-INTERRUPT response
}
void Provider::S_ACTRreq() {	// SS primitive	S-ACTIVITY-RESUME request
}
void Provider::S_ACTSreq() {	// SS primitive	S-ACTIVITY-START request
}
void Provider::S_CGreq() {		// SS primitive	S-CONTROL-GIVE request
}
void Provider::S_GTreq() {		// SS primitive	S-TOKEN-GIVE request
}
void Provider::S_PTreq() {		// SS primitive	S-TOKEN-PLEASE request
}
void Provider::S_RELreq() {		// SS primitive	S-RELEASE request
}
void Provider::S_RELrsp(bool accept) { //+	SS primitive	S-RELEASE response accept
										//-	SS primitive	S-RELEASE response reject
}
void Provider::S_RSYNreq() {	// SS primitive	S-RESYNCHRONIZE request
}
void Provider::S_RSYNrsp() {	// SS primitive	S-RESYNCHRONIZE response
}
void Provider::S_SYNMreq() {	// SS primitive	S-SYNCHRONIZE-MAJOR request
}
void Provider::S_SYNMrsp() {	// SS primitive	S-SYNCHRONIZE-MAJOR response
}
void Provider::S_SYNmreq() {	// SS primitive	S-SYNCHRONIZE-MINOR request
}
void Provider::S_SYNmrsp() {	// SS primitive	S-SYNCHRONIZE-MINOR response
}
void Provider::S_UERreq() {		// SS primitive	S-U-EXCEPTION-REPORT request
}
void Provider::TC() {			// PPDU 			CAPABILITY DATA
}
void Provider::TCC() {			// PPDU 			CAPABILITY DATA ACKNOWLEDGE
}
void Provider::TD() {			// PPDU 			DATA
}
void Provider::TE() {			// PPDU 			EXPEDITED DATA
}
void Provider::TTD() {			// PPDU 			P-TYPED DATA
}
void Provider::P_UERreq() { 	// PS primitive	P-U-EXCEPTION-REPORT request
}
void Provider::S_ACTDind() {	// PS primitive S-ACTIVITY-DISCARD indication
}

ReturnCode Provider::providerException(const statemap::SmcException& exception) const {
	int reason = 0;
	pb_logger->error(exception.what());
	if ( typeid(exception)==typeid(statemap::TransitionUndefinedException)) {
		const statemap::TransitionUndefinedException& tue = static_cast<const statemap::TransitionUndefinedException&>(exception);
		transitionUndefinedException(tue);
	}
	string message = exception.what();
#if 0
	pb_logger->SPAbortIndication(reason, 0);
	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
	tsap().TDisconnectRequest(reason, pb_called);
#endif
	return NOTOK;
}
ReturnCode Provider::serviceException(const statemap::SmcException& exception) const {
	int reason = 0;
	pb_logger->error(exception.what());
	if ( typeid(exception)==typeid(statemap::TransitionUndefinedException)) {
		const statemap::TransitionUndefinedException& tue = static_cast<const statemap::TransitionUndefinedException&>(exception);
		transitionUndefinedException(tue);
	}
	string message = exception.what();
#if 0
	pb_logger->SPAbortIndication(reason, 0);
	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
#endif
	return NOTOK;
}
ReturnCode Provider::userException(const statemap::SmcException& exception) const {
	pb_logger->error(exception.what());
	if ( typeid(exception)==typeid(statemap::TransitionUndefinedException)) {
		const statemap::TransitionUndefinedException& tue = static_cast<const statemap::TransitionUndefinedException&>(exception);
		transitionUndefinedException(tue);
	}
	string message = exception.what();
#if 0
	pb_logger->SPAbortIndication(reason, 0);
	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
#endif
	return NOTDONE;
}
void Provider::transitionUndefinedException(const statemap::TransitionUndefinedException& tue) const {
	string error("error in ");
	if (tue.getState() != nullptr) {
		error += "state ";
		error += tue.getState();
	}
	if (tue.getTransition() != nullptr) {
		error += " on ";
		error += tue.getTransition();
	}
	pb_logger->error(error);
}
}
}
}
