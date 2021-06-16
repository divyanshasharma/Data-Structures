//https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1#
long long subCount(long long arr[], int N, long long K)
	{
	    vector<long long>a(K,0);
	    int s=0;
	    for(int i=0;i<N;i++){
	        s+=arr[i];
	        a[(s%K+K)%K]++;
	    }
	    long long int ans=0;
	    for(int i=0;i<K;i++){
	        if(a[i]>1)
	        ans+=(a[i]*(a[i]-1))/2;
	    }
	    ans+=a[0];
	    return ans;
	}

