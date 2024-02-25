#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL; 
            this->right = NULL; 
        }
};

// bfs
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    // for separator
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp==NULL)
        {
            // to look good
            cout<<endl;
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {

            cout<<temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root)
{
    Node* temp = root;

    while (temp->left!=NULL)
        temp = temp->left;
    
    return temp;
}

Node* deletefromBST(Node* root, int d)
{
    if (root==NULL)
        return root;
    
    if (root->data == d)
    {
        // 0 child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child - left
        if (root->left != NULL and root->left==NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 1 child - right
        if (root->left == NULL and root->left!=NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL and root->right !=NULL)
        {
            // here we have two options, either the max from the left subtree or the min from the right subtree
            int mini = minVal(root->right)->data;
            root->data = mini;
            // now to yeet the node whos data we used
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > d)
    {
        deletefromBST(root->left, d);
        return root;
    }
    else
    {
        deletefromBST(root->right, d);
        return root;
    }
}

Node* insertBST(Node* &root, int d)
{
    if (root==NULL)
    {
        root = new Node(d);
        return root;
    }
    
    if (d > root->data)
        root->right = insertBST(root->right, d);
    else if (d < root->data)
        root->left = insertBST(root->left, d);
    
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data!=-1)
    {
        insertBST(root, data);
        cin>>data;
    }
}
int main()
{
    Node* root = NULL;

    cout<<"enter val"<<endl;
    takeInput(root);

    cout<<"level order trav is "<<endl;
    levelOrderTraversal(root);

    return 0;
}