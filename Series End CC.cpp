// https://www.codechef.com/problems/ITGUY04
const int N = 100001;
vii dp(N, 0);
void count() {
	fo(i, 1, N) {
		dp[i] = dp[i - 1] + i * i;
	}
}
void solve()
{
    int q;
    cin>>q;
    while(q--){
	int n;
	cin >> n;
	cout << dp[n - 1] << endl;
}
}
