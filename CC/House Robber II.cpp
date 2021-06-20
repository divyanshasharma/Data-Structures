class Solution {
public:
    int maxutil(vector<int>&a, int l, int r){
        int s=0;
        if(r<l)return INT_MIN;
        if(l==r)return a[l];
        if(r==(l+1))return max(a[r],a[l]);
        vector<int>dp(r-l+2,0);
        dp[0]=a[l];
        dp[1]=max(a[l],a[l+1]);
        for(int i=2;i<=(r-l);i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i+l]);
        }
        return max(dp[r-l-1],dp[r-l]);
    }
    int rob(vector<int>& a) {
        int n=a.size();
        if(n<=3)return *max_element(a.begin(),a.end());
        return max(maxutil(a,0,n-2),maxutil(a,1,n-1));
    }
};
