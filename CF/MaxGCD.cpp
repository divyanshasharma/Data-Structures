
//https://codeforces.com/problemset/problem/75/C
void solve()
{
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int g = __gcd(a, b);
	vii div;
	fo(i, 1, sqrt(g)) {
		if (g % i == 0) {
			div.pb(i);
			if ((i * i) != g) {
				div.pb(g / i);
			}
		}
	}
	while (n--) {
		int l, r;
		cin >> l >> r;
		int s = -1;
		fo(i, 0, div.size() - 1) {
			if (div[i] >= l && div[i] <= r) {
				s = max(s, div[i]);
			}
		}
		cout << s << endl;
	}
}
