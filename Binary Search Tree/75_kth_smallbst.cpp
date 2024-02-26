#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void solve3000(BinaryTreeNode<int> *root, int k, int &i, int &ans)
{
    
    if (root==NULL)
        return ;
    

    solve3000(root->left, k, i, ans);
    i++;
    // cout<<"bruh "<<i<<endl;
    if (k==i)
    {
        ans = root->data;
        return ;
    }
    solve3000(root->right, k, i, ans);

    return ;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    int ans =-1;
    solve3000(root, k, i, ans);
    return ans;
}