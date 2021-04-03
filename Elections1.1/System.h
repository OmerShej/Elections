#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "General.h"
#include "Date.h"
#include "Citizen.h"
#include "PoliticalParty.h"
#include "VotingRegion.h"
#include <vector>

class System
{
private:
	Date& m_Date;
	vector<Citizen*> m_AllCitizens; // contains all of the citizens which have been added to the system.
	vector<PoliticalParty*> m_AllPoliticalParties; // contains all of the political parties which have been added to the system.
	vector<VotingRegion*> m_AllVotingRegions; // contains all of the voting regions(kalpis) which have been added to the system.
	int m_CitizensCounter = 0; // citizens arr logical size
	int m_PartiesCounter = 0; // political party arr logical size
	int m_VotingRegionsCounter = 0; // voting regions arr(kalpi's) logical size
	int m_VoteIndicator = 0;
public:
	//constructors
	System(Date& Date);
	System(System& other) = delete; // cannot copy election system.
	~System();
	//setters
	bool setElectionsDate(Date& i_Date);
	bool setCitizens(Citizen& i_NewCitizen);
	bool setParties(PoliticalParty& i_NewParty);
	bool setVotingRegions(VotingRegion& i_NewRegion);
	void setVoteIndicator();
	//getters
	VotingRegion& findRegion(int& i_Index);
	PoliticalParty& findPoliticalParty(int i_Index);
	Citizen& findCitizen(int i_Index);
	const Date& getDate() const;
	int getCitizens() const;
	int getParties() const;
	int getVotingRegions() const;
	int getVoteIndicator() const;
	//others
	void showVotingRegions() const;
	bool checkVotingRegion(VotingRegion* i_VotingRegion, int Age, int Quarantine);
	void showPoliticalParties() const;
	void showCitizens() const;
	void saveCitizens();
	void loadCitizens();
};
	

#endif // __SYSTEM_H

