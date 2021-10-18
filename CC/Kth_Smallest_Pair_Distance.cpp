//https://leetcode.com/problems/find-k-th-smallest-pair-distance/
class Solution {
public:
    int count_no_of_pairs_with_abs_diff_less_than_equal_to_mid(vector<int>&a, int n, int mid){
        int res=0;
        for(int i=0;i<n;i++){
            res+=upper_bound(a.begin()+i,a.end(),a[i]+mid)-(a.begin()+i+1);
        }//means mid(distance) tak ki difference dein aise kitne elements ahin hmare pass available
        return res;
    }
    int smallestDistancePair(vector<int>&a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        int low=a[1]-a[0];
        int high=a[n-1]-a[0];
        for(int i=1;i<n-1;i++){
            low=min(low, a[i+1]-a[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(count_no_of_pairs_with_abs_diff_less_than_equal_to_mid(a,n,mid)<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};
