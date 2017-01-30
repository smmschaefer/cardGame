#include "card.h"


int main()
{
	int choice;
	char name[SIZE];
	char cost[SIZE];
	int attack;
	int defense;
	char ability[TEXT];
	char instant[TEXT];
	
	card magic;
	
	system("CLEAR");
	magic.load();

	do
	{
		cout << "\n::::::::::::::::::::::::::::::\n";
		cout << "::::::[ CARD GAME BETA ]::::::\n";
		cout << "::::::::::::::::::::::::::::::\n";
		cout << "::::::[ PICK AN OPTION ]::::::\n";
		cout << "::::::::::::::::::::::::::::::\n";	
		cout << "::::::::::::::::::::::::::::::\n\n";

		cout << "1..... View Current Cards In Deck\n";
		cout << "2..... Create a New Card\n";
		cout << "3..... Search for Card\n";
		cout << "4..... Remove Card from Deck\n";
		cout << "5..... Exit\n";
	
		cout << "Enter Choice: ";

		while(!(cin >> choice))
		{
			cout << "Improper input...\n";
			cout << "Please enter a valid input, 1-5: \n";
			cin.clear();
			cin.ignore(101, '\n');
		}
		
		cin.ignore(100, '\n');
		switch(choice)
		{
			case 1:
				system("CLEAR");					
				cout << "\n::::::::::::::::::::::::::::::\n";
				cout << "::::::[ CARD GAME BETA ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";
				cout << ":[ DISPLAYING CARDS IN DECK ]:\n";
				cout << "::::::::::::::::::::::::::::::\n";	
				cout << "::::::::::::::::::::::::::::::\n\n";
				
				magic.display();	
			
				break;
			case 2:
				system("CLEAR");
				cout << "\n::::::::::::::::::::::::::::::\n";
				cout << "::::::[ CARD GAME BETA ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";
				cout << ":::::[ CREATE A NEW CARD ]::::\n";
				cout << "::::::::::::::::::::::::::::::\n";	
				cout << "::::::::::::::::::::::::::::::\n\n";

				cout << "CREATE A NEW CARD!\n\n";
				
				cout << "Name of card: ";
				cin.get(name, 101, '\n');
				cin.ignore(101, '\n');			
				cout << "\n";
				
				cout << "Mana cost: ";
				cin.get(cost, 101, '\n');
				cin.ignore(101, '\n');
				cout << "\n";

				cout << "Attack: ";
				cin >> attack;
				cout << "\n";
				cin.ignore(11,'\n');	
				
				cout << "Defense: ";
				cin >> defense;
				cout << "\n";
				cin.ignore(11,'\n');	
				
				cout << "Ability: ";
				cin.get(ability, 201, '\n');
				cin.ignore(201, '\n');
				cout << "\n";

				cout << "Instant: ";
				cin.get(instant, 202, '\n');
				cin.ignore(201, '\n');
				cout << "\n";
					
				magic.create(name, cost, attack, defense, ability, instant);
				
				break;
			case 3: 
				system("CLEAR");
				cout << "\n::::::::::::::::::::::::::::::\n";
				cout << "::::::[ CARD GAME BETA ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";
				cout << ":::::::[ SEARCH A CARD ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";	
				cout << "::::::::::::::::::::::::::::::\n\n";
			
				cout << "Enter the name of the card you would like to search for ... \n";
				cout << "Card Name: ";
				
				cin.get(name, 101, '\n');
				
				magic.search(name);
				
				break;
			case 4:
				system("CLEAR");
				cout << "\n::::::::::::::::::::::::::::::\n";
				cout << "::::::[ CARD GAME BETA ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";
				cout << ":::::::[ REMOVE A CARD ]::::::\n";
				cout << "::::::::::::::::::::::::::::::\n";	
				cout << "::::::::::::::::::::::::::::::\n\n";
				
				cout << "Enter the name of a the card you would like to remove...\n";
				cout << "Card Name: ";
				
				cin.get(name, 101, '\n');

				magic.remove(name);

				break;
			case 5:
				system("CLEAR");
				break;
			default:
				system("CLEAR");
				cout << "Improper input, exiting\n";
		}

	}while(choice != 5);	

	return 0;

}







