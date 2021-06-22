//https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1#

public:
    //Function to return maximum path sum from any node in a tree.
    int fsum(Node* r,int &rs)
    {
        if(r==NULL)return 0;
        if (!r->left && !r->right) {
            rs=max(rs,r->data);
            return r->data;
        }
        int l=fsum(r->left,rs);
        int ri=fsum(r->right,rs);
        int y=max(max(l,ri)+r->data, r->data);
        rs=max(rs, max(y,r->data+l+ri));
        return y;
        
    }
    int findMaxSum(Node* root)
    {
        if(root==NULL)return 0;
        if (!root->left && !root->right) return root->data;
        int r=INT_MIN;
        r=max(r,fsum(root,r));
        return r;
    }
