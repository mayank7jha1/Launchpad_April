#include<iostream>
using  namespace std;


//Function Overloading
int sum(int x, int y) {
	return x + y;
}

int sum(int x, int y, int z) {
	return x + y + z;
}

int sum(int x, int y , int z, int t) {
	return x + y + t + z;
}

double sum(int x, double y, double z) {
	return x + y + z;
}


// template<typename T>
double sum(double x = 0.0, double y = 0.0, double z = 0.0, double t = 0.0) {
	return x + y + z + t;
}


int main() {
	cout << sum(98, 5.8, 8.8);
}