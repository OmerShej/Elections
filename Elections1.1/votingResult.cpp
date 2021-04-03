#include "votingResult.h"
#include "General.h"


//c'tor
VotingResult::VotingResult(string& i_Party)
{
	setPoliticalParty(i_Party);
	m_NumOfVoters = 0;
}
//d'tor
VotingResult::~VotingResult()
{
	
}

//setters
bool VotingResult::setPoliticalParty(string& i_Party)
{
	m_Party = i_Party;
	return true;
}
//votes counter.
bool VotingResult::setNumOfVoters(int i_NumOfVoters)
{
	m_NumOfVoters += i_NumOfVoters;
	return true;
}

//getters
const string& VotingResult::getParty() const
{
	return m_Party;
}

int VotingResult::getNumOfVoters() const
{
	return m_NumOfVoters;
}
