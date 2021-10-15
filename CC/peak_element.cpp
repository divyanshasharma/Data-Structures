//https://leetcode.com/problems/find-peak-element/submissions/

    int findPeakElement(vector<int>& nums) {
     // e.g 1 2 1 3 5 6 4
        //aim is to find the peak element means uske side ke saare already sorted honge
        // so we'll apply binary search
        int n=nums.size(),l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return l;
    }

