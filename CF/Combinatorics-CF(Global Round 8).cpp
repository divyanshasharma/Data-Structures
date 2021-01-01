

void solve()
{
	int k;
	cin >> k;
	string s = "codeforces";
	vii a(10, 1);
	int l = 0, h = 1;
	while (h < k) {
		int u = a[l % 10];
		a[(l++) % 10]++;
		h = (h / u) * (u + 1);
	}
	l = 0;
	fo(i, 0, 9) {
		while (a[i]) {
			cout << s[i];
			a[i]--;
		}
	}
	cout << endl;
}
signed main() {

	FIO
	INPUT();

	int t;
	//cin >> t;
	t = 1;
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}
