#https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1#
vector <int> maxOfMin(int arr[], int n)
    {vector<int>l(n+1,-1),r(n+1,n),ans(n+1,0);
    stack<int>s;
    for(int i=0;i<n;i++){
        while((!s.empty()) && (arr[i]<=arr[s.top()])){
            s.pop();
        }
        if(!s.empty()){
            l[i]=s.top();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n-1;i>=0;i--){
        while((!s.empty()) && (arr[i]<=arr[s.top()])){
            s.pop();
        }
        if(!s.empty())
            r[i]=s.top();
        s.push(i);
    }
    for(int i=0;i<n;i++){
        int len=r[i]-l[i]-1;
        ans[len]=max(ans[len],arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    vector<int>p;
    for(int i=1;i<=n;i++){
        p.push_back(ans[i]);
    }
    return p;
    }
