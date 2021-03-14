//https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/discuss/912186/C%2B%2B-Binary-Search-with-explanation
 int enough(int m, int n, int mid){
        int count = 0;
        
        /*
        how to find how many elements are less than mid ??
        The basic idea is ith row is a multiple of (1,2,3,4,5,6,7,8,9,10)
        so divide the  number (mid) by ith row and you will get the number samller than mid in the multiplication table.
		it should be min(mid/i, n) -- why min ??  because we have given n columns, and we need to find smallest in the given range 
       
        for each row we need to check if how many elements are less than mid.
        for eg
        row1: 1   2   3   4   5   6     7   8   9     10
        row2: 2   4   6   8   10  12   14   16  18    20
        row3: 3   6   9   12  15  18   21   24  27    30
        mid = 15
        count += min(15/1, 10) = 10 (in row 1 less than 15 = 10) count = 10
        count += min(15/2, 10) = 7 (in row 2 elm less than 15 = 7) count = 17
        count += min(15/3, 10) = 5 (in row 2 elm less than 15 = 7) count = 22
        count is greater than k (18) : It means we are too much on the right side, move left.
	
        */
        for(int i = 1; i<=m; ++i){
            count += min(mid/i, n);
        }
        
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        // lets say m = 3 , n= 10, k = 18
        int start = 0;
        int end = m*n;
        while(start <= end){
            int mid  = start + (end - start)/2;
            
            //mid = 15
            // 1----------------15-----------------30
            // count = 22
            // 22 > k need to move left;
			//continue, in the same way now.
            
            if(enough(m,n,mid) >= k)
                end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }
