struct Edge {
	int s, d, wt;
};
bool cmp(Edge a, Edge b) {
	return a.wt < b.wt;
}
int get(vii & parent, int a) {
	if (parent[a] == a)return a;
	return get(parent, parent[a]);
}
void Union(vii & parent, vii & rank, int a, int b) {
	int aa = get(parent, a) ;
	int bb = get(parent, b) ;
	if (rank[aa] == rank[bb]) {
		rank[aa]++;
	}
	if (rank[aa] > rank[bb]) {
		parent[bb] = aa;
	}
	else {
		parent[aa] = bb;
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	Edge *e = new Edge [m];
	int o = 0;
	vii rank(n + 1, 1);
	vii parent(n + 1, 0);
	fo(i, 0, n) {
		parent[i] = i;
	}
	fo(i, 0, m-1) {
		int a, b, c;
		cin >> a >> b >> c;
		e[i].s = a;
		e[i].d = b;
		e[i].wt = c;
	}
	sort(e, e + m, cmp);
	int count = 0, i = 0;
	while (count < n - 1) {
		int y1 = get(parent, e[i].s);
		int y2 = get(parent, e[i].d);
		if (y1 != y2) {
			Union(parent, rank, e[i].s, e[i].d);
			o += e[i].wt;
			count++;
		}
		i++;
	}
	cout << o;
}





