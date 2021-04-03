#ifndef __VOTINGRESULT_H
#define __VOTINGRESULT_H
#include "General.h"

class VotingResult
{
private:
	string m_Party;
	int m_NumOfVoters;

public:
	//constructors
	VotingResult(string& i_Party);
	VotingResult(VotingResult& other) = delete; //cannot copy result
	~VotingResult();
	//setters
	bool setPoliticalParty(string& i_Party);
	bool setNumOfVoters(int i_NumOfVoters = 0);
	//getters
	const string& getParty() const;
	int getNumOfVoters() const; 
};

#endif //__VOTINGRESULT_H
