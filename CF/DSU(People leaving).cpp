/*

https://unacademy.com/class/dsu-master-class-part-2-offline-queries/0BACQS7N


n persons standing in a row at position  1-n
you can do 2 operations
1) -x: the person at position x left
2) ?x: find the newest person to the right of x that is still standing (not left)
e.g.=  
(i/p) 
5
6
? 1
- 3
? 3
- 2
? 1
? 2

(o/p)
1
4
1
4
*/

int get(vector<int>&parent, int a) {
	return (parent[a] == a) ? a : get(parent, parent[a]);
}
void unnion(vii &parent, int a, int b) {
	// here left is a & right is b

	int s1 = get(parent, a);
	int s2 = get(parent, b);
	// mergng the left to right 
	parent[s1] = s2;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vii curr(n + 1, 0);
	vii parent(n + 1, 0);
	fo(i, 0, n) {
		parent[i] = i;
	}
	while (m--) {
		char s;
		cin >> s;
		if (s == '?') {
			int a;
			cin >> a;
			int kk = get(parent, a);
			if (kk == n + 1) {
				cout << -1 << endl;
			}
			else
				cout << kk << endl;
		}
		else {
			int x;
			cin >> x;
			unnion(parent, x, x + 1);
		}
	}

}
