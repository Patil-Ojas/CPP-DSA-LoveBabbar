#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void getInorder(TreeNode<int>* root, vector<int> &inn)
{
    if (root==NULL)
        return ;
    
    getInorder(root->left, inn);
    inn.push_back(root->data);
    getInorder(root->right, inn);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inOrder;
    getInorder(root, inOrder);

    int n = inOrder.size();
    TreeNode<int>* newRoot = new TreeNode<int>(inOrder[0]);
    TreeNode<int>* curr = newRoot;

    for(int i=1; i<n; i++)
    {
        TreeNode<int>* next = new TreeNode<int>(inOrder[i]);
        curr->left = NULL;
        curr->right = next;
        curr = next;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
