#include<iostream>
using  namespace std;

int main() {


	//Control Statements:
	//Break and Continue : Loop / Repeat Statements.


	// for (int i = 0; i < 10; i += 1) {
	// 	if (i == 5) {
	// 		break;
	// 	}
	// }

	// //YOu will stand here.

	// for (int i = 0; i < 10; i += 1) {
	// 	for (int j = 0; j < 15; j += 1) {
	// 		if (j == 5) {
	// 			break;
	// 		}
	// 	}
	// 	//It will stand here.
	// 	cout << "Yo";
	// }


	for (int i = 0; i < 5; i += 1) {

		cout << i;
		if (i == 3) {
			continue;
		}

		i += 1;
	}

}





