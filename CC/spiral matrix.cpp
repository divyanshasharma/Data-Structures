//https://www.interviewbit.com/problems/spiral-order-matrix-ii/
vector<vector<int> > Solution::generateMatrix(int n) {
 vector<vector<int> >a;
    for(int i=0;i<n;i++)
    {
    vector<int>v1;
        for(int j=0;j<n;j++)
        {
            v1.push_back(0);
           }
           a.push_back(v1);
    }
    int i=0,j=0,l=1,m=n;
    while(i<m&&j<n){
    for(int k=j;k<n;k++)
    {
        a[i][k]=l++;
    }
        for(int k=i+1;k<m;k++)
        {
            a[k][n-1]=l++;
        }
        if((n-1)>j)
        for(int k=n-2;k>=j;k--)
        {
            a[m-1][k]=l++;
        }
        if((m-1)>i)
        for(int k=m-2;k>i;k--)
        {
            a[k][j]=l++;
        }
        i++;j++;m--;n--;
    }
    return a;}

