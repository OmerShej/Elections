#include "Candidate.h"


//c'tor
Candidate::Candidate(string& i_FirstName, string& i_LastName, string& i_ID, int i_YearOfBirth, VotingRegion& i_VotingRegion, int i_Quarantine, PoliticalParty* i_PoliticalParty)
	: Citizen(i_FirstName, i_LastName, i_ID, i_YearOfBirth, i_VotingRegion, i_Quarantine)
{
	setPoliticalParty(i_PoliticalParty);
}
//d'tor
Candidate::~Candidate()
{
	
}
//setters
bool Candidate::setPoliticalParty(PoliticalParty* i_CandidatePoliticalParty)
{
	if (i_CandidatePoliticalParty != nullptr)
	{
		m_CandidatePoliticalParty = i_CandidatePoliticalParty;
		return true;
	}
	return false;
}
//getters
const PoliticalParty* Candidate::getPoliticalParty()
{
	return m_CandidatePoliticalParty;
}
//operators
bool operator==(const Candidate& a, const Candidate& b)
{
	if (&a == &b) {
		return true;
	}
	else
		return false;
}
