/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class info
{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};


info getlargestBST(TreeNode* root, int &ans)
{
    if (root==NULL)
        return {INT_MIN, INT_MAX, true, 0};
    
    info left = getlargestBST(root->left, ans);
    info right = getlargestBST(root->right, ans);

    info curr;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    curr.size = left.size + right.size + 1;

    if (left.isBST and right.isBST and (root->data<right.mini and root->data>left.maxi))
        curr.isBST = true;
    else
        curr.isBST = false;

    if (curr.isBST)
        ans = max(curr.size, ans);

    return curr;

}

int largestBST(TreeNode * root){
    int ans = 0;
    info temp = getlargestBST(root, ans);

    return ans;
} 