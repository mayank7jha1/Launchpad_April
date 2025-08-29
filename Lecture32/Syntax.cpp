#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main() {

	map<string, int>mp;
	unordered_map<string, int>ump;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		pair<string, int>p;
		cin >> p.first >> p.second;
		mp.insert(p);

		int x, y;
		cin >> x >> y;

		mp.insert({x, y});

		//Updation
		mp[x] = y;
	}

	// mp["Key"]=value

	for (pair<string, int> x : mp) {
		cout << x.first << " " << x.second << endl;
	}

	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << " " << it->second << endl;
	}

	// if (mp.count(key) == true / false) {

	// }


}