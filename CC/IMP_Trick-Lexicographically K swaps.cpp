#include <bits/stdc++.h>
void solve()
{	int n;
	cin >> n;
	vii a(n);
	map<int, int>m;
	fo(i, 0, n - 1) {
		cin >> a[i];
		m[a[i]] = i;
	}
	int k;
	cin >> k;
	if (k >= n) {
		sort(a.begin(), a.end());
		fo(i, 0, n - 1)
		cout << a[i] << " ";
		cout << endl;
	}
	else {
		int j = *max_element(a.begin(), a.end());
		int pos = 0;
		for (int i = j; i >= 0; i--) {

			if (k == 0)break;
			if (m.count(i)) {
				if (m[i] == pos) {
					pos++;
					continue;
				}
				else {
					int t = m[i];
					m[i] = pos;
					m[a[pos]] = t;
					pos++;
					k--;
				}
			}
		}
		for (int i = j; i >= 0; i--) {
			if (m.count(i)) {
				a[m[i]] = i;
			}
		}
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
	}
}
