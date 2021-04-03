#ifndef __USER_INTERFACE_H
#define __USER_INTERFACE_H

#include "General.h"
#include "Citizen.h"
#include "System.h"
#include "PoliticalParty.h"
#include "Date.h"


int findPartyResults(VotingRegion& v, string& PartyToCmp);
PoliticalParty* addPoliticalParty();
VotingRegion* addVotingRegion(int index);
void ViewElectionResults(System& _System);
void addPartyCandidate(System& _System);
Citizen* addCitizen(System& _System);
void myCalloc(int* arr, int size);
void Vote(System& _System);
Address& SetAddress();
Date& SetDate();
void showMenu();
//menu functions
bool case_1(System& _System);
bool case_2(System& _System);
bool case_3(System& _System);
void case_4(System& _System);
void case_5(System& _System);
void case_6(System& _System);
void case_7(System& _System);
void case_8(System& _System);
void case_9(System& _System);
void case_10(System& _System);
void case_11(System& _System);
//Hard-Coded functions.
void addPlayingRegions(System& _System);
void addPlayingParties(System& _System);
void addPlayingCitizens(System& _System);



#endif // !__USER_INTERFACE_H

