//https://www.spoj.com/problems/DIVFACT/
vbb prime(Mx + 1, 0);
vii prime_nos;
void prime_generator() {
	prime[0] = prime[1] = 1; //as they aren't primt
	for (int i = 2; i * i <= Mx; i++) {
		if (prime[i] == 0) {
			//3 conditions yaad rkhni hain
			//1. i*i ka loop sqrt n tak chaalan hai
			//2. j ko start i*i se krna hai
			//3. Increment krna hai by i
			for (int j = i * i; j <= Mx; j += i) {
				prime[j] = 1;
			}
		}
	}
	fo(i, 2, Mx) {
		if (prime[i] == 0) {
			prime_nos.pb(i);
		}
	}
}
int divisors_of_factorial(int n) {
	int r = 1; // as we know hme sabki occurrences store krni hai & multuply krta jana hai
	for (int i = 0; prime_nos[i] <= n; i++) {
		int k = prime_nos[i];
		//n/k as always floor values leni hai
		int c = 0; // to store the count of its power
		while (n / k) //sare cases le lo e.g. 2, 4, 8, 16 so on
		{
			c += n / k;
			k = k * prime_nos[i]; //raise the power
		}
		r = (r % mod) * (c + 1) % mod;
	}
	return r;
}
void solve()
{
	int g;
	cin >> g ;
	cout << divisors_of_factorial(g) << endl;

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


