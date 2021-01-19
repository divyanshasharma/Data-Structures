//https://www.interviewbit.com/problems/region-in-binarymatrix/
//BFS Not Optimized
struct lpl{
    int ff,ss,tt;
};
bool corr(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m)return false;
    return true;
}

int xx[]={0,0,1,-1,1,1,-1,-1};
int yy[]={1,-1,0,0,1,-1,1,-1};
 int Solution::solve(vector<vector<int> > &a) {
   int k=0;
    queue<lpl>q;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){  int r=0;
            if(a[i][j]==1){
                int s=0;
                q.push({i,j,1});
           vector<vector<int> > vis(a.size(),vector<int>(a[0].size(),0));
             while(!q.empty()){
        auto t=q.front();
        q.pop();
        r=max(r,t.tt);
        if(vis[t.ff][t.ss])continue;
//        cout<<t.ff<<" "<<t.ss<<endl;
        vis[t.ff][t.ss]=1;
          s++;
        for(int i=0;i<8;i++){
            if(corr(xx[i]+t.ff,yy[i]+t.ss,a.size(),a[0].size())){
            if(a[xx[i]+t.ff][yy[i]+t.ss])
                q.push({xx[i]+t.ff,yy[i]+t.ss,t.tt+1});
            }
        }
    }
   k=max(k,s);
                
            }
        }
    }
return k;
    
}

