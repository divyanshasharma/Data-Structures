void build(int *arr, int *seg, int s, int e, int tidx) {
	if (s == e) {
		seg[tidx] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	build(arr, seg, s, m, 2 * tidx);
	build(arr, seg, m + 1, e, 2 * tidx + 1);
//self work wala part hai ye phle left subtree recursively build kr di ab dono ke root node ko add krke store krli
	seg[tidx] = seg[2 * tidx] + seg[2 * tidx + 1];
	return;
}
void update(int *arr, int *tree, int s, int e, int tidx, int idx, int val) {
// update krne ke liye dhundni hogi values
// jis index prr jana hai vo bda hai ya cjota
	if (s == e) {
		arr[idx] = val;
		tree[tidx] = val;
		return;
	}
	int mid = (s + e) / 2;
	if (idx > mid) {
		update(arr, tree , mid + 1, e, 2 * tidx + 1, idx, val);
	}
	else {
		update(arr, tree , s, mid, 2 * tidx, idx, val);
	}
	tree[tidx] = tree[2 * tidx] + tree[2 * tidx + 1];
	return ;
}
int query(int *tree, int s, int e, int tidx, int l, int r) {
	if (s > r or e < l) //complete outside
	{
		return 0;
	}
	if (s >= l && e <= r) {//complete overlap ka case ho gya
		return tree[tidx];
	}
	int mid = (s + e) / 2;
	int a1 = query(tree, s, mid, 2 * tidx, l, r);
	int a2 = query(tree, mid + 1, e, 2 * tidx + 1, l, r);
	return a1 + a2;
}
void solve()
{
	int n;
	cin >> n;
	int * arr = new int [n];
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
	int *seg = new int[4 * n];
	build(arr, seg, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--) {
		// type 2 is update
		// type 1 is sum or query that we want to perform
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << query(seg, 0, n - 1, 1, l, r) << endl;
		}
		else {
			int i, v;
			cin >> i >> v;
			update(arr, seg, 0, n - 1, 1, i, v);
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
