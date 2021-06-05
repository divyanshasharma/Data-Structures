//https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1/?company[]=Accolite&company[]=Accolite&page=1&query=company[]Accolitepage1company[]Accolite#
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *r) 
    {
        vector<int>v;
        queue<Node*>q;
        if(r==NULL){
            v.push_back(-1);
            return v;
        }
        q.push(r);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t==NULL){
                v.push_back(-1);
            }
            else{
                v.push_back(t->data);
                q.push(t->left);
                q.push(t->right);
            }
        }
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int i=0;
       if(A[0]==-1)return NULL;
       Node *rr=(Node *)malloc(sizeof(Node));
       rr->data=A[0];
       rr->left=rr->right=NULL;
       queue<Node* >q;
       q.push(rr);
       while(!q.empty()){
           auto r=q.front();
           q.pop();
           if(A[i+1]!=-1){
               Node *t=(Node *)malloc(sizeof(Node));
               t->data=A[i+1];
               t->left=NULL;
               t->right=NULL;
               r->left=t;
               q.push(t);
            }
           else{
               r->left=NULL;
           }
           if(A[i+2]!=-1){
               Node *t=(Node *)malloc(sizeof(Node));
               t->data=A[i+2];
               t->left=NULL;
               t->right=NULL;
               r->right=t;
               q.push(t);
           }else{
               r->right=NULL;
           }
           i+=2;
       }
       return rr;
    }
};
