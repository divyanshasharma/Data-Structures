//https://leetcode.com/problems/find-duplicate-subtrees/submissions/
    vector<TreeNode*>an;
    vector<string>ans;
    unordered_map<string,int>mp;
    string fun(TreeNode* r){
        if(!r)return "$";
        string s="";
        s=to_string(r->val)+" "+fun(r->left)+" "+fun(r->right);
        mp[s]++;
        if(mp[s]==2){
            ans.push_back(s);
            an.push_back(r);
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        fun(root);
        return an;
    }
