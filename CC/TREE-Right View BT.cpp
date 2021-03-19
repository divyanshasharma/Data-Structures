// https://www.interviewbit.com/problems/right-view-of-binary-tree/
vector<int> Solution::solve(TreeNode* A) {
    if(!A) return vector<int>();
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(t){
            if(!q.front()){
                ans.push_back(t->val);
            }
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return ans;
}

