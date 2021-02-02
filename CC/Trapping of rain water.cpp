//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
int trappingWater(int a[], int n){
    int w=0,j=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[j]){
            w+=a[j]-a[i];
        }
        else if(a[j]<=a[i]){
            j=i;
        }
    }
    if(j!=n-1){
        int o=n-1,t=0;
        for(int k=n-1;k>=j;k--){
            w-=(a[j]-a[k]);
            if(a[k]<=a[o]){
                t+=(a[o]-a[k]);
            }
            else o=k;
        }
        w+=t;
        
    }
    return w;
}
