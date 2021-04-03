#ifndef __VOTINGREGION_H
#define __VOTINGREGION_H
#include "Address.h"
#include "votingResult.h"
#include "General.h"
#include <iostream>
#include "Array.h"
#include <vector>
class Citizen;

class VotingRegion // Kalpi.
{
protected:
	static int s_SerialNum;
	int m_SerialNum = 0;
	Address& m_Address;
	Array<Citizen*> m_VotingList; // contains a pointer to each citizens which choose this "kalpi" as his voting region.
	int m_AllCitizens; // total citizens for caculating kalpi's voters precent
	int m_AllVotesCounter; // voting list logical size (amount of total voters for this voting-region)
	vector<VotingResult*> m_ResultsInfo; // list that contains only parties which citizens voted for.
	int m_NumOfPartiesAdded; // result info logical size
public:
	//constructors
	VotingRegion(Address& i_Address);
	VotingRegion(VotingRegion& other) = delete; // cannot copy voting-regions
	virtual ~VotingRegion();
	//setters
	bool setSerialNum(int i_SerialNum = 0);
	bool setAddress(Address& i_Address);
	bool setAllCitiziens(int i_AllCitizens = 0);
	bool setNumOfParties(int i_NumOfParties = 0);
	bool setVotingList(Citizen* i_NewCitizen);
	bool setResultInfo(string& i_Party);
	//getters
	int getSerialNum() const;
	const Address& getAddress() const;
	int getAllCitiziens() const;
	int getAllVotesCounter() const;
	int getNumOfParties() const;
	vector<VotingResult*> getResultList() const;
	virtual int getType() const;
	//other
	void show() const;
	friend ostream& operator <<(ostream& os, VotingRegion &os_VotingRegion);
	void operator+=(Citizen& newCitizen); // adds a new citizen to voting-list.
};

#endif //__VOTINGREGION_H
