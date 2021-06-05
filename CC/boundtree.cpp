//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};
void printl(vector <int>&a, Node* root){
        if(root!=NULL){
            if(root->left)
            {
                a.push_back(root->data);
                printl(a,root->left);
            }
            else if(root->right){
                a.push_back(root->data);
                printl(a,root->right);
            }
        }
        return;
    }
    void printr(vector <int>&a, Node* root){
        vector<int>aa;
        if(root!=NULL){
            if(root->right)
            {

                aa.push_back(root->data);
                printr(a,root->right);

            }
            else if(root->left){

                aa.push_back(root->data);
                printr(a,root->left);
            }
        }
        for(int i=aa.size()-1;i>=0;i--){
            a.push_back(aa[i]);
        }
    }
    void printleaf(vector <int>&a, Node* root){
        if(root==NULL)return;
        if(root->left){
            printleaf(a,root->left);
        }
        if(root->left==NULL && root->right==NULL){
            a.push_back(root->data);
        }
        else if(root->right){
            printleaf(a,root->right);
        }

    }
    vector <int> printBoundary(Node *root)
    {
        vector<int>a;
        if(root==NULL)return a;
        a.push_back(root->data);
        printl(a,root->left);
        printleaf(a,root->left);
        printleaf(a,root->right);
        printr(a,root->right);
        for(int i=0;i<a.size();i++){
        	cout<<a[i]<<" ";
		}
    }
struct Node* newNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
//	struct Node* root = newNode(1);
//	root->left = newNode(2);
//	root->right = newNode(3);
//	root->right->right = newNode(12);
//	root->right->right->left = newNode(8);
//	root->right->right->left->right = newNode(19);
//	root->left->left = newNode(4);
//	root->left->right = newNode(5);
//	root->left->right->left = newNode(9);
//	root->left->right->right = newNode(7);
//	root->left->right->left->right = newNode(10);

	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->right = newNode(12);
	root->right->right->left = newNode(8);
	root->right->right->left->right = newNode(19);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(7);
	root->left->right->left->right = newNode(10);
	root->left->right->left->right->left = newNode(12);
	root->left->right->left->right->left->left = newNode(14);
	root->left->right->left->right->left->right = newNode(15);

	printBoundary(root);
	return 0;
}

