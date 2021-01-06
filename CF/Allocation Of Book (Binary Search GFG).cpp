//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
bool isValid(int max_allowed, int students, int *arr, int n){
    int s=1,c=0;
    for(int i=0;i<n;i++){
        c+=arr[i];
        if(c>max_allowed){
            c=arr[i];
            s++;
        }
    }
    if(s<=students)
    return 1;
    else
    return 0;
}
int findPages(int *arr, int n, int m) {
    int s=0,max_allowed=0;
    for(int i=0;i<n;i++){
        s=max(s,arr[i]);
        max_allowed+=arr[i];
    }
    int f=-1,e=max_allowed;
    while(s<=e){
        int mid=(s+e)/2;
        if(isValid(mid,m,arr,n)){
            // as we need to find such that
            // minimum aaye maximum no of allocated pages
            // true hai matlab we can 
            f=mid;
            e=mid-1;
        }
        else{
            // false hai atlb hme mid se bde elements lene padenge
            s=mid+1;
        }
    }
    return f;
}
