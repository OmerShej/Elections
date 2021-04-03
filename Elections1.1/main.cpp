//Omer Shejtman, ID: 316016708

#include "UserInterFace.h"
#include "General.h"

int main()
{
	Date date(1, 1, 2020); // election's date
	System ElectionSystem(date); // main system
	int menuIndex;
	/********Hard Coded Objects for the system********/
	addPlayingRegions(ElectionSystem);
	addPlayingParties(ElectionSystem);
	ElectionSystem.loadCitizens();
	//addPlayingCitizens(ElectionSystem);
	cout << endl;
	cout << endl;

	cout << "Welcome to Election-System Program !" << endl;
	do
	{
		showMenu();
		cout << endl;
		cout << "Please, select option from the menu :  " << endl;
		cin >> menuIndex;
		

		switch (menuIndex)
		{
		case 1:// add voting-region/kalpi
			case_1(ElectionSystem);
			break;
		case 2: // add a citizen 
			case_2(ElectionSystem);
			break;
		case 3: // add a political party
			case_3(ElectionSystem);
			break;
		case 4:	//  add a party candidate
			case_4(ElectionSystem);
			break;
		case 5:	// show all voting regions
			case_5(ElectionSystem);
			break;
		case 6: // show all citizens
			case_6(ElectionSystem);
			break;
		case 7: // show all political parties
			case_7(ElectionSystem);
			break;
		case 8: // election - voting proccess, asking each and every citizen to vote.
			case_8(ElectionSystem); 
			break;
		case 9:	// election results 
			case_9(ElectionSystem);
			break;
		case 10: // comparing 2 parties
			case_10(ElectionSystem);
			break;
		case 11: // exit 
			case_11(ElectionSystem);
			break;

		
			break;
		default:
			break;
		}
	} while (menuIndex != 11);
	
}


