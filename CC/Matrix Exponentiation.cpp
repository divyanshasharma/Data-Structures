void mull(vvii &a, vvii &m) {
	vvii t(2, vii(2, 0));
	t[0][0] = a[0][0] * m[0][0] + a[0][1] * m[1][0];
	t[0][1] = a[0][0] * m[0][1] + a[0][1] * m[1][1];
	t[1][0] = a[1][0] * m[0][0] + a[1][1] * m[1][0];
	t[1][1] = a[1][0] * m[0][1] + a[1][1] * m[1][1];

	a[0][0] = t[0][0];
	a[1][0] = t[1][0];
	a[0][1] = t[0][1];
	a[1][1] = t[1][1];
	return;
}
void poww(vvii &a, int n) {
	if (n == 0 || n == 1)return;
	poww(a, n / 2);
	mull(a, a);
	if (n % 2) {
		vvii aa(2, vii(2, 0));
		aa[0][0] = 1;
		aa[0][1] = 1;
		aa[1][0] = 1;
		aa[1][1] = 0;
		mull(a, aa);
	}
}
void solve()
{	int n;
	cin >> n;
	if (n == 0 || n == 1)cout << 0;
	else {
		vvii a(2, vii(2, 0));
		a[0][0] = 1;
		a[0][1] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		poww(a, n - 1);
		cout << a[0][0];
	}
}

