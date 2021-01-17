//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
bool dfs(int i, vector<int>&v, vector<int> adj[], int u ){
	if(v[i])return 1;
	v[i]=1;
	for(int j=0;j<adj[i].size();j++){
		if(v[adj[i][j]]==0){
			bool l= dfs(adj[i][j],v,adj,i);
			if(l)return 1;}
		else if(adj[i][j]!=u)return 1;
	}
	return 0;
}
bool isCyclic( vector<int> adj[],int V)
{
	vector<int>vis(V,0);
	for(int i=0;i<V;i++){
		if(vis[i]==0){
			bool l= dfs(i,vis,adj,-1);
			if(l)return 1;
		}
	}
	return 0;
}


