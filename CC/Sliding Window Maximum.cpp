class Solution {
//https://leetcode.com/problems/sliding-window-maximum/submissions/
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int>ans;
        int i=0,n=a.size();

        if(a.size()<=1 )return a;
        deque<int>dq;
        for(;i<k;i++){
            while(!dq.empty() && a[dq.back()]<=a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
            ans.push_back(a[dq.front()]);
        for(;i<n;i++){
            while(!dq.empty() && dq.front()<=(i-k)){
                dq.pop_front();
            }
            while(!dq.empty() && a[dq.back()]<=a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        
            ans.push_back(a[dq.front()]);
        }
        
        return ans;
    }
};
