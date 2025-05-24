#include<iostream>
using  namespace std;


//Computations: n*m*k : 10^15 : 10^7 seconds
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

	while (k > 0) {

		/*
			My current query means:
			Perform operations from x to y .

			This means you have to perform:
			Operation number x,x+1,x+2 _ _ _ _ _ _ y.
		*/

		int x, y;
		cin >> x >> y;

		for (int j = x; j <= y; j += 1) {

			/*
				I am trying to peform operation number j.
				To perform jth operation you have to
				add d[j] to array a from index l[j] to r[j].
			*/

			for (int k = l[j]; k <= r[j]; k += 1) {
				a[k] += d[j];//Work
			}
		}

		k -= 1;
	}

	//Print the array.
	for (int i = 1; i <= n; i += 1) {
		cout << a[i] << " ";
	}



}