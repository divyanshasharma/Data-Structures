/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 //https://binarysearch.com/problems/Linked-List-to-ZigZag-Tree-Path
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
Tree* solve(LLNode* head) {
    if(head==NULL)
       return NULL;
    Tree *r=(Tree*)malloc(sizeof(Tree));
    r->val=head->val;
    r->left=r->right=NULL;
    Tree *prev=r;   
    while(head!=NULL){
        //prev=r;
        int d=prev->val;
        head=head->next;
        if(head==NULL)return r;
        if(head->val<d){
            prev->left=(Tree*)malloc(sizeof(Tree));
            prev->left->val=head->val;
            prev->left->left=prev->left->right=NULL;
            prev=prev->left;
        }
        else{
            prev->right=(Tree*)malloc(sizeof(Tree));
            prev->right->val=head->val;
            prev->right->left=prev->right->right=NULL;
            prev=prev->right;
        }
    }
    return r;
}
