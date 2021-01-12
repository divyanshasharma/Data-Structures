#defne mid(a,b) a+(b-a)/2
//https://www.interviewbit.com/problems/rotated-sorted-array-search/
int Solution::search(const vector<int> &a, int t) {

    int s=0,n=a.size()-1;
    while(s<=e){
        int m=mid(s,e);
        if(a[m]==t)return m;
        else if(a[m]>=a[s]){
            if(a[m]>=t  &&  t>=a[s]){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        else if(a[m]<=a[e]){
            if(a[m]<=t  &&  t<=a[e]){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        else return -1;
    }
    return -1;
}


