//Number of Sublists With Odd Sum
//https://binarysearch.com/room/DJ-Ijkstra-OSTG6TsiNu?questionsetIndex=1
#define mod 1000000007
#define vii vector<int>
int solve(vector<int>& a) {
    int s=0,odd=0,even=1,ans=0;
    for(int i=0;i<a.size();i++){
        s=(s+a[i])%mod;
        ans=(ans+(s&1?even:odd))%mod;
        if(s&1)odd++;
        else even++;
    }
    return ans;
}
