
//https://unacademy.com/class/internship-interview-problem-solving-1/BJKDSJHU
//xorPair 
//odd length, make pair (p1,p2)

bool solve() {
	int n, v = 0;
	cin >> n;
	vii a, b;
	map<char, int>m;
	fo(i, 0, n - 1) {
		int y;
		cin >> y;
		v ^= y;
		a.pb(y);
	}
	fo(i, 0, n - 1) {
		int y;
		cin >> y;
		v ^= y;
		b.pb(y);
		m[y]++;
	}
	fo (i, 0, n - 1) {
		if (m.count(v ^ a[i]) > 0) {
			m[a[i]^v]--;
			if (m[a[i]^v] == 0)m.erase(a[i]^v);
		}
		else
			return false;
	}
	return true;
}

