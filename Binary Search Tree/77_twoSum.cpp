#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/

void getInorder(BinaryTreeNode<int>* root, vector<int> &nums)
{
    if (root==NULL)
        return;
    
    getInorder(root->left, nums);
    nums.push_back(root->data);
    getInorder(root->right, nums);

    return ;
}

bool checkTwoSum(vector<int> nums, int target)
{
    int start=0;
    int end=nums.size()-1;

    while (start < end)
    {
        if (nums[start]+nums[end] == target)
            return true;
        else if (nums[start]+nums[end] >= target)
            end--;    
        else
            start++;
    }

    return false;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) 
{
    vector<int> nums;
    
    getInorder(root, nums);
    bool ans = checkTwoSum(nums, target);
    
    return ans;
}