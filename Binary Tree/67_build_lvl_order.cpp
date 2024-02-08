#include <iostream>
#include <queue>
using namespace std;

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

class node
{
    public:
        int data;
        node* left;
        node* right;
    
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }    
};

// bfs
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    // for separator
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
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

node* buildtree(node* root)
{
    cout<<"enter data: ";
    int data;
    cin>>data;

    root = new node(data);

    if (data==-1)
    {
        return NULL;
    }

    cout<<"enter data for left of "<<data<<": ";
    root->left = buildtree(root->left);
    cout<<"enter data for right of "<<data<<": ";
    root->right = buildtree(root->right);
    
    return root;
}

void build_lvlorder(node* &root)
{
    queue<node*> q;

    cout<<"enter data for root: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for: "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;

        if (leftdata != -1)        
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;

        if (rightdata != -1)        
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}


void inorder(node* root)
{
    // base case
    if (root==NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);   
}

void preorder(node* root)
{
    // base case
    if (root==NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);   
}

void Postorder(node* root)
{
    // base case
    if (root==NULL)
    {
        return ;
    }

    Postorder(root->left);
    Postorder(root->right);   
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;

/*
    root = buildtree(root);
    cout<<"\n\n";

    cout<<"Level Order Traversal: ";
    levelOrderTraversal(root);
    cout<<"\n";

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<"\n";

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<"\n";
    
    cout<<"Postorder Traversal: ";
    Postorder(root);
    cout<<"\n";
*/

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    
    build_lvlorder(root);
    cout<<"\n";
    levelOrderTraversal(root);

    return 0;
}