#include "General.h"
#include "Candidate.h"
#include "Covid19CivilianVotingRegion.h"
#include "Covid19MilitaryVotingRegion.h"
#include "MilitaryVotingRegion.h"
#include "UserInterFace.h"



//shows the menu options 
void showMenu()
{
	cout << endl;
	cout << "1 - to add a voting region" << endl;
	cout << "2 - to add a citizen" << endl;
	cout << "3 - to add a political party" << endl;
	cout << "4 - to add a party candidate" << endl;
	cout << "5 - to view all of the voting regions" << endl;
	cout << "6 - to view all of the citizens" << endl;
	cout << "7 - to view all of the political parties" << endl;
	cout << "8 - to vote" << endl;
	cout << "9 - to view election results" << endl;
	cout << "10 - to compare amount of candidates between 2 parties" << endl;
	cout << "11 - to exit" << endl;
	cout << endl;
}
//obtain party's voting result in a certain region.
int findPartyResults(VotingRegion& v, const string& PartyToCmp)
{
	for (int i = 0; i < v.getNumOfParties(); i++)
	{
		if (v.getResultList()[i]->getParty() == PartyToCmp)
		{
			return v.getResultList()[i]->getNumOfVoters();
		}
	}
	return 0;
}
//seting and adding a new political party to the main party's arr.
PoliticalParty* addPoliticalParty()
{

	string name;
	int FactionIndex;
	cout << "Enter Politial Party's Name " << endl;
	cin.ignore();
	getline(std::cin, name);
	cout << "Set Party's Political Faction" << endl;
	cout << "press 1 for Right" << endl;
	cout << "press 2 for Left" << endl;
	cout << "press 3 for Center" << endl;
	cin >> FactionIndex;
	PoliticalParty *newPoliticalParty = new PoliticalParty(name, eFaction(FactionIndex - 1), SetDate());
	return newPoliticalParty;
}
//seting and adding a new voting region(kalpi) to the main votingRegion's arr.
VotingRegion* addVotingRegion(int index)
{

	if (index == 1)
	{
		VotingRegion* newRegion = new VotingRegion(SetAddress());
		return newRegion;
	}
	else if (index == 2)
	{
		Covid19CivilianVotingRegion* newRegion = new Covid19CivilianVotingRegion(SetAddress());
		return newRegion;
	}
	else if (index == 3)
	{
		MilitaryVotingRegion* newRegion = new MilitaryVotingRegion(SetAddress());
		return newRegion;
	}
	else
	{
		Covid19MilitaryVotingRegion* newRegion = new Covid19MilitaryVotingRegion(SetAddress());
		return newRegion;
	}
}
//adding a new candidate for one of the parties.
void addPartyCandidate(System& _System)
{
	
	int PartyIndex = 0;
	int CitizenIndex = 0;
	string FirstName;
	string LastName;
	string ID;
	int YearOfBirth;
	int index;
	int QuarantineIndex;
	cout << "Enter Candidate's first name " << endl;
	cin >> FirstName;
	cout << "Enter Candidate's last name " << endl;
	cin >> LastName;
	cout << "Enter Candidate's I.D Number " << endl;
	cin >> ID;
	cout << "Enter Candidate's year of birth " << endl;
	cin >> YearOfBirth;
	cout << "Health Decleration!, Enter 1 if Candidate is in Quarantine, otherwise press 0 " << endl;
	cin >> QuarantineIndex;
	cout << "choose Voting Region from the next list" << endl;
	_System.showVotingRegions();
	cin >> index;
	while (!_System.checkVotingRegion(&_System.findRegion(index), sr_YEAR - YearOfBirth, QuarantineIndex))
	{
		cout << "Notice! you've chose a Voting-Region which is incompatible with your Age and Quarantine status!" << endl;
		cout << "Please choose again" << endl;
		_System.showVotingRegions();
		cin >> index;
	}
	cout << endl;
	cout << " from the next list, Please choose a political party for the Candidate to asign in" << endl;
	_System.showPoliticalParties();
	cout << endl;
	cin >> PartyIndex;

	
	Candidate* NewCandidate = new Candidate(FirstName, LastName, ID, YearOfBirth, (_System.findRegion(index)), QuarantineIndex, &_System.findPoliticalParty(PartyIndex - 1));
	_System.findPoliticalParty((PartyIndex - 1)).setCandidate(*NewCandidate);
	_System.setCitizens(*NewCandidate);
	_System.findRegion(index) += *NewCandidate;
}
//seting and adding a new citizen to the main citizen arr.
Citizen* addCitizen(System& _System) // demands update - not finished!!!!!
{
	//bool Flag = false;
	Citizen* NewCitizen;
	string FirstName;
	string LastName;
	string ID;
	int YearOfBirth;
	int index;
	int QuarantineIndex;
	cout << "Enter Citizen's first name " << endl;
	cin >> FirstName;
	cout << "Enter Citizen's last name " << endl;
	cin >> LastName;
	cout << "Enter Citizen's I.D Number " << endl;
	cin >> ID;
	cout << "Enter Citizen's year of birth " << endl;
	cin >> YearOfBirth;
	cout << "Health Decleration!, Enter 1 if citizen is in Quarantine, otherwise press 0 " << endl;
	cin >> QuarantineIndex;
	cout << "choose Voting Region from the next list" << endl;

	_System.showVotingRegions();
	cin >> index;
	while (!_System.checkVotingRegion(&_System.findRegion(index), sr_YEAR - YearOfBirth, QuarantineIndex))
	{
		cout << "Notice! you've chose a Voting-Region which is incompatible with your Age or Quarantine status!" << endl;
		cout << "Please choose again" << endl;
		_System.showVotingRegions();
		cin >> index;
	}
	
	while (true)
	{
		try
		{
			NewCitizen = new Citizen(FirstName, LastName, ID, YearOfBirth, (_System.findRegion(index)), QuarantineIndex);
			//Flag = true;
			_System.findRegion(index) += *NewCitizen;
			return NewCitizen;
		}
		catch (int Value)
		{
			if (Value == FirstName_Error)
			{
				cout << "Invalid Input, please enter correct firstname " << endl;
				cin >> FirstName;
			}
			if (Value == LastName_Error)
			{
				cout << "Invalid Input, please enter correct lastname " << endl;
				cin >> LastName;
			}
			if (Value == ID_Error)
			{
				cout << "Invalid Input, Please enter correct ID. " << endl;
				cout << "**Notice** I.D consist of exactly 9 figures, when each figure is between 0 to 9.  " << endl;
				cin >> ID;
			}
			if (Value == YearOfBirth_Error)
			{
				cout << "Invalid Year of Birth, Please enter correctly.  " << endl;
				cin >> YearOfBirth;
			}
		}
		catch (...)
		{
			cout << "Unknown Error\n";
			cout << "Bye Bye\n";
		}
	}
	//_System.findRegion(index).setVotingList(NewCitizen);
	//_System.findRegion(index) += *NewCitizen;
	//return NewCitizen;
}
//displays all voting result in each kalpi(votingRegion) for a certain party.
void ViewElectionResults(System& _System)
{
	int NumOfParties = _System.getParties();
	int NumOfVotingRegion = _System.getVotingRegions();
	int *ResultArr = new int[NumOfParties];
	myCalloc(ResultArr, NumOfParties);
	int Votes;

	for (int i = 0; i < NumOfParties; i++)
	{
		cout << " Results per kalpi for " << _System.findPoliticalParty(i).getName() << " party, are: " << endl;
		cout << " --------------------------------------------------" << endl;
		for (int j = 0; j < NumOfVotingRegion; j++)
		{
			cout << " Kalpi num " << j << ", located at " << _System.findRegion(j).getAddress().getCity() << ". Votes are: ";
			Votes = findPartyResults(_System.findRegion(j), _System.findPoliticalParty(i).getName());
			cout << Votes;
			ResultArr[i] += Votes;
			cout << endl << endl;
		}
		cout << " ***********************************" << endl;
		cout << "    **************************" << endl;
		cout << " ***********************************" << endl << endl;
	}

	for (int i = 0; i < NumOfParties; i++)
	{
		cout << " Total Votes for the " << _System.findPoliticalParty(i).getName() << ", are: " << ResultArr[i] << endl;
		cout << " Which are " << (((float)ResultArr[i] / (float)_System.getCitizens())*100.0) << "% of the votes." << endl << endl;
		cout << " ***********************************" << endl;
		cout << endl;
	}

}
//initialize function, for int arrys.
void myCalloc(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}
//asks each and every citizen to vote, and sets his voting desicion.
void Vote(System& _System)
{
	
	int flag = 0;
	int PartyIndex = 0;
	int numOfCitizens = _System.getCitizens();
	string Party;
	for (int i = 0; i < numOfCitizens; i++)
	{
		cout << " Hi! " << endl;
		cout << _System.findCitizen(i).getFirstName() << " " << _System.findCitizen(i).getLastName() << endl;
		cout << "Would you like to make a difference?" << endl;
		cout << "For Yes! press 1, otherwise press 2" << endl;
		cin >> flag;
		while( flag < 1 || flag > 2 )
		{
			cout << endl;
			cout << "Invalid input, 1/yes 2/no." << endl;
			cout << endl;
			cin >> flag;
		}
		if (flag == 1)
		{
			cout << "******Choose party's index******" << endl;
			cout << endl;
			_System.showPoliticalParties();
			cin >> PartyIndex;
			Party = _System.findPoliticalParty((PartyIndex - 1)).getName();
			_System.findCitizen(i).getVotingRegion()->setResultInfo(Party);
		}
	}
	cout << "All Citizens have voted!" << endl;
	cout << endl;
}
//set address
Address& SetAddress()
{

	string city;
	string street;
	int houseNumber;
	cout << " Please enter the following details " << endl;
	cout << "Enter city: " << endl;
	cin.ignore();
	getline(std::cin ,city);
	cout << "Enter street: " << endl;
	getline(std::cin, street);
	cout << "Enter building's number: " << endl;
	cin >> houseNumber;
	Address* newAddress= new Address(city, street, houseNumber);
	return *newAddress;

}
//set date
Date& SetDate()
{
	int day;
	int month;
	int year;
	cin.clear();
	cin.ignore();
	
	cout << "Please enter Party's date of initiate" << endl;
	cout << "Day : " << endl;
	cin >> day;
	cout << "Month : " << endl;
	cin >> month;
	cout << "Year : " << endl;
	cin >> year;
	
	Date* newDate = new Date(day, month, year);
	return *newDate;
}


//add voting region
bool case_1(System& _System)
{
	int Index;
	cout << "Hello User, There are 4 types of Voting Regions. Please choose one of the next Options" << endl;
	cout << "1-Civilian-VotingRegion" << endl;
	cout << "2-Quarantined - VotingRegion(Civilian)" << endl;
	cout << "3-Military - VotingRegion" << endl;
	cout << "4-Quarantined - VotingRegion(Military)" << endl;
	cin >> Index;
	_System.setVotingRegions(*addVotingRegion(Index)); // add kalpi
	return true;
}
//add citizen
bool case_2(System& _System)
{
	_System.setCitizens(*addCitizen(_System));
	return true;
}
//add political party
bool case_3(System& _System)
{
	_System.setParties(*addPoliticalParty());
	return true;
}
//add candidate
void case_4(System& _System)
{
	addPartyCandidate(_System);
}
//show voting regions
void case_5(System& _System)
{
	cout << "Displaying all Voting Regions" << endl;
	cout << endl;
	_System.showVotingRegions();
} 
//show citizens
void case_6(System& _System)
{
	cout << "Displaying all Citizens" << endl;
	_System.showCitizens();
}
//show political parties
void case_7(System& _System)
{
	cout << "Displaying all Political Party's" << endl;
	_System.showPoliticalParties();
}
//vote proccess
void case_8(System& _System)
{
	if (_System.getVoteIndicator() == 1)
	{
		cout << endl;
		cout << "***Can-not Activate Vote Function more than once***" << endl;
		cout << endl;
		return;
	}
	else
	{
		Vote(_System);
		_System.setVoteIndicator();
	}
}
//showing election result
void case_9(System& _System)
{
	if (_System.getVoteIndicator() == 1)
	{
		ViewElectionResults(_System);
	}
	else
	{
		cout << "************************NOTICE************************" << endl;
		cout << "Election round hasnt been occured yet, Please vote first." << endl;
		cout << "************************NOTICE************************" << endl;
	}
	cout << endl;
}
//comparing 2 parties
void case_10(System& _System)
{
	cout << "Likud party has " << _System.findPoliticalParty(0).getNumOfCandidates() << " " << "Candidates." << endl;
	cout << "Kachol - Lavan party has " << _System.findPoliticalParty(1).getNumOfCandidates() << " " << "Candidates." << endl;

	if (_System.findPoliticalParty(0) >  _System.findPoliticalParty(1))
	{
		cout << "Likud party has more candidates" << endl;
	}
	else
		cout << "Kachol - Lavan party has more candidates" << endl;
}
//exiting
void case_11(System& _System)
{
	_System.saveCitizens();
	cout << endl;
	cout << endl;
	cout << " ------******************************------" << endl;
	cout << " ------******************************------" << endl;
	cout << "Thank you for using Election-System, Bye Bye!" << endl;
	cout << " ------******************************------" << endl;
	cout << " ------******************************------" << endl;
	
}



/********"Hard-Coded" functions for playing********/
void addPlayingRegions(System& _System)
{
	//VotingRegion Num1

	string v1 = { "Rishon" };
	string v12 = { "Bashari" };
	Address* address1= new Address(v1, v12, 8);
	VotingRegion* V1 = new VotingRegion(*address1);
	_System.setVotingRegions(*V1);

	//VotingRegion Num2
	string v2 = { "Kibutz Gesher" };
	string v22 = { "Adardasim" };
	Address* address2 = new Address(v2, v22, 0);
	VotingRegion* V2 = new VotingRegion(*address2);
	_System.setVotingRegions(*V2);

	//VotingRegion Num3
	string v3 = { "Tel aviv" };
	string v32 = { "Shpinoza" };
	Address* address3 = new Address(v3, v32, 41);
	Covid19MilitaryVotingRegion* V3 = new Covid19MilitaryVotingRegion(*address3);
	_System.setVotingRegions(*V3);

	//VotingRegion Num4
	string v4 = { "Tel aviv" };
	string v42 = { "Zichron Yacov" };
	Address* address4 = new Address(v4, v42, 6);
	Covid19CivilianVotingRegion* V4 = new Covid19CivilianVotingRegion(*address4);
	_System.setVotingRegions(*V4);
}

void addPlayingParties(System& _System)
{
	//Party Num1

	Date* date1 = new Date(2, 2, 1966);
	string name1 = { "Likud" };
	PoliticalParty* Party1 = new PoliticalParty(name1, (eFaction)0, *date1);
	_System.setParties(*Party1);
	
	//Party Num2

	Date* date2 = new Date(3, 3, 2019);
	string name2 = { "Kachol-Lavan" };
	PoliticalParty* Party2 = new PoliticalParty(name2, (eFaction)2, *date2);
	_System.setParties(*Party2);

	//Party Num3

	Date *date3 = new Date(3, 3, 2000);
	string name3 = { "Israel-Bitainu" };
	PoliticalParty* Party3 = new PoliticalParty(name3, (eFaction)2, *date3);
	_System.setParties(*Party3);

}

void addPlayingCitizens(System& _System)
{
	//Citizen Num1
	string naMe1 = { "Omer" };
	string name12 = { "Shejtman" };
	string id1 = { "204369966" };
	int VR1 = 3;
	Candidate* C1 = new Candidate(naMe1, name12, id1, 1996, (_System.findRegion(VR1)), 1, &_System.findPoliticalParty(0));
	_System.setCitizens(*C1);
	_System.findPoliticalParty(0).setCandidate(*C1);

	//Citizen Num2

	string nAme2 = { "Chen" };
	string name22 = { "Kapp" };
	string id2 = { "204369962" };
	int VR2 = 0;
	Candidate* C2 = new Candidate(nAme2, name22, id2, 1992, (_System.findRegion(VR2)), 0, &_System.findPoliticalParty(0));
	_System.setCitizens(*C2);
	_System.findPoliticalParty(0).setCandidate(*C2);

	//Citizen Num3

	string Name3 = { "Dani" };
	string name32 = { "Zion" };
	string id3 = { "204369988" };
	int VR3 = 3;
	Candidate* C3 = new Candidate(Name3, name32, id3, 1992, (_System.findRegion(VR3)), 1, &_System.findPoliticalParty(1));
	_System.setCitizens(*C3);
	_System.findPoliticalParty(0).setCandidate(*C3);

	//Citizen Num4

	string name4 = { "Yuval" };
	string name42 = { "Shlosser" };
	string id4 = { "204369999" };
	int VR4 = 1;
	Candidate* C4 = new Candidate(name4, name42, id4, 1996, (_System.findRegion(VR4)), 0, &_System.findPoliticalParty(1));
	_System.setCitizens(*C4);
	_System.findPoliticalParty(1).setCandidate(*C4);

	//Citizen Num5

	string name5 = { "Tamir" };
	string name52 = { "Shaham" };
	string id5 = { "204369977" };
	int VR5 = 1;
	Candidate* C5 = new Candidate(name5, name52, id5, 1990, (_System.findRegion(VR5)), 0, &_System.findPoliticalParty(2));
	_System.setCitizens(*C5);
	_System.findPoliticalParty(2).setCandidate(*C5);


	//Citizen Num6

	string name6 = { "Neta" };
	string name62 = { "Sharon" };
	string id6 = { "204369955" };
	int VR6 = 0;
	Candidate* C6 = new Candidate(name6, name62, id6, 1996, (_System.findRegion(VR6)), 0, &_System.findPoliticalParty(0));
	_System.setCitizens(*C6);
	_System.findPoliticalParty(2).setCandidate(*C6);

}


