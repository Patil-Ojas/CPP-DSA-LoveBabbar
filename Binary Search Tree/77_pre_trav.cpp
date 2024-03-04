#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>* solve3000(vector<int> &pre, int &mini, int &maxi, 
int &i)
{
    if (i>=pre.size())
        return NULL;
    
    if (pre[i]<mini || pre[i]>maxi)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[i++]);
    root->left = solve3000(pre, mini, root->data, i);
    root->right = solve3000(pre, root->data, maxi, i);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    
    // approach1 ->using preorder only -> O(N^2)
    // approach2 -> using inorder and inorder -> O(nlogn)
    // approach3 -> preorder is NLR -> O(N)

    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;

    return solve3000(preorder, mini, maxi, index);
}

