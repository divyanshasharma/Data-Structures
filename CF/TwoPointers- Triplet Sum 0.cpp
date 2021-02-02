//https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
bool twoNosWithsum(int x,int i,int j,int arr[]){
    while(i<j){
        if((arr[i]+arr[j])<x)i++;
        else if((arr[i]+arr[j])>x)j--;
        else return true;
    }
     return false;
}
bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        if(twoNosWithsum(-arr[i],i+1,n-1,arr)){
            return true;
        }
    }
    return false;
}
