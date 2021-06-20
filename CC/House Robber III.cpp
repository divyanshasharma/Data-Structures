//https://leetcode.com/problems/house-robber-iii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     map<TreeNode*,int> mp;
    
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int valueGrandChild=0;
        
        if(root->left){
            valueGrandChild+=rob(root->left->left)+rob(root->left->right);
        }
        
        if(root->right){
            valueGrandChild+=rob(root->right->left)+rob(root->right->right);
        }
        
        mp[root] = max(root->val+valueGrandChild,rob(root->left)+rob(root->right));
        
        return mp[root];
        
    }
};
