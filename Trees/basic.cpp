#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter left child of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter right child of " << data << ": " << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    cout << "Level order traversal: " << endl;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        { // purana level khatam
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        } // end of level
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;

    // creating tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order traversal
    levelOrderTraversal(root);

    cout << endl;

    cout << "Inorder traversal: " << endl;

    // inorder traversal
    inorder(root);

    cout << endl;

    cout << "Preorder traversal: " << endl;

    // preorder traversal
    preorder(root);

    cout << endl;

    cout << "Postorder traversal: " << endl;

    // postorder traversal
    postorder(root);

    return 0;
}