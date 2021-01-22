
void build(vii &seg, vii &a, int s, int e, int tidx) {
	if (s == e) {
		seg[tidx] = a[s];
		return;
	}
	int m = s + (e - s) / 2;
	build(seg, a, s, m, 2 * tidx);
	build(seg, a, m + 1, e, 2 * tidx + 1);
	seg[tidx] = min(seg[2 * tidx], seg[2 * tidx + 1]);
	return;
}
void update(vii &seg, vii &a, int ind, int u, int s, int e, int tidx) {
	if (s == e) {
		seg[tidx] = u;
		a[ind] = u;
		return;
	}
	int m = s + (e - s) / 2;
	if (m >= ind)
		update(seg, a, ind, u, s, m, 2 * tidx);
	else {
		update(seg, a, ind, u, m + 1, e, 2 * tidx + 1);
	}
	seg[tidx] = min(seg[2 * tidx], seg[2 * tidx + 1]);
	return;
}
int query(vii &seg, vii &a, int s, int e, int l, int r, int tidx) {
	if (s > r || l > e)return INT_MAX;
	if (l <= s && r >= e)return seg[tidx];
	int mid = s + (e - s) / 2;
	int a1 = query(seg, a, s, mid, l, r, 2 * tidx);
	int a2 = query(seg, a, mid + 1, e, l, r, 2 * tidx + 1);
	return min(a1, a2);
}
void solve()
{
	int n, q;
	cin >> n >> q;
	vii a(n);
	vii segment(4 * n + 1, INT_MAX);
	fo(i, 0, n - 1)
	cin >> a[i];
	int s = 0, e = n - 1, tidx = 1;
	build(segment, a, s, e, tidx);
	while (q--)
	{
		int ty;
		cin >> ty;
		if (ty == 2)
		{
			int r, l;
			cin >> l >> r;
			l--, r--;
			cout << query(segment, a, s, e, l, r, 1) << endl;
		}
		else {
			int k, u;
			cin >> k >> u;
			k--;
			update(segment, a, k, u, s, e, 1);
		}
	}
}

