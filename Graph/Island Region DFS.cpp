
bool corr(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m)return false;
    return true;
}

int xx[]={0, 0,1,-1,1,1,-1,-1};
int yy[]={1,-1,0,0 ,1,-1,1,-1};

void dfs(vector<vector<int> > &a,vector<vector<int> > &vis,int i, int j, int  r, int & h){

    if(vis[i][j])return;
h++;
    vis[i][j]=1;
   // cout<<i<<" "<<j<<" "<<h<<endl;
    int n=a.size(),m=a[0].size();
    for(int k=0;k<8;k++){
        if(corr(i+xx[k],j+yy[k],n,m)){
            if(a[i+xx[k]][j+yy[k]])
            dfs(a,vis,i+xx[k],j+yy[k],r+1,h);
        }
    }
} 
int Solution::solve(vector<vector<int> > &a) {

    int k=0,v=0;
    vector<vector<int> >vis(a.size(),vector<int>(a[0].size(),0));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            if(a[i][j]==1 && !vis[i][j]){
                int h=0;
                dfs(a,vis,i,j,1,h);
                k=max(k,h);
                //cout<<"--------"<<v++<<endl;
            }
        }
    }
    
    return k;
}


