#define ll long long
vector <long long> nextLargerElement(long long arr[], int n){
    vector<ll>r(n,-1);
    stack<ll>s;
    for(ll i=n-1;i>=0;i--){
        while(!s.empty() && (s.top()<=arr[i])){
            s.pop();
        }
        if(!s.empty())r[i]=s.top();
        s.push(arr[i]);
    }
    return r;
}

