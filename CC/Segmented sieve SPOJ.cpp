//https://www.spoj.com/problems/PRIME1/cstart=10
#define Mx						50001
vbb prime(Mx + 1, 0);
vii p;
void prime_generator() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i * i <= Mx; i++) {
		if (prime[i] == 0) {
			int j = i;
			for (j = i * i; j <= Mx; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= Mx; i++) {
		if (prime[i] == 0) {
			p.pb(i);
		}
	}
}
void segsieve(int a, int b) {
	vbb seg(b - a + 1, 0);
	if (a == 1)a++;
	for (int i = 0; p[i]*p[i] <= b; i++) {
		int j = (a / p[i]) * p[i];
		if (j < a)j += p[i];
		for (; j <= b; j += p[i]) {
			if (j != p[i])// if j==p[i] then thodi karenge kuch already hai hi prime ab uske multiples ke liye krna hai
				seg[j - a] = 1;
		}
	}
	for (int i = 0; i < (b - a + 1); i++) {
		if (seg[i] == 0) {
			cout << i + a << " ";
		}
	}
}
void solve()
{
	int a, b;
	cin >> a >> b;
	segsieve(a, b);
	cout << endl;
}
signed main() {

	FIO
	INPUT();

	int t;
	cin >> t;
	//t = 1;
	prime_generator();
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}


