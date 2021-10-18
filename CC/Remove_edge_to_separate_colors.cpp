https://unacademy.com/class/graph-interview-problems-part-1/B9V2XRWD
int n=100005;
list<int>graph[n];
vii colors(n);
int ans;
pii dfs(int src, int parent=-1){
	int r=(colors[src]=='A'), b=(colors[i]=='B');
	//count of blue & red in subtree
	for(Auto neighbour: graph[src]){
		if(neighbour!=parent){
			pii result=dfs(neighbur, src);
			ans+=(result.ss==countBlue ans result.ff==0);
			ans+=(result.ff==countRed ans result.ss==0);
			r+=result.ff;
			b+=result.ss;
		}
	}
	return {r,b};//return whole count
}
void solve()
{
	cin >> n;
	int countRed=0,countBlack=0;
	fo(i,0,n-1){
		char color;
		cin>>color;
		colors[i]=color;
		if(color=='A')
			countRed+=1;
		
		if(color=='B')
			countBlue+=1;
	}
	ans=0;
	fo(i,0,n-1){
		int u,v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	cout<<ans;//edges to be removed;
}


