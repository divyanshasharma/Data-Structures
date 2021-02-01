bool solvedSudoku = false;
vector<vector<int> >r(9, vector<int>(10, 0));
vector<vector<int> >c(9, vector<int>(10, 0));
vector<vector<int> >b(9, vector<int>(10, 0));
vector<vector<int> >a(9, vector<int>(9, 0));

bool isValid(vector<vector<int> >&a, int i, int j, int k, vector<vector<int> >&r, vector<vector<int> >&b, vector<vector<int> >&c) {
	if (b[(i / 3) * 3 + (j / 3)][k] == 1) {
		return false;
	}
	if (r[i][k] == 1)return false;
	if (c[j][k] == 1)return false;

	return true;
}
void solveSudoku(vector<vector<int> >&a, vector<vector<int> >&r, vector<vector<int> >&c, vector<vector<int> >&b, int i, int j) {
	if (i == 8 && j == 8 && a[i][j] != 0) {
		solvedSudoku = true;
		return;
	}
	if (a[i][j] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (isValid(a, i, j, k, r, b, c)) {
				a[i][j] = k;
				c[j][k] = 1;
				r[i][k] = 1;
				b[(i / 3) * 3 + (j / 3)][k] = 1;
				if (i == 8 && j == 8)
				{
					solvedSudoku = 1;
					return;
				}
				else if (j == 8)
					solveSudoku(a, r, c, b, i + 1, 0);
				else
					solveSudoku(a, r, c, b, i, j + 1);
				if (solvedSudoku) {
					return;
				}
				else {
					a[i][j] = 0;
					c[j][k] = 0;
					r[i][k] = 0;
					b[(i / 3) * 3 + (j / 3)][k] = 0;
				}
			}
		}
	}
	else {
		if (i == 8 && j == 8) {
			solvedSudoku = true;
			return;
		}
		else if (j == 8)
			solveSudoku(a, r, c, b, i + 1, 0);
		else
			solveSudoku(a, r, c, b, i, j + 1);
	}
}
void solve()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int t;
			cin >> t;
			a[i][j] = t;
			if (t != 0) {
				r[i][t] = 1;
				c[j][t] = 1;
				b[(i / 3) * 3 + (j / 3)][t] = 1;
			}
		}
	}
	solveSudoku(a, r, c, b, 0, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	if (solvedSudoku) {
		cout << "Successfully Solved\n";
	}
	else {
		cout << "Unsuccesssful\n";
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

