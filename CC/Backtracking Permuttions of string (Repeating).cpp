unordered_set<string>m;
void perm(string g, int i){
	if(i==g.size()){
		cout<<g<<endl;
		return;
	}
	if(m.count(g))return;
	for(int j=i;j<g.size();j++){
		swap(g[i],g[j]);
		perm(g,i+1);
		swap(g[i],g[j]);
	}
	m.insert(g);
}
void solve()
{
	string g;
	cin >> g ;
	perm(g,0);
}

