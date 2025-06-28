#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;//Take input for n also.
	int i = 1;
	int ans = 0;//here variable is not defined i.e not specified data type.
	while (i <= n)
	{
		int a, b, c;
		cin >> a >> b >> c;//Take input for a,b,c from user.
		int sum = a + b + c;//Sum is not defined (data type not specified. also a,b,c are variables not text.)
		if (sum >= 2)
		{
			ans = ans + 1;//ans=ans=1 this is not right, also ans and 1 are not text.
			i = i + 1;//Again not text.
		}
		else
		{
			i = i + 1;//again not text.
		}
	}

	//We need to print the answr value not yes or no and while will not have else part.

	cout << ans << endl;

	// } else {
	// 	cout << "YES" << '\n';
	// }

}