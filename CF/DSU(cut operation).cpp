/*
undirected graph & some operations
Cut each edge when "Cut query comes

https://unacademy.com/class/dsu-master-class-part-2-offline-queries/0BACQS7N
*/
int get(vector<int>&parent, int a) {
	return (parent[a] == a) ? a : get(parent, parent[a]);
}
void unnion(vii &parent, vii &rank, int a, int b) {
	int s1 = get(parent, a);
	int s2 = get(parent, b);
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
	int n, m, k;
	cin >> n >> m >> k;
	// here no. of edges is m
	//already specified that all edges will be cut ny the end
	vector<pair<int, int> >q1;
	vii parent(n + 1, 0);
	vii rank(n + 1, 1);
	vii q;
	fo(i, 0, n) {
		parent[i] = i;
	}
	while (k--) {
		string s;
		cin >> s;
		if (s == "cut") {
			q.pb(1);
			int a, b;
			cin >> a >> b;
			q1.pb({a, b});
		}
		else {
			q.pb(2);
			int a, b;
			cin >> a >> b;
			q1.pb({a, b});
		}
	}
	reverse(q.begin(), q.end());
	reverse(q1.begin(), q1.end());
	std::vector<string> l;
	fo(i, 0, q.size() - 1) {
		if (q[i] == 1) {
			unnion(parent, rank, q1[i].ff, q1[i].ss);
		}
		else {
			int s1 = get(parent, q1[i].ff);
			int s2 = get(parent, q1[i].ss);
			if (s1 == s2) {
				l.pb("Yes");
			}
			else {
				l.pb("No");
			}
		}
	}
	for (int i = l.size() - 1; i >= 0; i--) {
		cout << l[i] << endl;
	}
}
