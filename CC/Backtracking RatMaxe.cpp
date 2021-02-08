//https://www.codechef.com/problems/BPHC03
int totalPaths = 0;
bool issafe(vector<vector<int>>&g, int i, int j , int ei, int ej, vector<vector<bool> >& vis) {
	return (i >= 0 && j >= 0 && i < ( ei + 1) && j < (ej + 1)  && (vis[i][j] == 0) && (g[i][j] == 0));
}
void helper(vector<vector<int>>&g, int i, int j, int ei, int ej, vector<vector<bool> >&vis)
{
	if (i == ei && j == ej) {
		totalPaths++;
		return;
	}
	if (!issafe(g, i , j, ei, ej, vis))return;
	int n = g.size();
	vis[i][j] = 1;
	if ((i + 1 < n) && issafe(g, i + 1, j, ei, ej, vis)) {
		helper(g, i + 1, j, ei, ej, vis);
	}
	if ((j > 0) && issafe(g, i, j - 1, ei, ej, vis)) {
		helper(g, i, j - 1, ei, ej, vis);
	}
	if ((i > 0) && issafe(g, i - 1, j, ei, ej, vis)) {
		helper(g, i - 1, j, ei, ej, vis);
	}
	if ((j + 1 < n) && issafe(g, i, j + 1, ei, ej, vis)) {
		helper(g, i, j + 1, ei, ej, vis);
	}
	vis[i][j] = 0;
	return;
}
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>>g(n, vii(n, 0));
	fo(i, 0, n - 1) {
		fo(j, 0, n - 1) {
			cin >> g[i][j];
		}
	}
	vector<vector<bool> >vis(n, vector<bool>(n, 0));
	helper(g, 0, 0, n - 1, n - 1, vis);
	cout<<totalPaths;
	return;
}

