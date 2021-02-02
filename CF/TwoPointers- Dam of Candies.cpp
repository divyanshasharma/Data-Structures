//https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1/?track=30-DOC-day-8#
  int maxCandy(int height[], int n) 
    { 
        vector<pair<int, int> >v;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            v.push_back(make_pair(height[i],i));
        }
        sort(v.begin(),v.end() );
        l[n-1]=v[n-1].second;
        r[n-1]=v[n-1].second;
        for(int i=n-2;i>=0;i--){
            l[i]=min(l[i+1],v[i].second);
            r[i]=max(r[i+1],v[i].second);
        }
        int m=0;
        for(int i=0;i<n;i++){
            m=max(m,(abs(r[i]-l[i])-1)*(min(height[r[i]],height[l[i]])));
        }
        return m;
    }  
