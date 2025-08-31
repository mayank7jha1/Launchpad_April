#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		multiset<int>xc, yc, sx, sy;

		xc.insert(0);
		xc.insert(n);
		yc.insert(0);
		yc.insert(m);

		sx.insert(n);
		sy.insert(m);

		for (int i = 0; i < q; i++) {

			int a, b;
			cin >> a >> b;

			if (a == 0) {
				//Create a division in x = b.

				if (xc.find(b) != xc.end()) {
					//You have already made a division on this co-ordinate.
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				multiset<int>::iterator small = (--xc.lower_bound(b));
				multiset<int>::iterator large = xc.upper_bound(b);

				int Length = (*large - *small);
				sx.erase(sx.find(Length));

				sx.insert(b - *small);
				sx.insert(*large - b);

				xc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;

			} else {
				//Create a division in y = b;

				if (yc.find(b) != yc.end()) {
					//You have already made a division on this co-ordinate.
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				multiset<int>::iterator small = (--yc.lower_bound(b));

				multiset<int>::iterator large = yc.upper_bound(b);

				int Length = (*large - *small);
				sy.erase(sy.find(Length));

				sy.insert(b - *small);
				sy.insert(*large - b);

				yc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;
			}
		}
	}
}
