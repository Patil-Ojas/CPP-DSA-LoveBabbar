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

int main()
{
    node* root = NULL;

    root = buildtree(root);
    cout<<"\n\n";
    levelOrderTraversal(root);

    return 0;
}