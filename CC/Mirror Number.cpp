//https://unacademy.com/class/internship-interview-problem-solving-2/WTBGQE0L

#include <bits/stdc++.h>

#define vs						vector<string>
vs mirror(int n, int size) {
	if (n == 0)return {""};
	if (n == 1)return {"0", "1", "8"};
	vs t = mirror(n - 2, size);
	vs r;
	for (string i : t) {
		if (n != size) {
			r.pb("0" + i + "0");
		}
		r.pb("9" + i + "6");
		r.pb("6" + i + "9");
		r.pb("1" + i + "1");
		r.pb("8" + i + "8");
	}
	return r;
}
void solve()
{
	int n;
	cin >> n;
	vs fd = mirror(n, n);
	fo(i, 0, fd.size() - 1) {
		cout << fd[i] << endl;
	}
}
