#include "General.h"
#include "VotingRegion.h"
#include "Array.h"


int VotingRegion::s_SerialNum = 0;
//c'tor
VotingRegion::VotingRegion(Address& i_Address) : m_Address(i_Address)
{
	setSerialNum(s_SerialNum++);
	setNumOfParties(0);
	setAllCitiziens(0);
	m_AllVotesCounter = 0; 
	m_VotingList;
	
}

//d'tor
VotingRegion::~VotingRegion()
{
	int ResultinfoSize = getNumOfParties();
	for (int i = 0; i < ResultinfoSize; i++)
	{
		delete m_ResultsInfo[i];
	}
	delete& m_Address;
}

//setters
bool VotingRegion::setSerialNum(int i_SerialNum)
{
	m_SerialNum = i_SerialNum;
	return true;
}

bool VotingRegion::setAddress(Address& i_Address) 
{
	m_Address.setCity(i_Address.getCity());
	m_Address.setStreet(i_Address.getStreet());
	m_Address.setHouseNumber(i_Address.getHouseNumber());
	return true;
	
}

bool VotingRegion::setAllCitiziens(int i_AllCitizens)
{
	m_AllCitizens += i_AllCitizens;
	return true;
}

bool VotingRegion::setNumOfParties(int i_NumOfParties)
{
	m_NumOfPartiesAdded += i_NumOfParties;
	return true;
}
//updates each voting region's(kalpi) voting list. the list contains which citizens are allowed to vote at the specific kalpi.
bool VotingRegion::setVotingList(Citizen* i_NewCitizen)
{
	if (i_NewCitizen == nullptr)
	{
		cout << "Failed adding to voting-list" << endl;
		return false;
	}
	m_VotingList += i_NewCitizen;
	m_AllVotesCounter++;
	return true;
}
//creating a "voting result" object per political party, the object is being created only if a citizen made a vote for that party.
//if none of the citizens have not voted for a certain party, even though no obj was created the result counter will eventually show zero in that specific kalpi.
bool VotingRegion::setResultInfo(string& i_Party)
{
	
	if (i_Party.size() == 0) // if its the first vote.
	{
		cout << "String cannot be empty, failed adding result info object" << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < m_NumOfPartiesAdded; i++)// searching if a voting result object is already exist for a certain party.
		{
			if (m_ResultsInfo[i]->getParty() == i_Party)// if it does exist, then it just counts another vote.
			{
				m_ResultsInfo[i]->setNumOfVoters(1);
				return true;
			}
		}
		VotingResult* NewResultObj = new VotingResult(i_Party);
		NewResultObj->setNumOfVoters(1);
		m_ResultsInfo.push_back(NewResultObj);
	}
	m_NumOfPartiesAdded++;
	return true;
}

//getters
int VotingRegion::getSerialNum() const
{
	return m_SerialNum;
}

const Address& VotingRegion::getAddress() const
{
	return m_Address;
}

int VotingRegion::getAllCitiziens() const
{
	return m_AllCitizens;
}

int VotingRegion::getAllVotesCounter() const
{
	return m_AllVotesCounter;
}

int VotingRegion::getNumOfParties() const
{
	return m_NumOfPartiesAdded;
}

vector<VotingResult*> VotingRegion::getResultList() const
{
	return m_ResultsInfo;
}

//other
void VotingRegion::show() const
{
	cout << "Voting Region Serial Num: " << m_SerialNum << "  ";
	cout << m_Address;
}

ostream& operator <<(ostream& os, VotingRegion& os_VotingRegion)
{
	os << "Voting Region Serial Num: " << os_VotingRegion.getSerialNum() << " ";
	os << os_VotingRegion.getAddress();
	os << " ,Type: " << (typeid(os_VotingRegion).name() + 6);
	os << endl;
	for (int i = 0; i < os_VotingRegion.getAllCitiziens(); i++) {
		os << os_VotingRegion.m_VotingList[i];
	}
	return os;
}

void VotingRegion::operator+=(Citizen& i_NewCitizen)	
{
	this->setVotingList(&i_NewCitizen);

}

int VotingRegion::getType() const
{
	return 1;
}