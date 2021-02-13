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
#define vbb                     vector<bool>
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
#define Mx						50001
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void pr(int n, string o) {
	if (n == 0) {
		cout << o << endl;
		return;
	}
	if(o.size()==0){
		pr(n-1,o+'1');
		pr(n-1,o+'0');
		return;
	}
	if(o[o.size()-1]=='0')
	{
		pr(n-1,o+'1');
	}
	pr(n-1,o+'0');
	
}
void solve()
{
	int g;
	cin >> g ;
	string o = "";
	pr(g, o);
	//cout << o;
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


