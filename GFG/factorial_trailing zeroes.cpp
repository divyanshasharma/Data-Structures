//https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1
class Solution
{
public:
    int trailingZeroes(int N)
    {
        int c=0;
        for(int i=5;N/i>=1;i*=5){
            c+=N/i;
        }
        return c;
    }
};


