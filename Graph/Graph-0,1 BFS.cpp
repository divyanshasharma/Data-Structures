//https://www.interviewbit.com/problems/min-cost-path/
//https://unacademy.com/class/graph-interview-problems-part-2/UUUUVBUH
struct triplet{
    int x, y, wt;
};
int Solution::solve(int A, int B, vector<string> &C) {

int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};
set<pair<int, int>>visited;
    deque<triplet>qu;
    qu.push_front({0,0,0});
    while(!qu.empty()){
        auto t=qu.front();
        qu.pop_front();
        if(t.x==A-1 && t.y==B-1)return t.wt;
        if(visited.count({(t.x), (t.y)}))continue;
        visited.insert({t.x,t.y});
        for(int i=0;i<=3;i++){
        if(((t.x+xx[i])<0) || ((t.y+yy[i])<0) || ((t.x+xx[i])>=A) || ((t.y+yy[i])>=B))continue;
        if(visited.count({(t.x+xx[i]), (t.y+yy[i])}))continue;
        int c=0;
        if(C[t.x][t.y]=='U' && xx[i]==-1 && yy[i]==0){
            c=0;
        }
        else if(C[t.x][t.y]=='D' && xx[i]==1 && yy[i]==0){
            c=0;
        }
        else if(C[t.x][t.y]=='R' && xx[i]==0 && yy[i]==1){
            c=0;
        }
        else if(C[t.x][t.y]=='L' && xx[i]==0 && yy[i]==-1){
            c=0;
        }
        else{
            c=1;
        }
        if(c==0)
            qu.push_front({t.x+xx[i],t.y+yy[i],t.wt+c});
        else{
            qu.push_back({t.x+xx[i],t.y+yy[i],t.wt+c});
        }
        }
    }
    return -1;
}

