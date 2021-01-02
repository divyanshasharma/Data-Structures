/*https://unacademy.com/class/faang-interview-problems-part-1/FF8CX59W

is it possible to convert one string to another in minimum number of conversions such that converting
 one letter converts all its occurrences 

taking special case of cycle

this is also possible because we can see tha abc->bca using extra character d
abc->dbc->dba->dca->bca
(converting all a to d, all c to a, all b to c & finallt all d to a)
so cycls can be easily solved only is the ttal size of set is less than 26 because we required a dummy variable to carry out conversios
*/
void solve()
{
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << " Possible";
		return;
	}
	if (a.size() != b.size()) {
		cout << "Not Possible\n";
		return;
	}
	unordered_map<char, char>m;
	for (int i = 0; i < a.size(); i++)	{

		if (m.find(a[i]) != m.end() && m[a[i]] != b[i]) {
			cout << "Not Possible\n";
			return;
		}
		m[a[i]] = b[i];
	}
	set<char>s;
	for (auto it = m.begin(); it != m.end(); it++) {
		s.insert(it->second);
	}
	if (s.size() == 26) {
		cout << "Not Possible\n";
		return;
	}
	else {
		cout << "possible\n";
		return;
	}
}
