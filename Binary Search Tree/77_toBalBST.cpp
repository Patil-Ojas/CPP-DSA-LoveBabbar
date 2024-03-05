/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void getInorder(TreeNode<int>* root, vector<int> &inn)
{
    if (root==NULL)
        return ;
    
    getInorder(root->left, inn);
    inn.push_back(root->data);
    getInorder(root->right, inn);

    return ;
}

TreeNode<int>* makeBalBST(vector<int>& inn, int start, int end)
{
    if (start>end)
        return NULL;
    
    int mid = (start + end )/2;
    TreeNode<int>* root = new TreeNode<int>(inn[mid]);

    root->left = makeBalBST(inn, start, mid-1);
    root->right = makeBalBST(inn, mid+1, end);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inn;
    getInorder(root, inn);

    int start = 0;
    int end = inn.size()-1;
    return makeBalBST(inn, start, end);
}
