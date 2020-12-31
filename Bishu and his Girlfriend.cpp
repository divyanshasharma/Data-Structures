/*Problem Link
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/submissions/
*/
void dfs(int f, vector<vector<int> >&v, vector<int> &vis, vector<int> &dis)
{
	if (vis[f])return;
	vis[f] = 1;
	for (int i = 0; i < v[f].size(); i++) {
		{
			if (!vis[v[f][i]])
			{
				dis[v[f][i]] = min(1 + dis[f], dis[v[f][i]]);
				dfs(v[f][i], v, vis, dis);
			}
		}
	}
	return;
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<int> >v(n + 1, vector<int>(0));
	fo(i, 0, n - 2) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int q;
	cin >> q;
	vector<int>vis(n + 1, 0);
	vector<int>dis(n + 1 , INT_MAX);
	int s = INT_MAX;
	dis[0] = 0;
	dfs(0, v, vis, dis);
	int l = INT_MAX;
	int hh = n;
	while (q--) {
		int s;
		cin >> s;
		if (dis[s] < l) {
			l = dis[s];
			hh = s;
		}
		if (dis[s] == l) {

			hh = min(hh, s);
		}
	}
	cout << hh << endl;
}
