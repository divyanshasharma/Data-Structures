//https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0#


int R, C;
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool dfs(vector<vector<char>> &g, int i, int j, string &s) {
    int row=i, col=j;
	for (int ii = 0; ii < 8; ii++) {
		int cu = 1;
		i=row;
		j=col;
		for ( cu = 1; cu < s.size(); cu++) {
		    if(((i+x[ii])<0) || ((i+x[ii])>=g.size())||((j+y[ii])<0) || ((j+y[ii])>=g[0].size()))break;
		    if (g[i + x[ii]][j + y[ii]] != s[cu]) {
				break;
			}
			else {
			    i=i+x[ii];
			    j=j+y[ii];
			}
		}
		if (cu == s.length())return true;
	}
	return false;
}
void solve(vector<vector<char>>&g, string s) {
	int f = 0;
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[0].size(); j++) {
			if (g[i][j] == s[0]) {
				auto r = dfs(g, i, j, s);
				if (r) {
					f = 1;
					cout << i << " " << j << ", ";
				}
			}
		}
	}
	if (f == 0) {
		cout << -1;
	}
}
int main() {

	int t;
	cin >> t;
	//t = 1;
	fo(i, 0, t - 1)
	{
		cin >> R >> C;
		vector<vector<char>> grid(R, vector<char>(C)) ;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> grid[i][j];
			}
		}
		string s;
		cin >> s;
		solve(grid, s);
		cout << endl;
	}
	return 0;
}


