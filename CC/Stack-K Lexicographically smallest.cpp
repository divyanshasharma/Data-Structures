#https://binarysearch.com/problems/K-Lexicographically-Smallest-Subsequence
vector<int> solve(vector<int>&a, int k) {
    //vector<int> ans;
    int n=a.size();
    stack<int>s;
    if(k==0)return {};
    for(int i=0;i<n;i++)
    {
    while(!s.empty() && a[s.top()]>a[i] && (s.size()-1 +n-i>=k )) {
        s.pop();
    }
    if (s.empty() || s.size() < k) {
        s.push(i);
    }
    }
    if(s.size()!=k)return {};
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(a[s.top()]);
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
