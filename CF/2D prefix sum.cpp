//https://www.hackerearth.com/problem/algorithm/vaccination-time/
int paths(vector<vii>&v, int l1, int r1, int l2, int r2) {
	int s = 0;
	vector<vii>vis(v.size(), vii(v[0].size(), 0));
	int m = 0;

	return s;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vii> v(n + 1, vii(m + 1, 0)), pre(n + 1, vii(m + 1, 0));
	fo(i, 1, n ) {
		fo(j, 1, m ) {
			cin >> v[i][j];
			v[i][j] = v[i][j] % 2;
			pre[i][j] = v[i][j];
		}
	}

	fo(i, 1, n ) {
		fo(j, 1, m ) {
			pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}
	int nn;
	cin >> nn;

	fo(i, 0, nn - 1) {
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int h = pre[l2][r2] + pre[l1 - 1][r1 - 1] - pre[l2][r1 - 1] - pre[l1 - 1][r2];
		cout << h << endl;
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

