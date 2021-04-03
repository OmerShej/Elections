#ifndef __POLITICALPARTY_H
#define __POLITICALPARTY_H
#include "General.h"
#include "Date.h"
#include "Candidate.h"
#include <vector>
using namespace std;


class PoliticalParty
{
private:
	static int s_SerialCounter; 
	int m_PartySerialNum = 0;
	string m_Name;
	eFaction m_Faction;
	Date& m_Date;
	int m_CandidatesCounter = 0;
	vector<Candidate*> m_PartyCandidates; // parties candidates arr.
public:
	//constructors
	PoliticalParty(string& i_Name, eFaction i_Faction, Date& i_Date);
	PoliticalParty(PoliticalParty& other) = delete; //cannot copy party's
	~PoliticalParty();

	
	//setters
	bool setNumOfCandidates(int i_CandidatesCounter);
	bool setName(string& i_Name);
	bool setPoliticalFaction(eFaction i_Faction);
	bool setDate(Date& i_Date);
	bool setCandidate(Candidate& i_Candidate);
	bool setSerialNum(int i_SerialNum);
	//getters
	const string& getName() const;
	const int getSerialNum() const;
	eFaction getPoliticalFaction() const;
	const Date& getDate() const;
	int getNumOfCandidates() const;
	//others
	void showCandidates() const;
	friend ostream& operator <<(ostream& os, PoliticalParty& os_PoliticalParty);
	bool operator>(const PoliticalParty& Party1) const;

};

#endif //__POLITICALPARTY_H
