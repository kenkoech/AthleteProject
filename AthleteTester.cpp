//##############################################################################
// KEN KOECH
// CIS 200: DATA STRUCTURES
// ATHLETE LINKEDLIST PROJECT
// CREATION DATE
// MODIFICATION DATE
//##############################################################################

//##############################################################################
//Tasks to do with the ‘Athlete’ class.
//0. Pick any five team sports from ODU athletics, and store
//information about players in five different files.E.g.,
//BasketBall_Girls.csv, Baseball_Boys.txt.
//1. Create two separate linked lists of ‘Athlete’ objects for any two
//given sports.E.g., girlsSoccerList, boysFootballList.
//2. Construct objects from data in the file and insert them in the
//lists.
//3. Create three sorted linked list of ‘Athlete’ objects.
//4. Construct objects from data in the file and insert them in the
//lists.
//5. Search for a given Athlete in a list.
//6. Merge two lists from different sports(for instance: girls and
//	boys basketball) into one list.
//##############################################################################
#include <iostream>
#include "LinkedList.h"
#include <fstream>

//################################### FUNCTIONS ###########################################
// Function for reading file and storing it in a linked list
void readFromFileIntoList(LinkedList<Athlete>&, ifstream&);

// Function to display the main menu
void mainMenu();

// Function to display the sports menu
void sportsMenu();

// Function to add new player on clientside
Athlete createNewPlayer();

// Function to check if the user's choice is valid
bool isValidChoice(int);

// Function to display merged list
void doDisplay(LinkedList <Athlete>&, char);

// Function to inform the user of player search
void playerSearch(LinkedList<Athlete>&, int);

// Function for opening file using just the name and reading contents into a linkedlist
// I made this function cause my program opens files and creates linkedlists only if the user wants to use them
// I therefore use this function every time the user wants to merge lists
void openNewFile(string, LinkedList<Athlete>&);

// Function for opening a file
//ifstream& openFile(string);

//Function to sort the list client side
//template<typename T>
//LinkedList<T> sortList(LinkedList<T> linkedList)

//################################### END OF FUNCTION PROTOTYPES ###########################################

using namespace std;
int main() {
	// Variables to hold the user choices, jersey numbers to be searched for, and whether a user would like to see an updated list or not
	int choiceForMainMenu, choiceForSportsMenu, jerseyNumber, choiceForMerge;
	char option;
	do {
		do {
			mainMenu();
			cin >> choiceForMainMenu;
		} while (!isValidChoice(choiceForMainMenu));
		// I have a switch statement for the different sports
		// Within each switch statement is a nested switch statement that lists operations that can be done on the lists
		// Within the merge option in the nested switch statement is another nested switch statement that lets the user choose which sport to merge with
		switch (choiceForMainMenu)
		{
		case 0: cout << "Thank you for your time! See you next time." << endl;
				break;
		case 1: {
			LinkedList<Athlete> soccerAthleteList;
			openNewFile("Men's_Soccer_Roster.csv", soccerAthleteList);
			do {
				do {
					sportsMenu();
					cin >> choiceForSportsMenu;
				} while (!isValidChoice(choiceForSportsMenu));


				switch (choiceForSportsMenu) {
				case 1: cout << "Here is the list of current soccer athletes: " << endl;
					soccerAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 2: cout << "Here is a list of soccer athletes sorted according to jersey number: " << endl;
					// Sort a list
					soccerAthleteList.sortList();
					// Display the sorted list
					soccerAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 3: cout << "What is the jersey number of your player?" << endl;
					cin >> jerseyNumber;
					// Function will search for athlete's jersey number and output other details if user wishes to have them
					playerSearch(soccerAthleteList, jerseyNumber);
					break;
				case 4: { // Call our function that adds a new player to the list
					Athlete newPlayer = createNewPlayer();
					// Sort the list
					soccerAthleteList.sortList();
					// Add the new player to the list
					soccerAthleteList.insertInSorted(newPlayer);
					cout << "Your player has been added!! Would you like to see the new list? Y/N" << endl;
					cin >> option;
					doDisplay(soccerAthleteList, option); }
					  break;
				case 5: cout << "Which other sport would you like to merge a list from? ";
					do {
						do {
							mainMenu();
							cin >> choiceForMerge;
						} while (!isValidChoice(choiceForMerge));
						switch (choiceForMerge)
						{
						case 1: cout << "Invalid choice. This is already the men's soccer list. Please select another sport or press 0 to quit." << endl;
							cout << "#################################\n";
							break;
						case 2: {
							//LinkedList<Athlete> womenSoccerList;
							//readFromFileIntoList(womenSoccerList, openFile("Women's_Soccer_Roster.csv"));
							LinkedList<Athlete> womenSoccerAthleteList;
							// Women's Soccer LinkedList
							openNewFile("Women's_Soccer_Roster.csv", womenSoccerAthleteList);
							LinkedList<Athlete> mergedList = soccerAthleteList.mergeTwoLists(womenSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 3: {
							// Men's Basketball LinkedList
							LinkedList<Athlete> mensBasketballAthleteList;
							openNewFile("Men's_Basketball_Roster.csv", mensBasketballAthleteList);
							LinkedList<Athlete> mergedList = soccerAthleteList.mergeTwoLists(mensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 4: {
							// Women's Basketball LinkedList
							LinkedList<Athlete> womensBasketballAthleteList;
							openNewFile("Women's_Basketball_Roster.csv", womensBasketballAthleteList);
							LinkedList<Athlete> mergedList = soccerAthleteList.mergeTwoLists(womensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 5: {
							// Women's Volleyball LinkedList
							LinkedList<Athlete> womensVolleyballAthleteList;
							openNewFile("Women's_Volleyball_Roster.csv", womensVolleyballAthleteList);
							LinkedList<Athlete> mergedList = soccerAthleteList.mergeTwoLists(womensVolleyballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 0: cout << "Thank you for your time! Back to the sports menu..." << endl;
								cout << "#################################\n";
							break;
						}
					} while (choiceForMerge);
					break;
				case 0: cout << "Thank you for your time! Back to main menu..." << endl;
						cout << "#################################\n";
					break;
				}
			} while (choiceForSportsMenu);
		}
		break;
		case 2: {
			//Women's Soccer LinkedList
			LinkedList<Athlete> womensoccerAthleteList;
			openNewFile("Women's_Soccer_Roster.csv", womensoccerAthleteList);
			do {
				do {
					sportsMenu();
					cin >> choiceForSportsMenu;
				} while (!isValidChoice(choiceForSportsMenu));


				switch (choiceForSportsMenu) {
				case 1: cout << "Here is the list of your current athletes: " << endl;
					womensoccerAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 2: cout << "Here is a list of your current athletes sorted according to jersey number: " << endl;
					// Sort a list
					womensoccerAthleteList.sortList();
					// Display the sorted list
					womensoccerAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 3: cout << "What is the jersey number of your player?" << endl;
					cin >> jerseyNumber;
					// Function will search for athlete's jersey number and output other details if user wishes to have them
					playerSearch(womensoccerAthleteList, jerseyNumber);
					break;
				case 4: { // Call our function that adds a new player to the list
					Athlete newPlayer = createNewPlayer();
					// Sort the list
					womensoccerAthleteList.sortList();
					// Add the new player to the list
					womensoccerAthleteList.insertInSorted(newPlayer);
					cout << "Your player has been added!! Would you like to see the new list? Y/N" << endl;
					cin >> option;
					doDisplay(womensoccerAthleteList, option); }
					  break;
				case 5: cout << "Which other sport would you like to merge a list from? ";
					do {
						do {
							mainMenu();
							cin >> choiceForMerge;
						} while (!isValidChoice(choiceForMerge));
						switch (choiceForMerge)
						{
						case 2: cout << "Invalid choice. This is already the women's soccer list. Please select another sport or press 0 to quit." << endl;
							cout << "#################################\n";
							break;
						case 1: {
							// Men's Soccer LinkedList
							LinkedList<Athlete> menSoccerAthleteList;
							openNewFile("Men's_Soccer_Roster.csv", menSoccerAthleteList);
							LinkedList<Athlete> mergedList = womensoccerAthleteList.mergeTwoLists(menSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							break;
						case 3: {
							// Men's Basketball LinkedList
							LinkedList<Athlete> mensBasketballAthleteList;
							openNewFile("Men's_Basketball_Roster.csv", mensBasketballAthleteList);
							LinkedList<Athlete> mergedList = womensoccerAthleteList.mergeTwoLists(mensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 4: {
							// Women's Basketball LinkedList
							LinkedList<Athlete> womensBasketballAthleteList;
							openNewFile("Women's_Basketball_Roster.csv", womensBasketballAthleteList);
							LinkedList<Athlete> mergedList = womensoccerAthleteList.mergeTwoLists(womensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 5: {
							// Women's Volleyball LinkedList
							LinkedList<Athlete> womensVolleyballAthleteList;
							openNewFile("Women's_Volleyball_Roster.csv", womensVolleyballAthleteList);
							LinkedList<Athlete> mergedList = womensoccerAthleteList.mergeTwoLists(womensVolleyballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 0: cout << "Thank you for your time! Back to the sports menu..." << endl;
								cout << "#################################\n";
							break;
						}
					} while (choiceForMerge);
					break;
				case 0: cout << "Thank you for your time! Back to main menu..." << endl;
						cout << "#################################\n";
					break;
				}
			} while (choiceForSportsMenu);
		}
		break;
		case 3: {
			// Men's Basketball LinkedList
			LinkedList<Athlete> mensBasketballAthleteList;
			openNewFile("Men's_Basketball_Roster.csv", mensBasketballAthleteList);
			do {
				do {
					sportsMenu();
					cin >> choiceForSportsMenu;
				} while (!isValidChoice(choiceForSportsMenu));


				switch (choiceForSportsMenu) {
				case 1: cout << "Here is the list of your current athletes: " << endl;
					mensBasketballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 2: cout << "Here is a list of your current athletes sorted according to jersey number: " << endl;
					// Sort a list
					mensBasketballAthleteList.sortList();
					// Display the sorted list
					mensBasketballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 3: cout << "What is the jersey number of your player?" << endl;
					cin >> jerseyNumber;
					// Function will search for athlete's jersey number and output other details if user wishes to have them
					playerSearch(mensBasketballAthleteList, jerseyNumber);
					break;
				case 4: { // Call our function that adds a new player to the list
					Athlete newPlayer = createNewPlayer();
					// Sort the list
					mensBasketballAthleteList.sortList();
					// Add the new player to the list
					mensBasketballAthleteList.insertInSorted(newPlayer);
					cout << "Your player has been added!! Would you like to see the new list? Y/N" << endl;
					cin >> option;
					doDisplay(mensBasketballAthleteList, option); }
					  break;
				case 5: cout << "Which other sport would you like to merge a list from? ";
					do {
						do {
							mainMenu();
							cin >> choiceForMerge;
						} while (!isValidChoice(choiceForMerge));
						switch (choiceForMerge)
						{
						case 3: cout << "Invalid choice. This is already the men's basketball list. Please select another sport or press 0 to quit." << endl;
							cout << "#################################\n";
							break;
						case 1: {
							// Men's Soccer LinkedList
							LinkedList<Athlete> menSoccerAthleteList;
							openNewFile("Men's_Soccer_Roster.csv", menSoccerAthleteList);
							LinkedList<Athlete> mergedList = mensBasketballAthleteList.mergeTwoLists(menSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 2: {
							// Women's Soccer LinkedList
							LinkedList<Athlete> womenSoccerAthleteList;
							openNewFile("Women's_Soccer_Roster.csv", womenSoccerAthleteList);
							LinkedList<Athlete> mergedList = mensBasketballAthleteList.mergeTwoLists(womenSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 4: {
							// Women's Basketball LinkedList
							LinkedList<Athlete> womensBasketballAthleteList;
							openNewFile("Women's_Basketball_Roster.csv", womensBasketballAthleteList);
							LinkedList<Athlete> mergedList = mensBasketballAthleteList.mergeTwoLists(womensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 5: {
							// Women's Volleyball LinkedList
							LinkedList<Athlete> womensVolleyballAthleteList;
							openNewFile("Women's_Volleyball_Roster.csv", womensVolleyballAthleteList);
							LinkedList<Athlete> mergedList = mensBasketballAthleteList.mergeTwoLists(womensVolleyballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 0: cout << "Thank you for your time! Back to sports menu..." << endl;
								cout << "#################################\n";
							break;
						}
					} while (choiceForMerge);
					break;
				case 0: cout << "Thank you for your time! Back to main menu..." << endl;
						cout << "#################################\n";
					break;
				}
			} while (choiceForSportsMenu);
		}
		break;
		case 4: {
			// Women's Basketball LinkedList
			LinkedList<Athlete> womensBasketballAthleteList;
			openNewFile("Women's_Basketball_Roster.csv", womensBasketballAthleteList);
			do {
				do {
					sportsMenu();
					cin >> choiceForSportsMenu;
				} while (!isValidChoice(choiceForSportsMenu));


				switch (choiceForSportsMenu) {
				case 1: cout << "Here is the list of your current athletes: " << endl;
					womensBasketballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 2: cout << "Here is a list of your current athletes sorted according to jersey number: " << endl;
					// Sort a list
					womensBasketballAthleteList.sortList();
					// Display the sorted list
					womensBasketballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 3: cout << "What is the jersey number of your player?" << endl;
					cin >> jerseyNumber;
					// Function will search for athlete's jersey number and output other details if user wishes to have them
					playerSearch(womensBasketballAthleteList, jerseyNumber);
					break;
				case 4: { // Call our function that adds a new player to the list
					Athlete newPlayer = createNewPlayer();
					// Sort the list
					womensBasketballAthleteList.sortList();
					// Add the new player to the list
					womensBasketballAthleteList.insertInSorted(newPlayer);
					cout << "Your player has been added!! Would you like to see the new list? Y/N" << endl;
					cin >> option;
					doDisplay(womensBasketballAthleteList, option); }
					  break;
				case 5: cout << "Which other sport would you like to merge a list from? ";
					do {
						do {
							mainMenu();
							cin >> choiceForMerge;
						} while (!isValidChoice(choiceForMerge));
						switch (choiceForMerge)
						{
						case 4: cout << "Invalid choice. This is already the women's basketball list. Please select another sport or press 0 to quit." << endl;
							cout << "#################################\n";
							break;
						case 1: {
							// Men's Soccer LinkedList
							LinkedList<Athlete> menSoccerAthleteList;
							openNewFile("Men's_Soccer_Roster.csv", menSoccerAthleteList);
							LinkedList<Athlete> mergedList = womensBasketballAthleteList.mergeTwoLists(menSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 2: {
							// Women's Soccer LinkedList
							LinkedList<Athlete> womenSoccerAthleteList;
							openNewFile("Women's_Soccer_Roster.csv", womenSoccerAthleteList);
							LinkedList<Athlete> mergedList = womensBasketballAthleteList.mergeTwoLists(womenSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 3: {
							// Men's Basketball LinkedList
							LinkedList<Athlete> mensBasketballAthleteList;
							openNewFile("Men's_Basketball_Roster.csv", mensBasketballAthleteList);
							LinkedList<Athlete> mergedList = womensBasketballAthleteList.mergeTwoLists(mensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 5: {
							// Women's Volleyball LinkedList
							LinkedList<Athlete> womensVolleyballAthleteList;
							openNewFile("Women's_Volleyball_Roster.csv", womensVolleyballAthleteList);
							LinkedList<Athlete> mergedList = womensBasketballAthleteList.mergeTwoLists(womensVolleyballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 0: cout << "Thank you for your time! Back to sports menu..." << endl;
								cout << "#################################\n";
							break;
						}
					} while (choiceForMerge);
					break;
				case 0: cout << "Thank you for your time! Back to main menu..." << endl;
						cout << "#################################\n";
					break;
				}
			} while (choiceForSportsMenu);
		}
		break;
		case 5: {
			// Women's VolleyBall LinkedList
			LinkedList<Athlete> womensVolleyballAthleteList;
			openNewFile("Women's_Volleyball_Roster.csv", womensVolleyballAthleteList);
			do {
				do {
					sportsMenu();
					cin >> choiceForSportsMenu;
				} while (!isValidChoice(choiceForSportsMenu));


				switch (choiceForSportsMenu) {
				case 1: cout << "Here is the list of your current athletes: " << endl;
					womensVolleyballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 2: cout << "Here is a list of your current athletes sorted according to jersey number: " << endl;
					// Sort a list
					womensVolleyballAthleteList.sortList();
					// Display the sorted list
					womensVolleyballAthleteList.displayLinkedList();
					cout << "#################################\n";
					break;
				case 3: cout << "What is the jersey number of your player?" << endl;
					cin >> jerseyNumber;
					// Function will search for athlete's jersey number and output other details if user wishes to have them
					playerSearch(womensVolleyballAthleteList, jerseyNumber);
					break;
				case 4: { // Call our function that adds a new player to the list
					Athlete newPlayer = createNewPlayer();
					// Sort the list
					womensVolleyballAthleteList.sortList();
					// Add the new player to the list
					womensVolleyballAthleteList.insertInSorted(newPlayer);
					cout << "Your player has been added!! Would you like to see the new list? Y/N" << endl;
					cin >> option;
					doDisplay(womensVolleyballAthleteList, option); }
					  break;
				case 5: cout << "Which other sport would you like to merge a list from? ";
					do {
						do {
							mainMenu();
							cin >> choiceForMerge;
						} while (!isValidChoice(choiceForMerge));
						switch (choiceForMerge)
						{
						case 5: cout << "Invalid choice. This is already the women's volleyball list. Please select another sport or press 0 to quit." << endl;
							cout << "#################################\n";
							break;
						case 1: {
							// Men's Soccer LinkedList
							LinkedList<Athlete> menSoccerAthleteList;
							openNewFile("Men's_Soccer_Roster.csv", menSoccerAthleteList);
							LinkedList<Athlete> mergedList = womensVolleyballAthleteList.mergeTwoLists(menSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 2: {
							// Women's Soccer LinkedList
							LinkedList<Athlete> womenSoccerAthleteList;
							openNewFile("Women's_Soccer_Roster.csv", womenSoccerAthleteList);
							LinkedList<Athlete> mergedList = womensVolleyballAthleteList.mergeTwoLists(womenSoccerAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 3: {
							// Men's Basketball LinkedList
							LinkedList<Athlete> mensBasketballAthleteList;
							openNewFile("Men's_Basketball_Roster.csv", mensBasketballAthleteList);
							LinkedList<Athlete> mergedList = womensVolleyballAthleteList.mergeTwoLists(mensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 4: {
							// Women's Basketball LinkedList
							LinkedList<Athlete> womensBasketballAthleteList;
							openNewFile("Women's_Basketball_Roster.csv", womensBasketballAthleteList);
							LinkedList<Athlete> mergedList = womensVolleyballAthleteList.mergeTwoLists(womensBasketballAthleteList);
							cout << "Your lists have been merged!! Would you like to see the merged list? Y/N" << endl;
							cin >> option;
							doDisplay(mergedList, option);
						}
							  break;
						case 0: cout << "Thank you for your time! Back to sports menu..." << endl;
								cout << "#################################\n";
							break;
						}
					} while (choiceForMerge);
					break;
				case 0: cout << "Thank you for your time! Back to main menu..." << endl;
						cout << "#################################\n";
					break;
				}
			} while (choiceForSportsMenu);
		}
			  break;
		}
	} while (choiceForMainMenu);

		cout << endl << endl << "###########################################################" << endl << endl;



	return 0;
}

//################################### FUNCTIONS ###########################################
// Function for reading soccer file and storing it in a linked list
void readFromFileIntoList(LinkedList<Athlete>&athleteList, ifstream & fs) {
	// Variables to hold values from the file
	int jerseyNumber;
	string name, position, year, height, hometown;
	// Loop to create nodes and input data of athletes from file into the nodes
	while (fs >> jerseyNumber)//>> firstName >> lastName >> position >> year >> height >> hometown >> state) 
	{
		getline(fs, name, ',');
		getline(fs, position, ',');
		getline(fs, year, ',');
		getline(fs, height, ',');
		getline(fs, hometown);

		Athlete ath(jerseyNumber, name, position, year, height, hometown);
		athleteList.appendNode(ath);

	}
}

// Function to display the menu
void mainMenu()
{
	cout << "\t ***Main Menu*** \t\n";
	cout << "Choose a sport or operation from the following menu\n";
	cout << "#################################\n";
	cout << "1. Men's Soccer \n";
	cout << "2. Women's Soccer\n";
	cout << "3. Men's Basketball\n";
	cout << "4. Women's Basketball \n";
	cout << "5. Women's Volleyball\n";
	cout << "0. Quit\n";
	cout << "#################################\n";
}//end menu

 // Function to display the sports menu
void sportsMenu() {
	cout << "\t ***Sports Menu***" << endl;
	cout << "What would you like to do?" << endl;
	cout << "#################################\n";
	cout << "1. Display current list of athletes\n";
	cout << "2. Display sorted list of athletes\n";
	cout << "3. Search for a player\n";
	cout << "4. Add a new player \n";
	cout << "5. Merge list with another sport's list\n";
	cout << "0. Quit\n";
	cout << "#################################\n";
}

// Function to create a new player on clientside
Athlete createNewPlayer() {
	string name, position, schoolYear, height, homeTown;
	int jerseyNumber;
	cout << "What is the athlete's jersey number? " << endl;
	cin >> jerseyNumber;
	cin.ignore();
	cout << "What is the athlete's full name? " << endl;
	getline(cin, name);
	cout << "What is the athlete's position? " << endl;
	cin >> position;
	cout << "What is the athlete's school year?  (Fr., So., Jr., Sr.)" << endl;
	cin >> schoolYear;
	cout << "What is the athlete's height? " << endl;
	cin >> height;
	cin.ignore();
	cout << "What is the athlete's hometown/high school? " << endl;
	getline(cin, homeTown);

	Athlete ath(jerseyNumber, name, position, schoolYear, height, homeTown);
	return ath;
}

// Function to check if user's choice is valid
bool isValidChoice(int input)
{
	if (0 == input || 1 == input || 2 == input || 3 == input || 4 == input || 5 == input)
		return true;
	else
		return false;
}


// Function for displaying merged list
void doDisplay(LinkedList<Athlete>& l, char character){
	if (character == 'Y' || character == 'y') {
		l.displayLinkedList();
		cout << "#################################\n";
	}
	else {
		cout << "Okay." << endl;
		cout << "#################################\n";
	}
}

// Function to inform user of result of player search
void playerSearch(LinkedList<Athlete>& linkedList, int jerseyNumber)
{
	int result = linkedList.searchList(jerseyNumber);
	// If player is found in the list, output that player, else, let user know player does not exist
	if (result != -1) {
		cout << "\nYour player has been found in our list!! Here are the details: \n\n";
		cout << "JerseyNumber\t" << "Name\t" << "Position\t" << "Year\t";
		cout << "Height\t" << "Hometown\t\n" << linkedList.atPosition(result)->data;
		cout << "\n\n#################################\n";
	}
	else {
		cout << "Sorry! Your player does not exist in our list. To add a player, pick option 4 in the menu." << endl;
		cout << "#################################\n";
	}
}
void openNewFile(string fileName, LinkedList<Athlete>& linkedList)
{
	ifstream fileToBeRead(fileName, ios::in);
	if (!fileToBeRead) {
		cout << "Error opening file!" << endl;
		exit(-1);
	}
	readFromFileIntoList(linkedList, fileToBeRead);
	fileToBeRead.close();
}
// Function for opening a file
//ifstream& openFile(string fileName) {
//	ifstream fileToBeRead(fileName, ios::in);
//	if (!fileToBeRead) {
//		cout << "Error Opening File!";
//		exit(-1);
//	}
//	return fileToBeRead;
//}

//template<typename T>
//LinkedList<T> sortList(LinkedList<T> linkedList) {
//	{
//		int size = linkedList.getNumberOfNodes();
//		// Look for the smallest value and put it in position 1
//		// Look for the next smallest value and put it in position 2.....n times
//		int minposition;
//		Node<T>* minValue = new Node<T>;
//
//		for (int start = 1; start <= size; start++)
//		{
//			minposition = start;
//			*minValue = linkedList.atPosition(start);
//			for (int position = start + 1; position < size; position++)
//			{
//				if (linkedList.atPosition(position) < minValue)
//				{
//					*minValue = linkedList.atPosition(position);
//					minposition = position;
//				}
//			}
//			swap(linkedList.atPosition(minposition), linkedList.atPosition(start));
//		}
//	}
//
// }
//################################### END OF FUNCTION DEFINITIONS ###########################################