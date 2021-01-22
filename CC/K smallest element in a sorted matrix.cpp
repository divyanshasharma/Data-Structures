//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
// same logic used of K smallest sorted prime function
// all are K Ordered statistics
class Solution {
public:
      struct frac{
        int val, i,j;
    };
    class cmp{
        public:
        bool operator()(const frac &a, const frac &b){
            return a.val>b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<frac, vector<frac>, cmp>pq;
        for(int i=0;i<matrix.size();i++){
            frac f;
            f.val=matrix[i][0];
            f.i=i;
            f.j=0;
            pq.push(f);
        }
        while(k>1){
            k--;
            auto t=pq.top();
            pq.pop();
            if(t.j==matrix[t.i].size()-1){
                continue;
            }
            else{
                frac f;
                f.val=matrix[t.i][t.j+1];
                f.i=t.i;
                f.j=t.j+1;
                pq.push(f);
            }
        }
        return pq.top().val;
    }
};
