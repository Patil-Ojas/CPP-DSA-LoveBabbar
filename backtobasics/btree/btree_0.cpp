#include <iostream>
#include <queue>
using namespace std;

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

node* buildtree(node* root)
{
    int d;
    // cout<<"enter data";
    cin>>d;

    if (d==-1)
        return NULL;
    
    root = new node(d);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp==NULL)
        {
            cout<<endl;

            if (!q.empty())
            {
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
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    root = buildtree(root);

    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<"\n";

    return 0;
}