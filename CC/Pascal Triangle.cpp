//Pascal Triangle 
//Method 1: Binomial Coefficient
int binCo(int n, int m){
    int r=1;
    m=n-m;
    for(int i=0;i<m;i++){
        r*=(n-i);
        r/=(i+1);
    }
    return r;
}
vector<int> Solution::getRow(int m) {
    vector<int>a;
    for(int i=0;i<=m;i++){
        a.push_back(binCo(m,i));
    }
    return a;
}
//https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
//Method 2: Maths
vector<int> Solution::getRow(int m) {
    vector<int>a;
    int n=1;
    for(int i=0;i<=m;i++){
        a.push_back(n);
        n=n*(m-i)/(i+1);
    }
    return a;
}
//Method 3: DP
vector<int> Solution::getRow(int m) {
    vector<int>a;
    int n=1;
    vector<vector<int>>adj(m+1);
    adj[0].push_back(1);
    for(int i=1;i<=m;i++){
        for(int j=0;j<=i;j++){
            if(j<i){
                adj[i].push_back(adj[i-1][j-1]+adj[i-1][j]);
            }
            else{
                adj[i].push_back(adj[i-1][j-1]);
            }
        }
    }
    return adj[m];
}

