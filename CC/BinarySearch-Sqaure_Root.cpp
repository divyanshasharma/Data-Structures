https://www.interviewbit.com/problems/square-root-of-integer/
int Solution::sqrt(int n) {
    if (n==0)return 0;
    int lo=1, e=n-1,ans=1;
    while(lo<=e){
        int m=lo+(e-lo)/2;
        if(m==(n/m)){
            ans=m;
            return m;
        }    
        else if(m>(n/m)){
            
            e=m-1;
        }
        else{
            ans=m;
            lo=m+1;
        }
    }
    return ans;
}

