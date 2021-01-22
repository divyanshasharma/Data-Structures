//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
 
	int size1 = nums1.size(), size2 = nums2.size();

    if(size1==0 || size2==0)
        return {};
    
    vector<vector<int>> res;
    
    // min priority-queue
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
    set<pair<int,int>> already_entered;
    
    pq.push({nums1[0]+nums2[0], {0,0}});
    already_entered.insert({0,0});
    
    while(!pq.empty() && res.size() < k){
        
        auto top = pq.top();
        pq.pop();
        
        int idx1 = top.second.first, idx2 = top.second.second;
        
        res.push_back({nums1[idx1], nums2[idx2]});
        
        if(idx1 + 1 < size1 && already_entered.count({idx1+1,idx2}) == 0){
            pq.push({nums1[idx1 + 1] + nums2[idx2],{idx1 + 1, idx2}});
            already_entered.insert({idx1+1,idx2});
        }
        
        if(idx2 + 1 < size2 && already_entered.count({idx1,idx2+1}) == 0){
            pq.push({nums1[idx1] + nums2[idx2 + 1],{idx1, idx2 + 1}});
            already_entered.insert({idx1,idx2+1});
        }
        
    }
 
    return res;
}
};
