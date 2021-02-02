////https://leetcode.com/problems/sliding-window-maximum/submissions/

class Solution {
public:
    void build(vector<int>&seg, vector<int>&a, int s, int e, int tidx){
        if(s==e){
            seg[tidx]=a[s];
            return;
        }
        int mid=s+(e-s)/2;
        build(seg, a, s, mid, 2*tidx);
        build(seg, a, mid+1,e, 2*tidx+1);
        seg[tidx]=max(seg[2*tidx],seg[2*tidx+1]);
        return;
    }
    int query(vector<int>&a,vector<int>&seg,int s, int e,int l ,int r, int tidx ){
        if(e<l || s>r)return INT_MIN;
        if(l<=s && r>=e){
            return seg[tidx];
        }
        int mid=s+(e-s)/2;
        int a1=query(a,seg,s,mid, l, r, 2*tidx);
        int a2=query(a,seg,mid+1, e, l, r, 2*tidx+1);
        return max(a1,a2);
    }
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int>ans,seg(4*n+1);
        build(seg,a,0,n-1,1);
        for(int i=0;i<=n-k;i++){
            ans.push_back(query(a,seg,0,n-1,i,i+k-1, 1));
        }
        return ans;
    }
};
