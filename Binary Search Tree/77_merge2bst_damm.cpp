// algo - convert BST to sorted DLL inplace
//      - merge sorted SLL
//      - convert sorted LL to BST

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

int countNodes(TreeNode* root)
{
    TreeNode* temp = root;
    int count = 0;

    while (temp!=NULL)
    {
        count++;
        temp = temp->right;
    }

    return count;
}

void convertToDLL(TreeNode* &root, TreeNode* &head)
{
    if (root==NULL)
        return 
    
    convertToDLL(root->right, head);
    
    root->right = head;
    if (head!=NULL)
        head->left = root;

    head = root;

    convertToDLL(root->left, head);
}

TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2)
{
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while (head1!=NULL and head2!=NULL)
    {
        if (head1->data < head2->data)
        {
            if (head==NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                // insert at end
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head==NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1!=NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2!=NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

TreeNode* sortedLLtoBST(TreeNode* &head, int count)
{
    if (count<=0 or head==NULL)
        return NULL;
    
    TreeNode* left = sortedLLtoBST(head, count/2);
    
    TreeNode* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLtoBST(head, count/2 -1);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // method 1
    // get inorder of both trees
    vector<int> arr;
    getInorder(root1, arr);
    getInorder(root2, arr);

    // sort it
    sort(arr.begin(), arr.end());

    // make tree from inorder
    return arr;
    
    // method 2
    /*
    // convert BST into DLL inplace
    TreeNode* head1 = NULL;
    convertToDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertToDLL(root2, head2);

    // merge sorted LL
    TreeNode* head = mergeLinkedList(head1, head2);

    // convert sorted LL to BST
    int count = countNodes(head);
    TreeNode* ans = sortedLLtoBST(head, count);

    vector<int> nums;
    getInorder(ans, nums);
    return nums;
    */
}