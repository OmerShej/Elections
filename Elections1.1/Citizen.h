#ifndef __CITIZEN_H
#define __CITIZEN_H
#include "General.h"


class VotingRegion;

class Citizen
{
protected:
	string m_FirstName;
	string m_LastName;
	string m_ID;
	int m_YearOfBirth;
	int m_Quarantine;
	VotingRegion* m_VotingRegion; 
public:
	//constructors
	Citizen(string& i_FirstName, string& i_LastName, string& i_ID, int i_YearOfBirth, VotingRegion& i_VotingRegion, int i_Quarantine) noexcept(false);
	Citizen(Citizen& other) = delete; //cannot copy citizens
	virtual ~Citizen();
	//others
	friend ostream& operator <<(ostream& os, Citizen& citizen);
	//getters
	const string& getFirstName() const;
	const string& getLastName()	const;
	const string& getID() const;
	int getYearOfBirth() const;
	VotingRegion* getVotingRegion();
	const int getQuarantineStatus();
	const int getQuarantineStatusToFile();
	//setters
	bool setFirstName(string& i_FirstName);
	bool setLastName(string& i_LastName);
	bool setID(string& i_ID);
	bool setYearOfBirth(int i_YearOfBirth);
	bool setVotingRegion(VotingRegion* i_VotingRegion);
	bool setQuarantineStatus(int i_Quarantine);
};

#endif //__CITIZEN_H
