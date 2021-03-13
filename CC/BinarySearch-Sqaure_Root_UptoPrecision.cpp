
void sq(int n) {
	ll l = 0, hi = n - 1;
	while (l < hi) {
		ll m = l + (hi - l) / 2;
		if (m * m == n) {
			l = m;
			break;
		}
		if (m * m > n) {
			hi = m - 1 ;
		}
		else {
			l = m ;
		}
	}
	// incrementing for 6 digit
	ld in = 0.1, s = l, d = 1;
	fo(i, 0, 5) {
		while (s * s <= n) {
			s += in;
		}
		s -= in;
		in /= 10;
	}
	cout << s << endl;
}
void solve()
{
	int n;
	cin >> n;
	sq(n) ;
}
// TC
5
81
72
64
625
36
