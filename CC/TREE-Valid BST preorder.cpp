//https://www.interviewbit.com/problems/valid-bst-from-preorder/

int Solution::solve(vector<int> &pre) {
    int root=INT_MIN;
    stack<int>s;
    for(int i=0;i<pre.size();i++){
        if(root>pre[i])return 0;
		//here we are also allowing the equality case
        while(!s.empty() && s.top()<pre[i]){
            root=s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return 1;
}
