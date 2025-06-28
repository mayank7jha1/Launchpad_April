#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define int long long

bool isValid(int* a, int n, int t, int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (mid / a[i]);
		if (sum >= t) {
			return true;
		}
	}
	return false;
}


int32_t main() {

	int n, t;
	cin >> n >> t;

	int a[n] {0};
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int s = 1;
	int min_ele = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min_ele = min(min_ele, a[i]);
	}

	int e = t * min_ele;

	int ans = -1;
	while (s <= e)
	{
		int mid = s + (e - s) / 2;
		if (isValid(a, n, t, mid))
		{
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << endl;
}




