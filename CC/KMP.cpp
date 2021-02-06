//https://practice.geeksforgeeks.org/problems/760a2a0627f1abf231de42b93bb71825ecbcb3b4/1/?track=30-DOC-day-12&batchId=320
	int lps(string s)
	{
	    vector<int>f(s.size()+1,0);
	    for(int i=1;i<s.size();i++){
	        int j=f[i-1];
	        while(j>0 && (s[i]!=s[j])){
	            j=f[j-1];
	        }
	        if(s[i]==s[j])j++;
	        f[i]=j;
	    }
	    int t=f[s.size()-1];//*max_element(f.begin(),f.end());
	    return t;
	}
