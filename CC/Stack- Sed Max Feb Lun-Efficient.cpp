//https://discuss.codechef.com/t/sedmax-editorial/86099/6
void solve() {
	int n;
	cin >> n;
	vector<pii> arr(n);
	set<int>maxIndex, ans;
	vii a(n);
	fo(i, 0, n - 1) {
		cin >> a[i];
		arr[i].ff = a[i];
		arr[i].ss = i;
	}
	sort(arr.rbegin(), arr.rend());
	fo(i, 0, n - 1) {
		int val = arr[i].ff;
		int idx = arr[i].ss;
		//cout << arr[i].ff << " " << arr[i].ss << " \n";
		auto y = maxIndex.lower_bound(idx);
		if (y != maxIndex.end()) {
			ans.insert(a[*y] - val);
		}
		//cout << *y << " ";
		if (y != maxIndex.begin()) {
			y--;
			ans.insert(a[*y] - val);
		}
		maxIndex.insert(idx);
	}
	cout << ans.size() << endl;
}
signed main() {
	int t;
	cin >> t;
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}

