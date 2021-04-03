#include "System.h"
#include "General.h"
#include "Covid19CivilianVotingRegion.h"
#include "Covid19MilitaryVotingRegion.h"
#include "MilitaryVotingRegion.h"
#include "VotingRegion.h"
//c'tor
System::System(Date& i_Date) : m_Date(i_Date)
{
	
} 
//d'tor
System::~System()
{
	for (int i = 0; i < m_CitizensCounter; i++)
	{
		delete m_AllCitizens[i];
	}

	for (int i = 0; i < m_PartiesCounter; i++)
	{
		delete m_AllPoliticalParties[i];
	}

	for (int i = 0; i < m_VotingRegionsCounter; i++)
	{
		delete m_AllVotingRegions[i];
	}

}

//setters
bool System::setElectionsDate(Date& i_Date)
{
	m_Date.setDay(i_Date.getDay());
	m_Date.setMonth(i_Date.getMonth());
	m_Date.setYear(i_Date.getYear());
	return true;
}
//adding citizens to the main citizens arr
bool System::setCitizens(Citizen& i_NewCitizen)
{
	if(&i_NewCitizen == nullptr)
	{
		cout << "Failed adding citizen" << endl;
		return false;
	}
	m_AllCitizens.emplace_back(&i_NewCitizen);
	m_CitizensCounter++;
	return true;
}
//adding PoliticalParties to the main parties arr
bool System::setParties(PoliticalParty& i_NewParty)
{
	if (&i_NewParty == nullptr)
	{
		cout << "Failed adding political party" << endl;
		return false;
	}
	m_AllPoliticalParties.push_back(&i_NewParty);
	m_PartiesCounter++;
	return true;
}
//adding voting regions(kalpi's) to the main voting region arr
bool System::setVotingRegions(VotingRegion& i_NewRegion)
{

	if(&i_NewRegion == nullptr)
	{
		cout << "Failed setting new voting region" << endl;
		return false;
	}
	m_VotingRegionsCounter++;
	m_AllVotingRegions.push_back(&i_NewRegion);
	return true;
}
//seting voteIndicator to 1 if "Vote" function has been activated, in order to prevent more than 1 voting round.
void System::setVoteIndicator()
{
	m_VoteIndicator++;
}

//getters
const Date&  System::getDate() const
{
	return m_Date;
}

int System::getCitizens() const
{
	return m_CitizensCounter;
}

int System::getParties() const
{
	return m_PartiesCounter;
}

int System::getVotingRegions() const
{
	return m_VotingRegionsCounter;
}

//returns a pointer set to the wanted voting region.
VotingRegion& System::findRegion(int& i_Index) // setting a pointer to a region for each citizen
{
	while (true) {
		if ((i_Index < m_VotingRegionsCounter) && (i_Index >= 0))
		{
			return *m_AllVotingRegions[i_Index];
		}
		else
		{
			cout << endl;
			cout << "****Invalid index, please choose again****" << endl;
			cout << endl;
			showVotingRegions();
			cin >> i_Index;
			cin.ignore();
		}
	}
}
//finding want citizen by its index in the citizens array.
Citizen& System::findCitizen(int i_Index) // finding Citizen.
{
	while (true) {
		if ((i_Index < m_CitizensCounter) && (i_Index >= 0))
		{
			return *m_AllCitizens[i_Index];
		}
		else
		{
			cout << endl;
			cout << "****Invalid index, please choose again****" << endl;
			cout << endl;
			showCitizens();
			cin >> i_Index;
			i_Index--;
		}
	}

}
//returns a pointer, which points to the wanted political party.
PoliticalParty& System::findPoliticalParty(int i_Index) // finding political party.
{
	while (true) {
		if ((i_Index < m_PartiesCounter) && (i_Index >= 0))
		{
			return *m_AllPoliticalParties[i_Index];
		}
		else
		{
			cout << endl;
			cout << "****Invalid index, please choose again****" << endl;
			cout << endl;
			showPoliticalParties();
			cin >> i_Index;
			i_Index--;
		}
	}
}

int System::getVoteIndicator() const
{
	return m_VoteIndicator;
}

//other
//displays all voting regions
void System::showVotingRegions() const
{
	for (int i = 0; i < m_VotingRegionsCounter; i++) // printing each kalpi
	{
		cout << i << ") - ";
		cout << *m_AllVotingRegions[i];
		
	}
}

void System::showPoliticalParties() const
{
	for (int i = 0; i < m_PartiesCounter; i++)
		// printing each party
	{
		cout << "Party Num " << i+1 << " is ";
		cout << *m_AllPoliticalParties[i];
		cout << endl;
	}
}
//printing citizens info one by one.
void System::showCitizens() const
{
	for (int i = 0; i < this->m_CitizensCounter; i++) // printing each citizen
	{
		cout << i + 1 << ") " << *m_AllCitizens[i];
	}
	
}

bool System::checkVotingRegion(VotingRegion* i_VotingRegion, int Age, int Quarantine)
{
	
	if (Quarantine == 0 && Age > 21 && i_VotingRegion->getType() == 1)
	{
		return true;
	}
	else if (Quarantine == 1 && Age > 21 && i_VotingRegion->getType() == 2)
	{
		return true;
	}
	else if (Quarantine == 0 && Age <= 21 && i_VotingRegion->getType() == 3)
	{
		return true;
	}
	else if (Quarantine == 1 && Age <= 21 && i_VotingRegion->getType() == 4)
	{
		return true;
	}
	else
		return false;
}


void System::saveCitizens()
{
	vector<Citizen*>::iterator itr = m_AllCitizens.begin();
	vector<Citizen*>::iterator itrEnd = m_AllCitizens.end();

	ofstream outFile("Citizens.txt", ios::trunc);
	for (; itr != itrEnd; itr++)
	{
		if (typeid(*(*itr)).name() + 6 == "Citizen")
		{
			outFile << typeid(*(*itr)).name() + 6 << endl;
			outFile << (*itr)->getFirstName() << endl;
			outFile << (*itr)->getLastName() << endl;
			outFile << (*itr)->getID() << endl;
			outFile << (*itr)->getYearOfBirth() << endl;
			outFile << (*itr)->getVotingRegion()->getSerialNum() << endl;
			outFile << (*itr)->getQuarantineStatusToFile() << endl;
		}
		else
		{
			outFile << typeid(*(*itr)).name() + 6 << endl;
			outFile << (*itr)->getFirstName() << endl;
			outFile << (*itr)->getLastName() << endl;
			outFile << (*itr)->getID() << endl;
			outFile << (*itr)->getYearOfBirth() << endl;
			outFile << (*itr)->getVotingRegion()->getSerialNum() << endl;
			outFile << (*itr)->getQuarantineStatusToFile() << endl;
			outFile << dynamic_cast<Candidate*>(*itr)->getPoliticalParty()->getSerialNum() << endl;
		}

	}
	outFile.close();
}

void System::loadCitizens()
{
	string type;
	string FirstName;
	string LastName;
	string ID;
	Citizen* tempCitizen;
	Candidate* tempCandidte;
	int YearOfBirth;
	int QuarantineStatus;
	int VotingRegionSerialNumber;
	int PoliticalPartySerialNumber;
	VotingRegion* VRegion;
	PoliticalParty* Party;
	ifstream inFile("Citizens.txt", ios::in);
	while (!inFile.eof() && inFile.is_open())
	{
		inFile >> type;
		if (type == "Citizen")
		{
		
			inFile >> FirstName;
			inFile >> LastName;
			inFile >> ID;
			inFile >> YearOfBirth;
			inFile >> VotingRegionSerialNumber;
			inFile >> QuarantineStatus;
			VRegion = &findRegion(VotingRegionSerialNumber);
			tempCitizen = new Citizen(FirstName, LastName, ID, YearOfBirth, *VRegion, QuarantineStatus);
			setCitizens(*tempCitizen);
			findRegion(VotingRegionSerialNumber).setVotingList(tempCitizen);
		}
		else if (type == "Candidate")
		{
			inFile >> FirstName;
			inFile >> LastName;
			inFile >> ID;
			inFile >> YearOfBirth;
			inFile >> VotingRegionSerialNumber;
			inFile >> QuarantineStatus;
			inFile >> PoliticalPartySerialNumber;
			PoliticalPartySerialNumber-=1;
			VRegion = &findRegion(VotingRegionSerialNumber);
			Party = &findPoliticalParty(PoliticalPartySerialNumber);
			tempCandidte = new Candidate(FirstName, LastName, ID, YearOfBirth, *VRegion, QuarantineStatus, Party);
			setCitizens(*tempCandidte);
			VRegion->setVotingList(tempCandidte);
			Party->setCandidate(*tempCandidte);
		}
		
		type = "";
	}
	inFile.close();
}