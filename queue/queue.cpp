#include <iostream>


class Queue
{
private:
    size_t size;
    int rear;
    int front;
    int *q;
public:
    Queue(int qsize);
    void enqueue(int value);
    int dequeue();
    bool IsEmpty();
    bool IsFull();
    ~Queue();

};

Queue::Queue(int qsize) : size(qsize), front(-1), rear(-1), q(new int[size]) {}

Queue::~Queue()
{
    delete [] q;
}

void Queue::enqueue(int value)
{
    if(IsFull())
    {
        std::cout <<"queue is overflowed:" <<"\n";
        return;
    }

    rear++;
    q[rear] = value;
}

int Queue::dequeue()
{
    int x=-1;
    if(IsEmpty())
    {
        std::cout <<"queue is Underlowed:" <<"\n";
        return -1;
    }

    front++;

    x = q[front];

    return x;

}

bool Queue::IsEmpty()
{
    if(front==rear)
    {
        return true;
    }

    return false;
}

bool Queue::IsFull()
{
    if(rear==size-1)
    {
        return true;
    }
    return false;
}

int main() {
 
    // int A[] = {1, 3, 5, 7, 9};
 
    Queue q(6);
 
    // Enqueue
    // for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.enqueue(60);
    // }
 
    // Overflow
    q.enqueue(70);
 
    // Dequeue
    for (int i=0; i<6; i++){
        std::cout << q.dequeue() << " ";
    }
    std::cout<<"\n";
    // Underflow
    std::cout << q.dequeue() << "\n";

}