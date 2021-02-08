void Print_subset(vii &g, int i, int n, vii &tem) {
	if (i == n) {
		if (tem.size() > 0) {
			fo(j, 0, tem.size() - 1) {
				cout << tem[j] << " ";
			}
			cout << endl;
		}
		return;
	}
	tem.push_back(g[i]);
	Print_subset(g, i + 1, n, tem);
	tem.pop_back();
	Print_subset(g, i + 1, n, tem);
}
void solve()
{
	int n;
	cin >> n;
	vector<int>g(n, 0);
	fo(i, 0, n - 1) {
		cin >> g[i];
	}
	vii tem;
	Print_subset(g, 0, n, tem);
	return;
}
