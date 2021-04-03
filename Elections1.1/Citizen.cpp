#include "General.h"
#include "Citizen.h"


//c'tor
Citizen::Citizen(string& i_FirstName, string& i_LastName, string& i_ID, int i_YearOfBirth, VotingRegion& i_VotingRegion, int i_Quarantine) noexcept(false)
{
	if (!setFirstName(i_FirstName))
	{
		throw FirstName_Error;
		//cout << "Invalid Input, please enter correct firstname " << endl;
		//cin >> i_FirstName;
	}
	if (!setLastName(i_LastName))
	{
		throw LastName_Error;
		//cout << "Invalid Input, please enter correct lastname " << endl;
		//cin >> i_LastName;
	}
	if (!setID(i_ID))
	{
		throw ID_Error;
		//cout << "Invalid Input, Please enter correct ID. " << endl;
		//cout <<	"**Notice** I.D consist of exactly 9 figures, when each figure is between 0 to 9.  " << endl;
		//cin >> i_ID;
	}
	if (!setYearOfBirth(i_YearOfBirth))
	{
		throw YearOfBirth_Error;
		//cout << "Invalid Year of Birth, Please enter correctly.  " << endl;
		//cin >> i_YearOfBirth;
	}
	setQuarantineStatus(i_Quarantine);
	setVotingRegion(&i_VotingRegion);
}

//d'tor
Citizen::~Citizen()
{
	
}

//getters
const string& Citizen::getFirstName()	const
{
	return m_FirstName;
}

const string& Citizen::getLastName()	const
{
	return m_LastName;
}

const string& Citizen::getID()	const
{
	return m_ID;
}

int Citizen::getYearOfBirth()	const
{
	return m_YearOfBirth;
}

VotingRegion* Citizen::getVotingRegion()
{
	return m_VotingRegion;
}

const int Citizen::getQuarantineStatus()
{
	
if (m_Quarantine == 0)
	{
		cout << "Not in Quarantine!" << endl;
	}
	else
		cout << "NOTICE! In Quarantine" << endl;
	return m_Quarantine;
}

const int Citizen::getQuarantineStatusToFile()
{
	return m_Quarantine;
}

//setters
bool Citizen::setFirstName(string& i_FirstName)
{
	int nameSz = i_FirstName.size();
	for (int i = 0; i < nameSz; i++)
	{//checks each and every char in the string, to see if its a "valid" char.
		if ((i_FirstName[i] < 'a' || i_FirstName[i] > 'z') && (i_FirstName[i] < 'A' || i_FirstName[i] > 'Z'))
		{
			return false;
		}
	}
	m_FirstName = i_FirstName;
	return true;
}

bool Citizen::setLastName(string& i_LastName)
{
	int lastNameSz = i_LastName.size();
	for (int i = 0; i < lastNameSz; i++)
	{//checks each and every char in the string, to see if its a "valid" char.
		if ((i_LastName[i] < 'a' || i_LastName[i] > 'z') && (i_LastName[i] < 'A' || i_LastName[i] > 'Z'))
		{
			return false;
		}
	}
	m_LastName = i_LastName;
	return true;
}

bool Citizen::setID(string& i_ID)
{
	if (i_ID.size() != 9) //if id input is less/more than 9 figures, immeddiatly returns false.
	{
		return false;
	}
	else {//if the string contains excatly 9 char, checks each and every char in the string to make sure its a number between 0 to 9.
		for (int i = 0; i < 9; i++)
		{
			if (i_ID[i]<'0' || i_ID[i]>'9')
			{
				return false;
			}
		}
		m_ID = i_ID;
		return true;
	}
}

bool Citizen::setYearOfBirth(int i_YearOfBirth)
{                                                                                                                   //   2020             18
	if (i_YearOfBirth < 1880 || i_YearOfBirth > (sr_YEAR - sr_LegalAgeToVote))//valid years are only between 1880 to (CurrentYear - LegalAgeToVote) (only citizens above 18 are allowed to vote).
	{
		return false;
	}
	else
	{
		m_YearOfBirth = i_YearOfBirth;
		return true;
	}
}

bool Citizen::setVotingRegion(VotingRegion* i_VotingRegion)
{
	m_VotingRegion = i_VotingRegion;
	return true;
}

bool Citizen::setQuarantineStatus(int i_Quarantine)
{
	m_Quarantine = i_Quarantine;
	return true;
}

//other
ostream& operator <<(ostream& os,Citizen& citizen)
{
	
	os << "Full-Name: " << citizen.getLastName();
	os << " ," << citizen.getFirstName();
	os << "  Age: " << (sr_YEAR - citizen.getYearOfBirth());
	os << " ,Covid-19 Status: ";
	citizen.getQuarantineStatus();
	return os;
}
