#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//pre-order traversal
void preOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//in-order traversal
void inOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root-> data << " ";
    inOrder(root->right);
}

//post-order traversal
void postOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root-> data << " ";
}

int main()
{
/*Binary Tree structure:
       60
       /\
     20 70
     /\
    10 40
       /\
     30  50
*/
    TreeNode *root = new TreeNode(60);
    root->left = new TreeNode(20);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(30);
    root->left->right->right = new TreeNode(50);
    //your code :)

    /* display */
    preOrder(root);
    std::cout << std::endl;
    inOrder(root);
    std::cout << std::endl;
    postOrder(root);
}