// https://codeforces.com/problemset/problem/1263/D#
void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int get(vii & parent, int a) {
	return (parent[a] == a ? a : get(parent, parent[a]));
}
void unnion(vii &parent, vii &rank, int i, int c) {
	int s1 = get(parent, i);
	int s2 = get(parent, c);
	if (rank[s1] == rank[s2]) {
		rank[s1]++;
	}
	if (rank[s1] > rank[s2]) {
		parent[s2] = s1;
	}
	else {
		parent[s1] = s2;
	}
}

void solve()
{
	int count = 0, n;
	cin >> n;
	vii parent(26, 0);
	vii rank(26, 1);
	vbb total(26, false);
	vbb current(26, false);
	fo(i, 0, 25) {
		parent[i] = i;
	}
	while (n--) {
		string s;
		cin >> s;
		fo(i, 0, 25) {
			current[i] = 0;
		}
		fo(i, 0, s.size() - 1) {
			current[s[i] - 'a'] = true;
		}
		fo(i, 0, 25) {
			if (current[i] == 1) {
				total[i] = 1;
				unnion(parent, rank, s[0] - 'a', i);
			}
		}
	}
	fo(i, 0, 25) {
		if (total[i] == 1 and get(parent, i) == i) {
			count++;
		}
	}
	cout << count << endl;
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







