#include<iostream>
using  namespace std;


//Computations: n+m+k : 3*10^5 < 1.5 seconds
//1 sec : 10^8
//1.5 sec : 1.5 * 10^8

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	//I will be following a 1 based index.
	int a[100001] {0};
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
	}

	/*
		My Operation i will look like this:
		l[i] to r[i] add d[i].
	*/

	int l[100001] {0}, r[100001] {0}, d[100001] {0};
	for (int i = 1; i <= m; i += 1) {
		cin >> l[i] >> r[i] >> d[i];
	}

	//Resolving the first range:
	//I am finding out konsa operation kitni bar karna hain.

	int oc[100001] {0};

	for (int i = 1; i <= k; i += 1) {
		int x, y;
		cin >> x >> y;
		/*
			Formulae:
			d[l] = task
			d[r+1] = Opposite task

			and do this for every query and then take prefix sum.
		*/

		oc[x] += 1;
		oc[y + 1] -= 1;
	}

	for (int i = 1; i <= 100001; i += 1) {
		oc[i] = oc[i - 1] + oc[i];
	}

	//Resolving the second range.

	//I am going to every operation and directly resolving
	// the values.

	int difference[100001] {0};
	for (int i = 1; i <= 100001; i += 1) {

		/*
			Current operation ko perform karne
			ka new matlab hain :

			l[i] se lekar r[i] tak aapko
			ab (d[i]*oc[i]) ko add karna hain.

			Use the formulae:

			and do that for every operation and
			then takee the prefix.
		*/

		int left = l[i];
		int right = r[i];

		difference[left] += ((d[i] * oc[i]));
		difference[right + 1] -= ((d[i] * oc[i]));
	}

	for (int i = 1; i <= 100001; i += 1) {
		difference[i] = difference[i - 1] + difference[i];
	}

	//Add in the original array:
	for (int i = 1; i <= 100001; i += 1) {
		a[i] = a[i] + difference[i];
	}


	//Print the array.
	for (int i = 1; i <= n; i += 1) {
		cout << a[i] << " ";
	}
}