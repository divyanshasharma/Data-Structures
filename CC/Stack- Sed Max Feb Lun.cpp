//https://www.codechef.com/problems/SEDMAX
void solve() {
	int n;
	cin >> n;
	vii arr(n, 0);
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
	set<pair<int, int>>p;
	stack<int>s;
	s.push(arr[0]);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && arr[i] > s.top()) {
			p.insert(mp( arr[i], s.top()));
			s.pop();
		}
		if (!s.empty()) {
			p.insert(mp(max(s.top(), arr[i]), min(s.top(), arr[i])));
		}
		s.push(arr[i]);
	}
	set<int>l;
	for (auto t = p.begin(); t != p.end(); t++) {
		l.insert(t->ff - t->ss);
	}
	// for (auto t = l.begin(); t != l.end(); t++) {
	// 	cout << *t << " ";
	// }
	cout << l.size() << endl;
}
signed main() {
	FIO
	INPUT();
	int t;
	cin >> t;
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}

