#include <iostream>

struct BstInsert
{
    int data;
    BstInsert *left{nullptr};
    BstInsert *right{nullptr};
};

void insert(BstInsert **root, int val)
{
    if(*root == nullptr)
    {
        *root = new BstInsert;
        (*root)->data = val;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
    }
    else
    {
        if(val < (*root)->data)
        {
            insert(&((*root)->left), val);
        }
        else if(val > (*root)->data)
        {
            insert(&((*root)->right), val);
        }
        else
        {
            std::cout << "Value already exists in the tree." << std::endl;
        }
    }
}

void inoderTraversal(BstInsert *root)
{
    if(root == nullptr)
    {
        return;
    }
    inoderTraversal(root->left);
    std::cout << root->data << " ";
    inoderTraversal(root->right);
}

// Search element in BST
bool Search(BstInsert *root, int val)
{
    if(root == nullptr)
    {
        return false;
    }
    if(val < root->data)
    {
        return Search(root->left, val);
    }
    else if(val > root->data)
    {
        return Search(root->right, val);
    }
    else
    {
        return true;
    }
}
int main()
{
    BstInsert *root = nullptr;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 25);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 12);

    std::cout << "Inorder Traversal: ";
    inoderTraversal(root);
    std::cout << std::endl;

    int searchValue = 15;
    if(Search(root, searchValue))
    {
        std::cout << "Value " << searchValue << " found in the BST." << std::endl;
    }
    else
    {
        std::cout << "Value " << searchValue << " not found in the BST." << std::endl;
    }
    return 0;
    
}
