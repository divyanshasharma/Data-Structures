https://www.spoj.com/problems/CUBEFR/
//There is a bug in SPOJ system
//If you take array size as 1000000
//Then you will get WA

//Wasted 3 hrs finding that bug


#include <iostream>
#include <stdio.h>
using namespace std;
int cubeFreeNumbers[1000100] = {0};

int main() {
	//Program to check for cube free numbers
	int cube;
	
	//Assign -1 to all the numbers which are not cube free
	for(int i=2;i<=100;i++){
		cube = i*i*i;
		if(cubeFreeNumbers[cube]!=-1){
			for(int j=cube;j<1000100;j=j+cube){
				cubeFreeNumbers[j] = -1;		
			}
		}
		
	}

	int k=1;
	for(int i=1;i<1000100;i++){
		if(cubeFreeNumbers[i]==0){
			cubeFreeNumbers[i] = k++;
		}
		
	}

	int temp;
	int count;
	cin>>count;
	for(int i=1;i<=count;i++){
		cin>>temp;
		if(cubeFreeNumbers[temp]!=-1){
			printf("Case %d: %d\n",i,cubeFreeNumbers[temp]);
		}else{
		    printf("Case %d: Not Cube Free\n",i);
		}
	}
	
	return 0;
}
