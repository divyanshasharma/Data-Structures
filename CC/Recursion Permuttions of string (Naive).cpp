void permutationss(string a,  string osf) {
	if (a.size() == 0) {
		cout << osf << endl;
		return;
	}
	for (int i = 0; i < a.size(); i++)
		permutationss(a.substr(0, i) + a.substr(i + 1), osf + a[i]);
}
void solve()
{
	string a;
	cin >> a;
	string h = "";
	permutationss(a, h);
}
