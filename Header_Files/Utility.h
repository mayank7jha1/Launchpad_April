#include<iostream>
using namespace std;


template<typename T1, typename T2>
class Pair {
public:
	T1 first;
	T2 second;

	//Constructor
	Pair() {
		//first = 0;
		//second = 0;
	}

	Pair(T1 f, T2 s) {
		first = f;
		second = s;
	}

	void make_pair(T1 f, T2 s) {
		first = f;
		second = s;
	}
};

