//https://www.codechef.com/problems/AMCS03
int n, k;
vii s;
vii d;
double f(double mid)
{
	double mini = 1e11;
	double maxi = 0;
	for (int i = 0; i < n; i++)
	{
		mini = min(mini, s[i] * mid + d[i]);
		maxi = max(maxi, s[i] * mid + d[i]);
	}
	return maxi - mini;
}
void solve()
{

	cin >> n >> k;
	s.resize(n), d.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i] >> d[i];
	double low = 0.0;
	double high = k;
	for (int _ = 0; _ < 80; _++)
	{
		double mid1 = low + (high - low) / 3.0;
		double mid2 = high - (high - low) / 3.0;
		if (f(mid1) >= f(mid2))
			low = mid1;
		else
			high = mid2;
	}
	cout << fixed << setprecision(6) << f(low) << endl;
}
