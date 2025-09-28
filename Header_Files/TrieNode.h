#include<iostream>
#include<map>
using namespace std;

class TrieNode {
public:
	char ch;
	bool terminal;
	unordered_map <char, TrieNode*>childMap;
	int freq;//Mera Current node kitni bar visited hain.

	//Default Constructor
	TrieNode() {

	}

	//Parameterised Constructor
	TrieNode(char ch) {
		this->ch = ch;
		this->terminal = 0;
		freq = 0;
	}
};