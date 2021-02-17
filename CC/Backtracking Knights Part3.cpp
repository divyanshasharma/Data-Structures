//https://unacademy.com/class/internship-interview-problem-solving-3/8V2GJ6PV
void printt(vvii &v) {
	int n = v.size();
	fo(i, 0, n - 1) {
		fo(j, 0, n - 1) {
			if (v[i][j]) {
				cout << "K";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}
int c = 0;
bool isSafe(int i, int j, int n, vvii & vis) {
	if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j])return 0;
	if ((i - 1 >= 0) && (j + 2 < n) && vis[i - 1][j + 2]) {
		return false;
	}
	if ((i - 1 >= 0) && (j - 2 >= 0) && vis[i - 1][j - 2]) {
		return false;
	}
	if ((i - 2 >= 0) && (j - 1 >= 0) && vis[i - 2][j - 1]) {
		return false;
	}
	if ((i - 2 >= 0) && (j + 1 < n) && vis[i - 2][j + 1]) {
		return false;
	}
	return true;
}
void knight(int n, int ii, int jj, vvii &vis, int k) {
	if (k == n) {
		c++;
		printt(vis);
		cout << endl << endl;
		return;
	}
	fo(i, ii, n - 1) {
		for (int j = (i == ii) ? jj : 0; j < n; j++) {
			if (isSafe(i, j, n, vis)) {
				vis[i][j] = 1;
				knight(n, i, j, vis, k + 1);
				vis[i][j] = 0;
			}
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	vvii vis(n, vii(n, 0));
	knight(n, 0, 0, vis, 0);
	cout << endl << endl << "No of possibilities are " << c;
}
