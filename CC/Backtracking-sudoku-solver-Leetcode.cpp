//https://leetcode.com/problems/sudoku-solver/submissions/
#define vii vector<int>
#define pb push_back
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define vvii vector<vector<int> >
class Solution {
public:
    bool issudoku=false;
    void solver(vector<vector<char>>&a, vvii &r, vvii &c, vvii &b, int i, int j){
        int n=a.size();
        int h=0;
        if(a[i][j]!='.')
        h=(a[i][j]-'0');
        if(i==n-1 && j==n-1 && a[i][j]!='.'){
            issudoku=true;
            return ;
        }            
        if(a[i][j]=='.'){
            for(int k=1;k<=n;k++){
                if(!r[i][k] && !c[j][k] && !b[(i/3)*3+(j/3)][k]){
                    a[i][j]=char(k+'0');
                    r[i][k]=1;
                    c[j][k]=1;
                    b[(i/3)*3+(j/3)][k]=1;
                    if(i==n-1 && j==n-1){
                        issudoku=true;
                        return;
                    }
                    if(j!=n-1)
                        solver(a,r,c,b,i,j+1);
                    else
                        solver(a,r,c,b,i+1,0);
                    if(issudoku)
                    return;
                    else{
                        a[i][j]='.';
                        r[i][k]=0;
                        c[j][k]=0;
                        b[(i/3)*3+(j/3)][k]=0;
                    }
                }
            }
        }
        else{
            if(j==n-1){
                solver(a,r,c,b,i+1,0);
            }
            else
                solver(a,r,c,b,i,j+1);
            
            if( issudoku==true)
                return ;
            
        }
    }
    
    void solveSudoku(vector<vector<char>>& a) {
        int n=a.size();
        vvii r(n,vii(n+1,0)),c(n,vii(n+1,0)),b(n,vii(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='.'){
                    continue;
                }
                else{
                    r[i][(a[i][j]-'0')]=1;
                    c[j][(a[i][j]-'0')]=1;
                    b[(i/3)*3+(j/3)][(a[i][j]-'0')]=1;
                }
            }
        }
        issudoku=false;
        solver(a,r,c,b,0,0);
        if(issudoku){
            return ;
        }
        vector<vector<char>> ch;
        a=ch;
        return ;
    }
};
