//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381875?leftPanelTab=1
//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
//Dutch National Flag
void sort012(int *a, int n)
{

   int lo = 0;
    int hi = n - 1;
    int mid = 0;
 	while(mid<=hi){
    	if(a[mid]==0){
            swap(a[lo],a[mid]);
            lo++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[hi],a[mid]);
            hi--;
        }
    }    
}
