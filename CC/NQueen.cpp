int countt = 0;
void display(vvii &g) {
	fo(i, 0, g.size() - 1) {
		fo(j, 0, g.size() - 1) {
			if (g[i][j] == 1)cout << "Q ";
			else cout << ". ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}
bool issafe(vvii &g, int n, int i, int j) {
	if (i >= n || j >= n || i < 0 || j < 0)return 0;
	fo(k, 0, i - 1) {
		if (g[k][j] == 1)
			return false;
	}
	fo(k, 0, j - 1) {
		if (g[i][k] == 1)
			return false;
	}
	for (int x = i - 1, y = j - 1; x >= 0 && y >= 0 ; x--, y--) {
		if (g[x][y])return false;
	}
	for (int x = i - 1, y = j + 1; x >= 0 && y < n ; x--, y++) {
		if (g[x][y])return false;
	}
	return true;
}
void nqueen(vvii &g, int n, int i, int qn) {
	if (i == n) {
		countt++;
		display(g);
		return;
	}
	// we are moving row by row
	// her colunmn prr place krr krkr ke check krr rhe
	// wheteher it is fitting or not
	fo (k, 0, n - 1) {
		if (issafe(g, n, i, k)) {
			g[i][k] = 1;
			nqueen(g, n, i + 1, qn + 1);
			g[i][k] = 0;
		}
	}
	return;
}
void solve() {
	int n;
	cin >> n;
	vvii g(n, vii(n, 0));
	nqueen(g, n, 0,  0);
	cout << countt;
}

