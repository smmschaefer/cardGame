#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int SIZE = 100;
const int TEXT = 200;


struct	node
{
	char * name;
	char * cost;
	int  attack;
	int defense;
	char * ability;
	char * instant;	

	node();
	~node();
	
	node * next;
};

class card
{
	public:
		card();
		~card();
	
		void search(char * name);
		void create(char * name, char * cost, int attack, int defense, char * ability, char * instant); //LLL
		void display();
		void remove(char * name);
		void load();
	//	attack();
	//	defend();
	//	use_ability();
	//	instant();
	private:
		void search(node * head, char * name);
		void remove(node * & head, char * name);
		void display(node * head);
		node * head;		
};
















