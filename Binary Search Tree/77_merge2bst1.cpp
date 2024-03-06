/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void getInorder(TreeNode *root, vector<int> &arr)
{
    if (root==NULL)
        return ;

    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);

    return ;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // get inorder of both trees
    vector<int> arr;
    getInorder(root1, arr);
    getInorder(root2, arr);

    // sort it
    sort(arr.begin(), arr.end());

    // make tree from inorder
    return arr;

}