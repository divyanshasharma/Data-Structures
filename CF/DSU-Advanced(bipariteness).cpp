pii get( vii & parent, vii &parity, int a)// this function will return the parent & parity
{
	// prity is (distance covered to move from a to its group's leader) %2
	if ( parent[a] == a) {
		return { a, 0}; //becasuse vo khud hi parent hai khudka
	}
	pii v = get(parent, parity, parent[a]);
	parent[a] = v.ff;
	parity[a] = (parity[a] + v.ss) % 2; //khudki parity + parent ki leader tak jane ki parity
	return {parent[a], parity[a]};
	//returning the parent & the parity
	}
}
void Union(vii & parent, vii & size, vii & parity, int a, int b) {
// isme hme ek edge add krni hai
	pii v1 = get(parent, parity, a);
	pii v2 = get(parent, parity, b);
	//v2.ff hai ye parent hai b ka & v2.ss jo hai vo parity hai b ki
	if (size[v2.ff] > size[v1.ff]) {
		swap(v1, v2); // because hamesha bde size me chota add krna
	// by inverse acyrman.. log*n
	}
	size[v1.ff] += size[v2.ff];
	parent[v2.ff] = parent[v1.ff];
// as parity of big one wont change only small wale ki change hogi bz we are adding it
	parity[v2.ff] = (v1.ss + 1 + v2.ss) % 2; //updating diztance
// kyuki ek edge add krdene se parity change ho gyi hai
	//v1.ss is a ki parity from its leader
}
void solve()
{
	//check the bipartiteness
	int n;
	cin >> n;
	int m;
	cin >> m;
	vii parent(n + 1, 0), parity(n + 1, 0), size(n + 1, 0);
	fo(i, 0, n) {
		parent[i] = i;
	}
	while (m--) {
		int a, b, c;
		cin >> c >> a >> b;
		if (c == 1) {
			Union(parent, size, parity, a, b);
		}
		else {

			pii ab = get(parent, parity, b);
			pii aa = get(parent, parity, a);
			if (ab.ss == aa.ss) {
				cout << "Yes they are in same set\n";
			}
			else {
				cout << "No they are in differernt set\n";
			}
		}
	}
}
