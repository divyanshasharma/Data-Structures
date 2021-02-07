//https://codeforces.com/problemset/problem/86/D
struct qu {
	int in, l, r;
};
#define BLC 500
bool cmp(qu as, qu b) {
	if (as.l / BLC != b.l / BLC) {
		return (as.l / BLC) < (b.l / BLC);
	}
	return as.r < b.r;
}
int ml = 0, mr = -1, c = 0, s = 0;
vii freq(1000005, 0), ans(200005, 0), a(200005, 0);
void add(int l) { 
	s -= (freq[a[l]] * freq[a[l]] * a[l]);
	freq[a[l]]++;
	s += (freq[a[l]] * freq[a[l]] * a[l]);
}
void remove(int r) {
	s -= (freq[a[r]] * freq[a[r]] * a[r]);
	freq[a[r]]--;
	s += (freq[a[r]] * freq[a[r]] * a[r]);
}
void solve()
{
	int n, q;
	cin >> n >> q;
	fo(i, 0, n - 1) {
		cin >> a[i];
	}
	vector<qu>qp(q);
	fo(i, 0, q - 1) {
		qp[i].in = i;
		cin >> qp[i].l >> qp[i].r;
		qp[i].l--;
		qp[i].r--;
	}
	sort(qp.begin(), qp.end(), cmp);
	fo(i, 0, q - 1) {
		int y = qp[i].l;
		int yy = qp[i].r;
		while (ml > y) {
			ml--;
			add(ml);
		}
		while (ml < y) {
			remove(ml);
			ml++;
		}
		while (mr > yy) {
			remove(mr);
			mr--;
		}
		while (mr < yy) {
			mr++;
			add(mr);
		}

		ans[qp[i].in] = s;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
}
signed main() {

	FIO
	INPUT();

	int t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

