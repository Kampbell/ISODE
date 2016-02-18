//
// The contents of this file are subject to the Mozilla Public
// License Version 1.1 (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy of
// the License at http://www.mozilla.org/MPL/
// 
// Software distributed under the License is distributed on an "AS
// IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
// implied. See the License for the specific language governing
// rights and limitations under the License.
// 
// The Original Code is State Machine Compiler (SMC).
// 
// The Initial Developer of the Original Code is Charles W. Rapp.
// Portions created by Charles W. Rapp are
// Copyright (C) 2000 - 2003 Charles W. Rapp.
// All Rights Reserved.
// 
// Contributor(s): 
//
// Function
//	Main
//
// Description
//  This routine starts the finite state machine running.
//

#include "stoplight.h"
#include <stdlib.h>
#include <signal.h>

using namespace std;

#ifndef WIN32
#ifndef SA_NOMASK
#define SA_NOMASK 0
#endif
#endif

using namespace cpp_ex4;

Stoplight *TheLight;
int KeepGoing = 1;

int YellowTimer = 2;    // Yellow lights last 2 seconds.
int NSGreenTimer = 8;    // North-south green lasts 8 seconds.
int EWGreenTimer = 

#ifdef WIN32
DWORD Gtimeout; // Number of milliseconds until the next timeout.
#endif

int main()
{
    void SigintHandler(int);

#ifdef WIN32
    // Windows kinda supports signals.
    (void) signal(SIGINT, SigintHandler);
#else
    struct sigaction signalAction;

    void SigalrmHandler(int);

    signalAction.sa_handler = SigintHandler;
#if defined(__hpux) || defined (__linux__)
    sigemptyset(&signalAction.sa_mask);
#if defined(__linux__)
    signalAction.sa_restorer = NULL;
#endif
#endif
    signalAction.sa_flags = SA_NOMASK;
    if (sigaction(SIGINT, &signalAction, (struct sigaction *) NULL) != 0)
    {
        cerr << "Unable to set SIGINT handling function." << endl;
        exit(1);
    }

    signalAction.sa_handler = SigalrmHandler;
#if defined(__hpux) || defined(__linux__)
    sigemptyset(&signalAction.sa_mask);
#if defined(__linux__)
    signalAction.sa_restorer = NULL;
#endif
#endif
    signalAction.sa_flags = SA_NOMASK;
    if (sigaction(SIGALRM, &signalAction, (struct sigaction *) NULL) != 0)
    {
        cerr << "Unable to set SIGALRM handling function." << endl;
        exit(1);
    }
#endif

    TheLight = Stoplight::Initialize(EAST_WEST);
    if (TheLight == (Stoplight *) NULL)
    {
        cerr << "Failed to create stoplight object." << endl;
        exit(1);
    }

    TheLight->start();

#ifdef WIN32
    // Wait for either the app to end or for timers to expire.
    while (KeepGoing)
    {
        // Because this demo only has one timer, just
        // sleep for that specified time period but for
        // only a half a second at a time to allow SIGINTs
        // to be received.
        while (Gtimeout > 0)
        {
            Gtimeout -= 500;
            Sleep(500);
        }

        TheLight->SigTimeout();
    }
#else
    while (KeepGoing)
        ;
#endif

    cout << "Terminating application." << endl;
    return 0;
}

void SigintHandler(int)
{
    KeepGoing = 0;
    return;
}

#ifndef WIN32
void SigalrmHandler(int)
{
    TheLight->SigTimeout();
    return;
}
#endif
