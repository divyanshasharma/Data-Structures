//https://unacademy.com/class/faang-interview-problems-part-2/U64O705W
// here we are calculating the contribution of the element in all the 

O(n2)
int sum=0;
fo(i,0,n-1){
	fo(j,0,m-1){
		int top_left=(i+1)*(j+1);
		int bottom_right=(n-i)*(m-j);
		int sub_matrices=top_left*bottom_right;
		sum+=a[i][j]*(sub_matrices);//contribution of the element in all the submatrices it will be part of
	}
}
return sum;

naive-O(n^6)
fo(i,0,n-1){//i
	fo(j,0,m-1){//j
		fo(k,i+1,n-1){//submatrix range from i+1 to n in x direction
			fo(l,j+1,m-1){//submatrix range from j+1 to m-1 in y direction
				//sum from i to k && j to l=>this van be replaced by prefix sum
				fo(d,i,k){
					fo(o,j,l){
						sum+=a[d][o];
					}
				}
			}
		}
	}
}

O(n^4)

fo(i,0,n-1){//i
	fo(j,0,m-1){//j
		fo(k,i+1,n-1){//submatrix range from i+1 to n in x direction
			fo(l,j+1,m-1){//submatrix range from j+1 to m-1 in y direction
				//sum from i to k && j to l=>this van be replaced by prefix sum
				//we'll use here prefix sum
				sum+=pre[k][l]-p[k-1][l]-p[k][l-1]+p[k-1][l-1];
			}
		}
	}
}
