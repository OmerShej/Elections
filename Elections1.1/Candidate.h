#ifndef __CANDIDATE__H
#define __CANDIDATE__H
#include "Citizen.h"

class PoliticalParty;


class Candidate: virtual public Citizen
{
private:
	PoliticalParty* m_CandidatePoliticalParty; 

public:
	//constructors
	Candidate(string& i_FirstName, string& i_LastName, string& i_ID, int i_YearOfBirth, VotingRegion& i_VotingRegion, int i_Quarantine, PoliticalParty* i_PoliticalParty);
	Candidate(Candidate& other) = delete; // cannot copy candidates
	virtual ~Candidate();
	//setters
	bool setPoliticalParty(PoliticalParty* i_CandidatePoliticalParty);
	//getters
	const PoliticalParty* getPoliticalParty();
	//other
	friend bool operator ==(const Candidate &a, const Candidate &b);
};



#endif // !__CANDIDATE__H

