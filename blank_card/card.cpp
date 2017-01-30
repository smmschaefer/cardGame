#include "card.h"


node::node()
{
	name = NULL;
	cost = NULL;
	attack = 0;
	defense = 0;
	ability = NULL;
	instant = NULL;
	
	next = NULL;
}//end 

node::~node()
{
	if(next)
	{
		delete [] name;
		delete [] cost;
		delete [] ability;
		delete [] instant;
	}
		
}//end

card::card()
{	
	head = NULL;
}//constructor

card::~card()
{
	if(!head)
	{
		return;
	}

	node * temp = NULL;

	while(head->next != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	delete head;
}//end

void card::create(char * name, char * cost, int attack, int defense, char * ability, char * instant)
{	
		node * temp = new node;
		temp->name = new char[strlen(name)+1];
		strcpy(temp->name, name);

		temp->cost = new char [strlen(cost)+1];
		strcpy(temp->cost, cost);

		temp->attack = attack;
		temp->defense = defense;
		
		temp->ability = new char[strlen(ability)+1];
		strcpy(temp->ability, ability);
		
		temp->instant = new char[strlen(instant)+1];		
		strcpy(temp->instant, instant);
		
		temp->next = head;
		head = temp;

}//end 

void card::display()
{
	display(head);
}//end

void card::display(node * head)
{
	if(!head)
	{
		return;
	}
	
	cout << "-----------------------------\n";
	cout << "                             |\n";
	cout << "Card Name: " << head->name << endl;
	cout << "Mana Cost: " << head->cost << endl;
	cout << "Attack: " << head->attack << endl;
	cout << "Defense: " << head->defense << endl;
	cout << "Ability: " << head->ability << endl;
	cout << "Instant: " << head->instant << endl;
	
	cout << "                             |\n";
	cout << "-----------------------------\n";
	cout << "\n";

	display(head->next);
}//end

void card::search(char * name)
{
	search(head, name);
}//end

void card::search(node * head, char * name)
{
	if(!head)
	{
		return;
	}	
	
	if(strcmp(head->name, name) == 0)
	{
		cout << "Card found,  displaying...\n\n";
		cout << "Card Name: " << head->name << endl;	
		cout << "Mana Cost: " << head->cost << endl;
		cout << "Attack: " << head->attack << endl;
		cout << "Defense: " << head->defense << endl;
		cout << "Abilitiy: " << head->ability << endl;
		cout << "Instant: " << head->instant << endl;
	}		
	
	search(head->next, name);

}//end 

void card::load()
{	
	ifstream in_data("cards.txt");
	
	char name[SIZE];
	char cost[SIZE];
	int attack = 0;
	int defense = 0;
	char ability[TEXT];
	char instant[TEXT];

//	in_data.open();

	if(in_data.fail())
	{
		cerr << "Can't find file\n";
		exit(1);
	}
	
	while(in_data && !in_data.eof())
	{

		in_data.get(name, 101, '\n');
		in_data.ignore(101, '\n');

		in_data.get(cost, 101, '\n');
		in_data.ignore(101, '\n');

		in_data >> attack;
		in_data.ignore(11, '\n');
		
		in_data >> defense;
		in_data.ignore(11, '\n');
	
		in_data.get(ability, 201, '\n');
		in_data.ignore(201, '\n');
		
		in_data.get(instant, 201, '\n');
		in_data.ignore(201, '\n');
	
		create(name, cost, attack, defense, ability, instant);
		
	}

	in_data.close();

}//end


void card::remove(char * name)
{
	remove(head, name);
}//end 


void card::remove(node * & head, char * name)
{

	if(!head)
	{
		return;
	}

	if(strcmp(head->name, name) == 0)
	{
		delete head;
		return;
	}

	remove(head->next, name);

}//end 








