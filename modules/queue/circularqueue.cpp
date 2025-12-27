#include <iostream>


class CircularQueue
{
private:
    size_t size;
    int rear;
    int front;
    int *q;
public:
    CircularQueue(int qsize);
    void enqueue(int value);
    int dequeue();
    bool IsEmpty();
    bool IsFull();
    ~CircularQueue();

};

CircularQueue::CircularQueue(int qsize) : size(qsize), front(0), rear(0), q(new int[size]) {}

CircularQueue::~CircularQueue()
{
    delete [] q;
}

void CircularQueue::enqueue(int value)
{
    if(IsFull())
    {
        std::cout <<"queue is overflowed:" <<"\n";
        return;
    }

    rear = (rear+1) % size;
    q[rear] = value;
}

int CircularQueue::dequeue()
{
    int x=-1;
    if(IsEmpty())
    {
        std::cout <<"queue is Underlowed:" <<"\n";
        return -1;
    }

    front = (front+1) % size;
    x = q[front];

    return x;

}

bool CircularQueue::IsEmpty()
{
    if(front==rear)
    {
        return true;
    }

    return false;
}

bool CircularQueue::IsFull()
{
    if((rear+1) % size == front)
    {
        return true;
    }
    return false;
}

int main() {
 
    // int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue q(6);
 
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