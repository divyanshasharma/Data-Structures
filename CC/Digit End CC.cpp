//https://www.codechef.com/problems/ANITGUY9
void solve()
{
	int n , q ;
	cin >> n ;

	while (n--)
	{
		cin >> q;
		int s = 0, h = q;
		while (h > 0) {
			s += h % 10;
			h = h / 10;
		}
		if (q % s != 0) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
		}
	}
}
