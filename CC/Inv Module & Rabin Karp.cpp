//https://www.spoj.com/status/ns=27397470
#include <bits/stdc++.h>
int dp[1000001];
int inv[1000001];
int getHash(string h) {
	int r = 0, p = 31, p_power = 1;
	for (int i = 0; i < h.size(); i++) {
		r = (r + (h[i] - 'a' + 1) * p_power) % mod;
		p_power = (p_power * p) % mod;
	}
	return r;
}
int substringHash(int l, int r) {
	int res = dp[r];
	if (l > 0)res = (res - dp[l - 1] + mod) % mod;
	res = (res * inv[l]) % mod;
	return res;
}
int power(int a, int n) {
	int r = 1;
	while (n) {
		if (n & 1)r = (r * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return r;
}
void init(string a) {
	dp[0] = (a[0] - 'a' + 1);
	int p = 31;
	inv[0] = 1;
	int p_power = p;
	for (int i = 1; i < a.size(); i++) {
		dp[i] = (dp[i - 1] + (a[i] - 'a' + 1) * p_power) % mod;
		inv[i] = power(p_power, mod - 2) % mod;
		p_power = (p_power * p) % mod;
	}
	return;
}
void solve(int n)
{
	string a, pat;
	fflush(stdin);
	cin >> pat;
	fflush(stdin);
	cin >> a;
	if (pat.size() > a.size()) {
		cout << endl;
		return;
	}
	init(a);
	int patHash = getHash(pat);
	for (int i = 0, j = pat.size() - 1; j < a.size(); i++, j++) {
		if (patHash == (substringHash(i, j))) {
			cout << i << endl;
		}
	}
	cout << endl;
	return;
}
signed main() {

	FIO
	INPUT();

	int t;
	//cin >> t;
	while (cin >> t)
	{
		solve(t);
	}
	return 0;
}

