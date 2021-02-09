#include <bits/stdc++.h>
#include<bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}

/*
----------------------------------------------------------------

   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..

----------------------------------------------------------------*/
bitset<100>c, ld, rd;
int countt = 0;
void display(vvii &g) {
	fo(i, 0, g.size() - 1) {
		fo(j, 0, g.size() - 1) {
			if (g[i][j])
				cout << "Q ";
			else
				cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void nqueen(vvii &g, int r, int n, int q) {
	if (r == n) {
		countt++;
		display(g);
		return;
	}
	for (int i = 0; i < g.size(); i++) {
		if ((!c[i]) && (!ld[r - i + n - 1] ) && (!rd[r + i] )) {
			g[r][i] = 1;
			c[i] = 1;
			ld[(r - i) + n - 1] = 1;
			rd[i + r] = 1;
			nqueen(g, r + 1, n, q + 1);
			g[r][i] = 0;
			c[i] = 0;
			ld[(r - i) + n - 1] = 0;
			rd[i + r] = 0;
		}
	}
}
void solve() {
	int n;
	cin >> n;
	vvii g(n, vii(n, 0));
	nqueen(g, 0, n, 0);
}
signed main() {

	FIO
	INPUT();

	int t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

