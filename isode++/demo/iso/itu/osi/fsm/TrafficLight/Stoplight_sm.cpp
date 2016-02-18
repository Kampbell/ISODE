#include "stoplightdefs.h"
#include "stoplight.h"
#include "Stoplight_sm.h"
using namespace statemap;
namespace cpp_ex4 {
	// FSM Map constructor.
	StopMap::StopMap() :
		EastWestGreen("EastWestGreen", 0),
		EastWestYellow("EastWestYellow", 1),
		NorthSouthGreen("NorthSouthGreen", 2),
		NorthSouthYellow("NorthSouthYellow", 3)
	{}
	
	// Class state -----------------------------------
	void StoplightState::Timeout(StoplightContext<Stoplight>& context) {
	     Default(context);
	}
	void StoplightState::Timeout(StoplightContext<Stoplight>& context, LightColors t) {
	     Default(context);
	}
	void StoplightState::Default(StoplightContext<Stoplight>& context) {
	    throw TransitionUndefinedException(context.getState().getName(), context.getTransition());
	    return;
	}
	void StopMap_EastWestGreen::Entry(StoplightContext<Stoplight>& context) {
	    Stoplight& ctxt = context.getOwner();
		ctxt.setTimer(Stoplight::EWGreenTimer);
	}
	
	// ----------------------------------------------------
	void StopMap_EastWestGreen::Timeout(StoplightContext<Stoplight>& context, LightColors t) {
		Stoplight& ctxt = context.getOwner();
		
		if ((t==RED)) {
			(context.getState()).Exit(context);
			context.setState(context.EastWestYellow);
			(context.getState()).Entry(context);
			ctxt.TurnLight(EWLIGHT, YELLOW);
		} else 
		{
		     StopMap_Default::Timeout(context, t);
		}
		return;
	};
	void StopMap_EastWestYellow::Entry(StoplightContext<Stoplight>& context) {
	    Stoplight& ctxt = context.getOwner();
		ctxt.setTimer(Stoplight::YellowTimer);
	}
	
	// ----------------------------------------------------
	void StopMap_EastWestYellow::Timeout(StoplightContext<Stoplight>& context) {
		Stoplight& ctxt = context.getOwner();
		
		(context.getState()).Exit(context);
		context.setState(context.NorthSouthGreen);
		(context.getState()).Entry(context);
		ctxt.TurnLight(EWLIGHT, RED);
		ctxt.TurnLight(NSLIGHT, GREEN);
		return;
	};
	void StopMap_NorthSouthGreen::Entry(StoplightContext<Stoplight>& context) {
	    Stoplight& ctxt = context.getOwner();
		ctxt.setTimer(Stoplight::NSGreenTimer);
	}
	
	// ----------------------------------------------------
	void StopMap_NorthSouthGreen::Timeout(StoplightContext<Stoplight>& context) {
		Stoplight& ctxt = context.getOwner();
		
		(context.getState()).Exit(context);
		context.setState(context.NorthSouthYellow);
		(context.getState()).Entry(context);
		ctxt.TurnLight(NSLIGHT, YELLOW);
		return;
	};
	void StopMap_NorthSouthYellow::Entry(StoplightContext<Stoplight>& context) {
	    Stoplight& ctxt = context.getOwner();
		ctxt.setTimer(Stoplight::YellowTimer);
	}
	
	// ----------------------------------------------------
	void StopMap_NorthSouthYellow::Timeout(StoplightContext<Stoplight>& context) {
		Stoplight& ctxt = context.getOwner();
		
		(context.getState()).Exit(context);
		context.setState(context.EastWestGreen);
		(context.getState()).Entry(context);
		ctxt.TurnLight(NSLIGHT, RED);
		ctxt.TurnLight(EWLIGHT, GREEN);
		return;
	};
}
