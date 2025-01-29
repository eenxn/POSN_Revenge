#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
    //tree structure
    struct TreeNode
    {
        int key;
        TreeNode *left;
        TreeNode *right;

        //Initializer List
        TreeNode(int value): key(value), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;

    //insert method
    TreeNode *insertNode(TreeNode *node, int key)
    {
        if(!node)
        {
            return (new TreeNode(key));
        }
        if(key < node->key)
        {
            node->left = insertNode(node->left, key);
        }
        else if(key > node->key)
        {
            node->right = insertNode(node->right, key);
        }
        return (node);
    }

    //search method
    bool searchNode(TreeNode *node, int key)
    {
        if(!node)
        {
            return false;
        }
        if(node->key == key)
        {
            return true;
        }

        if(key < node->key)
        {
            return searchNode(node->left, key);
        }
        return searchNode(node->right, key);
    }

    //remove method
    TreeNode *removeNode(TreeNode *node, int key)
    {
        if(!node)
        {
            return (node);
        }
        
        //Search
        if (key < node->key)
        {
            node->left = removeNode(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = removeNode(node->right, key);
        }
        //Node found
        else
        {
            //case 1: no children
            if (!(node->left) && !(node->right))
            {
                delete node;
                return nullptr;
            }
        
            //case 2: one child
            if (!(node->left))
            {
                TreeNode *temp;
                temp = node->right;
                delete node;
                return temp;
            }
            else if (!(node->right))
            {
                TreeNode *temp;
                temp = node->left;
                delete node;
                return temp;
            }

            //case 3: two children
            TreeNode *min;
            min = findMin(node->right);
            node->key = min->key;
            node->right = removeNode(node->right, min->key);
        }
        return (node);
    }

    //findMin() method
    TreeNode *findMin(TreeNode *node)
    {
        TreeNode *cur = node;
        while (!cur)
        {
            cur = cur->left;
        }

        return cur;
    }

    //inorder Traversal
    void inorderTraversal(TreeNode *node)
    {
        //your code na kub
            if(node == nullptr)
            {
                return;
            }
            inorderTraversal(node->left);
            cout << node-> key << " ";
            inorderTraversal(node->right);
    }

public:

    //constructor method
    BinarySearchTree(): root(nullptr) {}

    //insert method
    void insert(int key)
    {
        root = insertNode(root, key);
    }

    //search method
    bool search(int key)
    {
        return searchNode(root, key);
    }

    //remove method
    void remove(int key)
    {
        root = removeNode(root, key);
    }

    //inorder traversal
    void display()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }

};

int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);


    cout << "Inorder traversal: ";
    bst.display();

    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    bst.remove(40);
    cout << "Inorder traversal after removing 40: ";
    bst.display();
    return (0);
}