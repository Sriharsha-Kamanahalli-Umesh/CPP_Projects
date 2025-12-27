#include <iostream>

class stack
{
private:
    int *ptr{nullptr};
    int top;
    size_t m_size;
public:
    stack(size_t size) : m_size(size), ptr(new int[m_size]), top(-1) {}

    void Push(int ele);
    void Pop();
    int Top() const;
    bool IsEmpty() const;
    bool Isfull() const;

    void print();

    ~stack()
    {
        delete [] ptr;
    }
};

void stack::Push(int ele)
{
    if(Isfull())
    {
        std::cout << "stack is full" <<"\n";
        return;
    }
    top++;
    ptr[top] = ele;
}

void stack::Pop()
{
    if(IsEmpty())
    {
        std::cout <<"stack is empty" <<"\n";
        return;
    }
    
    top--;
}

int stack::Top() const
{
    if(IsEmpty())
    {
        
        std::cout << "\n" << "stack is empty" <<"\n";
        return -1;
    }

    int val = ptr[top];
    return val;
}

bool stack::IsEmpty() const
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool stack::Isfull() const
{
    if(top==m_size)
    {
        return true;
    }
    return false;
}

void stack::print()
{
    int size = top;
    while(size>=0)
    {
        std::cout << ptr[size] << " ";
        size--;
    }
}

int main()
{
    std::cout << "satck is creating:" <<"\n";

    stack st(6);
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

    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();

    std::cout << "Stack elements after pop are: ";
    st.print();
    std::cout <<"\n";

    std::cout <<"stack top element is: " << st.Top() <<"\n";

}