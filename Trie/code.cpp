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

#include <cstdlib>
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
class trieNode {
public:
	trieNode *left = NULL, *right = NULL;
};
void insertt(int n, trieNode *head) {
	trieNode *curr = head;
	rfo(i, 31, 0) {
		int b = (n >> i) & 1;
		if (b == 0) {
			if (!curr->left) {
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else {
			if (!curr->right) {
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}
int findMaxXor(trieNode *head, int n, int ai) {
	int val = ai;
	trieNode* curr = head;
	int curr_Xor = 0;
	rfo(j, 31, 0) {
		int b = (val >> j) & 1;
		if (b == 0) {
			if (curr->right) {
				curr_Xor += pow(2, j);
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		else {
			if (curr->left) {
				curr_Xor += pow(2, j);
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
	}

	return curr_Xor;
}
void solve()
{
	int n;
	cin >> n;
	int a[n];
	int c = 0;
	int q = INT_MIN;
	trieNode *r = new trieNode();
	fo(i, 0, n - 1) {
		cin >> a[i];
		c ^= a[i];
		insertt(c, r);
		q = max(max(c, q), findMaxXor(r,  n, c));
	}
	cout << q;
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