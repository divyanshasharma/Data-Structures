int c = 0;
bool isValid(vector<vector<char>>&a, int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i <= n && j <= m && (a[i][j] == '.'));
}
void pathh(vector<vector<char>>&a, int i, int j, int n, int m, string s) {
	if (!isValid(a, i, j, n, m))return;
	if (i == n && j == m) {
		c++;
		cout << s << endl;
		return;
	}
	if (isValid(a, i + 1, j, n, m))
		pathh(a, i + 1, j, n, m, s + 'D');
	if (isValid(a, i, j + 1, n, m))
		pathh(a, i, j + 1, n, m, s + 'L');
}
void solve()
{
	int g;
	cin >> g ;
	vector<vector<char>>a(g, vector<char>(g, 0));
	fo(i, 0, g - 1) {
		fo(j, 0, g - 1) {
			cin >> a[i][j];
		}
	}
	string s = "";
	pathh(a, 0, 0, g - 1, g - 1, s);
	cout << c << endl;
}

