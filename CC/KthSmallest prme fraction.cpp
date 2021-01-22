// https://leetcode.com/problems/k-th-smallest-prime-fraction/submissions/
//https://unacademy.com/class/faang-interview-problems-part-2/7RRPTIIT
class Solution {
public:
    
    struct fraction{
        double val, num,den;
    };
    class cmp{
        public:
        bool operator()(const fraction &a, const fraction &b){
            return a.val>b.val;
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
    // we need to store fraction so what we can do we can store the value of the numerator, denominator & the         //value in a structure let say fraction
    // our answer will be min heap because Kth smallest return krna hai
        priority_queue<fraction, vector<fraction>, cmp>pq;
        // as sorted hain already so 
        // by concept of k sorted merge
        // first of all store the fraction with num as i & den as last element
        // because ye hi hmare us particular i wale array ke smallest fraction honge
        for(int i=0;i<a.size();i++){
            fraction f;
            f.val=double(a[i]/(double)(a.back()));
            f.num=i;
            f.den=a.size()-1;
            pq.push(f);
        }
        while(k>1)//as k se chote wale saao ko pop krr denge jisse top prr hme required answer mil jaaye
        {
            k--;
            auto t= pq.top();
            pq.pop();
            fraction f;
            f.num=t.num;
            f.den=t.den-1;
            f.val=(double)(a[f.num]/(double)a[f.den]);
            pq.push(f);
        }
        // top wale num & denominator hi hmare answers hain so return them
        return {a[pq.top().num],a[pq.top().den]};
    }
};
