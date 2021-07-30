//Question link:
//https://github.com/divyanshasharma/Data-Structures/blob/main/CF/Splitwise%20Transaction%20-Easy%20Convert%20AMEX.pdf
//https://unacademy.com/class/how-to-optimize-a-np-complete-problem-build-own-splitwise/24KPBNJT
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define ar                      array
#define sz(v)                   (int)(v.size())
#define inf                     1e18
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int,best_hash>
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


struct best_hash {
    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void INPUT()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
----------------------------------------------------------------
   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
----------------------------------------------------------------
*/
struct transaction {
    int rec, sen;
    float amt;
    string str = "Dollar";
};
struct expense {
    float exp;
    int p;
};
void upheapify(vector<expense>&heap, int idx) {
    if (idx == 0)return;
    int par = (idx - 1) / 2;
    if (heap[par].exp < heap[idx].exp) {
        swap(heap[par].exp, heap[idx].exp);
        upheapify(heap, par);
    }
    else {
        return;
    }
}
void downheapify(vector<expense>&heap, int idx) {
    //if (idx == 0)return;
    int lc = 2 * idx + 1, rc = 2 * idx + 2;
    int largest = idx;
    if (lc < heap.size() && heap[lc].exp > heap[largest].exp) {
        largest = lc;
    }
    if (rc < heap.size() && heap[rc].exp > heap[largest].exp) {
        largest = rc;
    }
    if (largest == idx)return;
    swap(heap[idx].exp, heap[largest].exp);
    downheapify(heap, largest);
}
void push_heap(vector<expense>&heap, float val, int k) {
    expense e;
    e.p = k;
    e.exp = val;
    heap.push_back(e);
    upheapify(heap, heap.size() - 1);
}
void pop_heap(vector<expense>&heap) {
    if (heap.size() == 0)return ;
    int i = heap.size() - 1;
    auto t = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = t;
    heap.pop_back();
    downheapify(heap, 0);
}
expense heap_top(vector<expense>&heap) {
    expense e;
    e.p = -1;
    e.exp = -1;
    if (heap.size() == 0) {
        return e;
    }
    return heap[0];
}
float minn (float a, float b) {
    if (a > b) {
        return b;
    }
    else
        return a;
}
void solve() {
    int n;
    string aa;
    getline(cin, aa);
    n = stoi(aa);
    map<int, float>m;
    fo(i, 0, n - 1) {
        string a;
        getline(cin, a);
        stringstream s(a);
        transaction t;
        vector<string>v;
        while (s >> a) {
            v.pb(a);
        }
        t.rec = stoi(v[0]);
        t.sen = stoi(v[1]);
        t.amt = std::stof(v[2]);
        t.str = v[3];
        if (v[3] == "Euro") {
            t.amt *= 1.18;
        }
        else if (v[3] == "Rupees") {
            t.amt *= 0.013;
        }
        if (m.find(t.rec) != m.end())
        {
            m[t.rec] -= t.amt;
        }
        else {
            m[t.rec] = -t.amt;
        }
        if (m.find(t.sen) != m.end())
        {
            m[t.sen] += t.amt;
        }
        else {
            m[t.sen] = t.amt;
        }
    }
    vector<expense>pos, neg;
    for (auto i : m) {
        if (i.ss > 0) {
            push_heap(pos, i.ss, i.ff);
        }
        else if (i.ss < 0) {
            push_heap(neg, -1 * i.ss, i.ff);
        }
    }
    vector<transaction>result;
    while (pos.size() > 0) {
        auto p1 = heap_top(pos);
        auto p2 = heap_top(neg);
        pop_heap(pos);
        pop_heap(neg);
        if (p1.p == -1 || p2.p == -1)continue;
        transaction e;
        e.rec = p2.p;
        e.sen = p1.p;
        e.amt = minn(p1.exp, p2.exp);
        result.push_back(e);
        if (p1.exp > p2.exp) {
            push_heap(pos, p1.exp - p2.exp, p1.p);
        }
        else if (p1.exp < p2.exp) {
            push_heap(neg, p2.exp - p1.exp, p2.p);
        }
    }
    cout << result.size() << endl;
    fo(i, 0, result.size() - 1) {
        cout << result[i].sen << " is giving " << result[i].rec << " " << result[i].amt << endl;
    }
}
signed main() {

    FIO
    INPUT();

    int t;
    t = 1;
    //cin >> t;
    fo(i, 0, t - 1) {
        solve();
    }
    return 0;
}

