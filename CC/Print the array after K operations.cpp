//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381891?leftPanelTab=1
//https://www.geeksforgeeks.org/print-the-array-after-k-operations/
#include<bits/stdc++.h>
vector<int> printArrayAfterKOperations(vector<int> &a, int N, int k) {
	vector<int>b;
    int mx=*max_element(a.begin(),a.end());
    int mi=*min_element(a.begin(),a.end());
	if(k==0)return a;
    if(k%2==1){
        for(int i=0;i<a.size();i++){
            b.push_back((mx-a[i]));
        }
    }
    else{
        for(int i=0;i<a.size();i++){
            b.push_back((a[i]-mi));
        }
    }
    return b;
}

