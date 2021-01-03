/*
https://unacademy.com/class/dsu-masterclass-part-3-problem-solving/TB36I10B
you got n elements & you have 2 type of queries
Type 1:(x,y)  Merge them in same group
Type 2: (x) return the max, min & total size from the group in which x belongs
*/
int get(vector<int>&parent, int a) {
	return (parent[a] == a) ? a : get(parent, parent[a]);
}
void unnion(vii &parent, vii &rank, vii &min_, vii &max_, vii &size_, int a, int b) {
	// here left is a & right is b

	int s1 = get(parent, a);
	int s2 = get(parent, b);
	// mergng the left to right
	if (rank[s1] == rank[s2]) {
		rank[s1]++;
	}
	if (rank[s1] > rank[s2]) {
		parent[s2] = s1;
		size_[s1] = (size_[s1] + size_[s2]);
		max_[s1] = max(min_[s1], min_[s2]);
		min_[s1] = min(min_[s1], min_[s2]);
	}
	else {
		parent[s1] = s2;
		size_[s2] = (size_[s1] + size_[s2]);
		max_[s2] = max(min_[s1], min_[s2]);
		min_[s2] = min(min_[s1], min_[s2]);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vii rank(n + 1, 1);
	vii parent(n + 1, 0);
	vii min_(n + 1, INT_MAX);
	vii size_(n + 1, 1);
	vii max_(n + 1, INT_MIN);
	fo(i, 0, n) {
		parent[i] = i;
		min_[i] = i;
		max_[i] = i;
	}
	while (m--) {
		int s;
		cin >> s;
		if (s == 1) {
			int a, b;
			cin >> a >> b;
			unnion(parent, rank, min_, max_, size_, a, b);
		}
		else {
			int a;
			cin >> a;
			int x = get(parent, a);
			cout << min_[x] << " " << max_[x] << " " << size_[x] << "\n";
		}
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

