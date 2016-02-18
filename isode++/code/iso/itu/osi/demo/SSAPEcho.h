#ifndef	ALS_DEMO_SSAPECHO_H_
#define ALS_DEMO_SSAPECHO_H_

#include "Poco/Semaphore.h"
using Poco::Semaphore;

#include "Echo.h"


	class SSAPEcho : public Echo {
	protected:
	boolean				timer = false;
	Requirement			requirements;
	int					owned = 0;
	int					avail = 0;
	SSN					ssn;
	SSN					firstInitialSSN;
	SSN					secondInitialSSN;
	int					reason;
	int					extension;
	int					cc;
	char*				data;
	ActivityId			id;// activityId;
	Semaphore			semaphore;
	bool				trace = true;
	int					status = 0;

	SSAPEcho() : semaphore(0, 1) {}
	};
#endif

	