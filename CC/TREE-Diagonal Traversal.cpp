//https://www.interviewbit.com/problems/diagonal-traversal/

// Using Deque
vector<int> Solution::solve(TreeNode* A) {
	deque<TreeNode* >s;
	vector<int>v;
	s.push_front(A);
	TreeNode* root;
	while(!s.empty()){
		root=s.front();
		s.pop_front();
		v.push_back(root->val);
		if(root->left)
		s.push_back(root->left); //we have to traverse left node at end.
		if(root->right)
		s.push_front(root->right); // we have to traverse right node first.
	}
return v;
}


//       Using Queue
 vector<int> Solution::solve(TreeNode* A) {
 TreeNode *root=A;
 queue<TreeNode *> q;
 q.push(root);
 vector<int> v;
 while(q.size()!=0)
 {
     root=q.front();
     q.pop();
     while(root!=NULL)
     {
         v.push_back(root->val);
         if(root->left!=NULL)
         q.push(root->left);
         root=root->right;
     }
 }
 return v;
}
