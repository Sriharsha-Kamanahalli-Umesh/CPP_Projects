#include <iostream>
#include <queue>

struct Node
{
    Node *LeftChild;
    int data;
    Node *RightChild;
};

class Tree
{
private:
    Node *root;
    int noOfNodes=0;
    void TPreOrder(Node *node)
    {
        if(node)
        {
            std::cout << node->data << " ";
            TPreOrder(node->LeftChild);
            TPreOrder(node->RightChild);
        }
    }

    void TInOrder(Node *node)
    {
        if(node)
        {
            TInOrder(node->LeftChild);
            std::cout << node->data << " ";
            TInOrder(node->RightChild);
        }
    }

    void TPostOrder(Node *node)
    {
        if(node)
        {
            TPostOrder(node->LeftChild);
            TPostOrder(node->RightChild);
            std::cout << node->data << " ";
        }
    }

    void ILevelOrder(Node *node)
    {
        if(!node)
        {
            return;
        }
        std::queue<Node *> q;

        q.emplace(node);

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            noOfNodes++;
            std::cout << p->data << " ";

            if(p->LeftChild!=nullptr)
            {
                q.emplace(p->LeftChild);   
            }

            if(p->RightChild!=nullptr)
            {
                q.emplace(p->RightChild);
            }
        }
    }

    int IHeightOfTree(Node *p)
    {
        int l = 0;
        int r = 0;
        if (p == nullptr){
            return 0;
        }
    
        l = IHeightOfTree(p->LeftChild);
        r = IHeightOfTree(p->RightChild);
    
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }

    }
public:
    void CreateTree(int rootValue);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    int HeightOfTree();

    int NofOfNodes()
    {
        return noOfNodes;
    }

    ~Tree() 
    {
        delete root;
    }
};

void Tree::CreateTree(int rootValue)
{
    Node *t;
    Node *p;
    int InputValue;
    // Cretae root node;
    root = new Node;
    root->LeftChild = nullptr;
    root->data = rootValue;
    root->RightChild = nullptr;

    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();

        std::cout << "enter the left child node of " << p->data << ": ";
        std::cin >> InputValue;
        if(InputValue != -1)
        {
            t = new Node();
            t->LeftChild = nullptr;
            t->data = InputValue;
            t->RightChild = nullptr;

            p->LeftChild = t;
            q.emplace(t);
        }

        std::cout << "enter the right child node of " << p->data << ": ";
        std::cin >> InputValue;
        if(InputValue != -1)
        {
            t = new Node();
            t->LeftChild = nullptr;
            t->data = InputValue;
            t->RightChild = nullptr;

            p->RightChild = t;
            q.emplace(t);
        }
    }
}

void Tree::PreOrder()
{
    TPreOrder(root);
}

void Tree::InOrder()
{
    TInOrder(root);
}

void Tree::PostOrder()
{
    TPostOrder(root);
}

void Tree::LevelOrder()
{
    ILevelOrder(root);
}

int Tree::HeightOfTree()
{
    return IHeightOfTree(root);
}

int main()
{
    std::cout << "Creating Tree:" << "\n";

    Tree t;
    t.CreateTree(10);

    t.PreOrder();
    std::cout <<"\n";
    t.InOrder();
    std::cout <<"\n";
    t.PostOrder();
    std::cout <<"\n";
    t.LevelOrder();
    std::cout<<"\n";

    std::cout <<"the no of nodes in the tree: " << t.NofOfNodes() << "\n";
    std::cout <<"the hight of the tree is: " << t.HeightOfTree() << "\n";
}