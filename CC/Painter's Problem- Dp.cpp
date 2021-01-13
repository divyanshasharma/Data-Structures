int findMax(int a[], int n, int k) {
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	vii sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		// if only ek hi painter hai
		dp[1][i] = sum[i];
	}
	for (int i = 1; i <= k; i++) {
		dp[i][1] = sum[1];
	}
	for (int i = 2; i <= k; i++) //k painters
	{
		for (int j = 1; j <= n; j++) {
			int best = INT_MAX;
			for (int p = 1; p <= j; p++) {
				best = min(best, max(dp[i - 1][p], sum[j] - sum[p]));
			}
			dp[i][j] = best;
		}
	}
	return dp[k][n];
}
void solve()
{
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << findMax(arr, n, k) << endl;
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

