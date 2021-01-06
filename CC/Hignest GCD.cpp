//https://www.codechef.com/problems/GCDDIV
int largest_divisor_of_g(int n) {
	int r = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			r = i;
			while (n % i == 0) {
				n = n / i;
			}
		}
	}
	if (n != 1) {
		r = n;
	}
	return r;
}
void solve()
{
	int n, k;
	cin >> n >> k ;
	vii a(n, 0);
	int g = 0; //don't take it as once else ANSWER HAMESHA 1 HI AAEGA
	fo(i, 0, n - 1) {
		cin >> a[i];
		g = __gcd(a[i], g);
	}
	int y = largest_divisor_of_g(g);
	if (y <= k)
		cout << "YES\n";
	else {
		cout << "NO\n";
	}

}
signed main() {

	FIO
	INPUT();

	int t;
	cin >> t;
	//t = 1;
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}


