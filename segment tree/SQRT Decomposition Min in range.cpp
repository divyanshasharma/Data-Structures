//https://www.spoj.com/problems/RMQSQ/
void solve()
{
	int n;
	cin >> n;
	vii a(n);
	fo(i, 0, n - 1) {
		cin >> a[i];
	}
	int bs = sqrt(n);
	int bn = ceil((float)n / (float)bs);
	vii f(bn, INT_MAX);
	for (int i = 0; i < n; i++) {
		f[i / bs] = min(a[i], f[i / bs]);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int m = INT_MAX;
		if ((l / bs) == (r / bs)) {
			for (int i = l; i <= r; i++) {
				m = min(m, a[i]);
			}
			cout << m << endl;
		}
		else {
			int L = l / bs, R = r / bs;
			for (int i = l; i < (L + 1)*bs; i++) {
				m = min(m, a[i]);
			}
			for (int i = L + 1; i < R; i++) {
				m = min(m, f[i]);
			}
			for (int i = R * bs; i <= r; i++) {
				m = min(m, a[i]);
			}
			cout << m << endl;
		}
	}
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

