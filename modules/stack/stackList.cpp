#include <iostream>

struct StackList
{
    StackList *next{nullptr};
    int data;
};

class SatckWithList
{
private:
    StackList *list{nullptr};
public:
    SatckWithList() = default;

    void Push(int ele);
    void Pop();
    int Top() const;
    bool IsEmpty() const;
    bool Isfull() const;
    void print() const;
};

void SatckWithList::Push(int ele)
{
    if(IsEmpty())
    {
        StackList *node = new StackList;
        node->data = ele;
        node->next = nullptr;
        list = node;
    }
    else
    {
        StackList *node = new StackList;
        node->data = ele;
        node->next = list;
        list = node;
    }
}

void SatckWithList::Pop()
{
    if(IsEmpty())
    {
        std::cout <<"stack is empty" <<"\n";
        return;
    }
    else
    {
        StackList *node = list;
        list = list->next;
        delete node;
    }

}

int SatckWithList::Top() const
{
    if(IsEmpty())
    {
        
        std::cout << "\n" << "stack is empty" <<"\n";
        return -1;
    }

    int val = list->data;
    return val;
}

bool SatckWithList::IsEmpty() const
{
    if(list==nullptr)
    {
        return true;
    }
    return false;
}

void SatckWithList::print() const
{
    StackList *temp = list;
    while(temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}


int main()
{
    std::cout << "satck is creating:" <<"\n";

    SatckWithList st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    st.Push(60);
    st.Push(70);
    st.Push(80);

    std::cout << "Stack elemts are: ";

    st.print();
    std::cout <<"\n";

    std::cout <<"stack top element is: " << st.Top() <<"\n";

    st.Pop();
    st.Pop();
    std::cout << "Stack elements after pop are: ";
    st.print();
    std::cout <<"\n";

    std::cout <<"stack top element is: " << st.Top() <<"\n";

}