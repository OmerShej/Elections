#include "General.h"
#include "PoliticalParty.h"
const string os_Factions[] = { "Right", "Left", "Center" };

int PoliticalParty::s_SerialCounter = 1;
//c'tor
PoliticalParty::PoliticalParty(string& i_Name, eFaction i_Faction, Date& i_Date) : m_Date(i_Date)
{
	while (!setName(i_Name))
	{
		cout << "Invalid name, please enter party's name again " << endl;
		cin >> i_Name;
	}
	while (!setPoliticalFaction(i_Faction))
	{
		int FactionIndex;
		cout << "Invalid Faction, please try again " << endl;
		cout << "press 1 for Right" << endl;
		cout << "press 2 for Left" << endl;
		cout << "press 3 for Center" << endl;
		cin >> FactionIndex;
		i_Faction = (eFaction)(FactionIndex - 1);
	}
	setSerialNum(s_SerialCounter++);
	
}
//d'tor
PoliticalParty::~PoliticalParty()
{
	
	delete& m_Date;
	
}
//setters
bool PoliticalParty::setSerialNum(int i_SerialNum)
{
	this->m_PartySerialNum = i_SerialNum;
	return true;
}

bool PoliticalParty::setName(string& i_Name)
{
	int partySz = i_Name.size();
	for (int i = 0; i < partySz; i++)
	{
		if ((i_Name[i] < 'a' || i_Name[i] > 'z') && (i_Name[i] < 'A' || i_Name[i] > 'Z') && (i_Name[i] < ' ' || i_Name[i] > ' ') && (i_Name[i] < '-' || i_Name[i] > '-'))
		{
			return false;
		}
	}
	m_Name = i_Name;
	return true;
}

bool PoliticalParty::setPoliticalFaction(eFaction i_Faction)
{
	if(i_Faction < 0 || i_Faction > 2)
	{
		return false;
	}
	m_Faction = i_Faction;
	return true;
}

bool PoliticalParty::setDate(Date& i_Date)
{
	
	m_Date.setDay(i_Date.getDay());
	m_Date.setMonth(i_Date.getMonth());
	m_Date.setYear(i_Date.getYear());
	return true;
}

bool PoliticalParty::setNumOfCandidates(int i_CandidatesCounter)
{
	
	m_CandidatesCounter = i_CandidatesCounter;
	return true;
}
//adds a new candidate to specific political party
bool PoliticalParty::setCandidate(Candidate& i_Candidate)
{
	if (&i_Candidate == nullptr)
	{
		cout << "Failed adding candidate." << endl;
		return false;
	}
	m_PartyCandidates.push_back(&i_Candidate);
	m_CandidatesCounter++;
	cout << " Candidate has been added successfully!" << endl;
	return true;
}

//getters
const int PoliticalParty::getSerialNum() const
{
	return m_PartySerialNum;
}

const string& PoliticalParty::getName() const
{
	return m_Name;
}

const Date& PoliticalParty::getDate() const
{
	return m_Date;
}

int PoliticalParty::getNumOfCandidates() const
{
	return m_CandidatesCounter;
}

eFaction PoliticalParty::getPoliticalFaction() const
{
	return m_Faction;
}

//other
void PoliticalParty::showCandidates() const
{
	for (int i = 0; i < m_CandidatesCounter; i++)
	{
		cout << m_PartyCandidates[i]->getFirstName() << ", " << m_PartyCandidates[i]->getLastName() << " - " << m_Name << endl;
	}
}

ostream& operator <<(ostream& os, PoliticalParty& os_PoliticalParty)
{
	os << os_PoliticalParty.getName() <<" ,Party's Faction is: "<<os_Factions[os_PoliticalParty.getPoliticalFaction()]  <<" ,Party's Serial Number is: " << os_PoliticalParty.getSerialNum();
	os << " ,Num Of Candidates is : " << os_PoliticalParty.getNumOfCandidates() << ". " << endl;
	os << "Party's Candidates : ";
	for (int i = 0; i < os_PoliticalParty.getNumOfCandidates(); i++)
	{
		os << os_PoliticalParty.m_PartyCandidates[i]->getFirstName()<< " " << os_PoliticalParty.m_PartyCandidates[i]->getLastName() << ", ";
	}
	os << '\b';
	os << '\b';
	os << ".";
	return os;
}

bool PoliticalParty::operator>(const PoliticalParty& Party1) const
{
	if (this->getNumOfCandidates() > Party1.getNumOfCandidates())
	{
		return true;
	}
	else
		return false;
}