#include<iostream>
#include<string>
using namespace std;


/*
	Data : key value
	Address of the next single source of information.
*/

template<typename T>
class node {
public:
	string key;
	T value;

	//Because we are using seperate chain method
	node<T>*next;

	//Constructor
	node(string s, T v) {
		key = s;
		value = v;
		next = NULL;
	}

	//Destructor
	~node() {
		if (next != NULL) {
			delete next;
		}
	}
};

template<typename T>
class hashtable {
	node<T>**table;
	int ts;
	int cs;

	//Hashfunction
	int Hashfunction(string key) {

		int Mutiplier = 1;
		int ans = 0;

		for (int i = 0; i < key.size(); i++) {
			ans += (((key[i] % ts) * (Mutiplier % ts)) % ts);
			Mutiplier = ((Mutiplier % ts) * 131) % ts;
		}

		return (ans % ts);
	}


	void Rehashing() {

		node<T>**oldTable = table;

		table = new node<T>*[2 * ts];
		ts = ts * 2;
		cs = 0;

		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}

		//Copy all the data from the old table to the new
		//table but first pass them again through
		//hashfunction.

		//This ensure you are not making a long chain
		//on a single index.

		for (int i = 0; i < (ts / 2); i++) {

			//oldtable[i]: This is an address of a dynamic array

			node<T>*head = oldTable[i];

			while (head != NULL) {
				insert(head->key, head->value);
				head = head->next;
			}

		}

		delete[]oldTable;
	}

public:
	hashtable(int size = 10) {
		ts = 10;
		cs = 0;
		table = new node<T>*[size];

		//Initialise the pointers to NULL;
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}
	}

	void insert(string key, T value) {
		int hashindex = Hashfunction(key);

		node<T>*n = new node<T>(key, value);
		cs++;


		//Same as InsertAtHead in Linked List.
		n->next = table[hashindex];
		table[hashindex] = n;

		//Reshashing:
		if (((cs / ts) * 1.0) >= 0.7) {
			Rehashing();
		}

	}

	void Print() {
		for (int i = 0; i < ts; i++) {

			cout << i << " ---> ";
			node<T>*head = table[i];

			while (head != NULL) {
				cout << "{" << head->key << "," << head->value << "} ---> ";
				head = head->next;
			}

			cout << "NULL" << endl;
		}

	}

};