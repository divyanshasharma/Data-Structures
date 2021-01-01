#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
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
void build(int si , int ss , int se,vector<int>&st,vector<int>&lazy,vector<int>&ar)
{
	if (ss == se)
	{
		st[si] = ar[ss];
		return;
	}

	int mid = (ss + se) / 2;

	build(2 * si , ss , mid,st,lazy,ar);
	build(2 * si + 1 , mid + 1 , se,st,lazy,ar);

	st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si , int ss , int se , int qs , int qe,vector<int>&st,vector<int>&lazy,vector<int>&ar)
{
	if (lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if (ss != se)
			lazy[2 * si] += dx , lazy[2 * si + 1] += dx;
	}

	if (ss > qe || se < qs) return 0;

	if (ss >= qs && se <= qe)
		return st[si];

	int mid = (ss + se) / 2;
	return query(2 * si , ss , mid , qs , qe,st,lazy,ar) + query(2 * si + 1 , mid + 1 , se , qs , qe,st,lazy,ar);
}
void update(int si , int ss , int se , int qs , int qe , int val,vector<int>&st,vector<int>&lazy,vector<int>&ar)
{
	if (lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if (ss != se)
			lazy[2 * si] += dx , lazy[2 * si + 1] += dx;
	}

	if (ss > qe || se < qs) return;

	if (ss >= qs && se <= qe)
	{
		int dx = (se - ss + 1) * val;
		st[si] += dx;

		if (ss != se)
			lazy[2 * si] += val , lazy[2 * si + 1] += val;
		return;
	}

	int mid = (ss + se) / 2;
	update(2 * si , ss , mid , qs , qe , val,st,lazy,ar);
	update(2 * si + 1 , mid + 1 , se , qs , qe , val,st,lazy,ar);

	st[si] = st[2 * si] + st[2 * si + 1];
}


void solve()
{
	int n , q , code , l , r , val;
	cin >> n >> q;
	vector<int>ar(n);
	vector<int >st(4 * n) , lazy(4 * n);

	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	build(1 , 1 , n,st,lazy,ar);

	while (q--)
	{
		cin >> code;
		if (code == 2)
		{
			cin >> l;
			r = l;
			cout << query(1 , 1 , n , l , r,st,lazy,ar) << endl;
		}
		else
		{
			cin >> l >> r >> val;
			update(1 , 1 , n , l , r , val,st,lazy,ar);
		}
	}
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







