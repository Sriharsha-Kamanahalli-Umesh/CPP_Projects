#include <iostream>

struct LinkedListQueue
{
    LinkedListQueue *next;
    int data;
};


class Queue
{
private:
    LinkedListQueue *rear;
    LinkedListQueue *front;
public:
    Queue();
    void enqueue(int value);
    int dequeue();
    bool IsEmpty();
    bool IsFull();
    void display();
    ~Queue();

};

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    LinkedListQueue* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::enqueue(int value)
{
    LinkedListQueue* node = new LinkedListQueue;
    node->data = value;
    node->next = nullptr;
    if(front==nullptr)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next=node;
        rear = node;
    }
}

int Queue::dequeue()
{
    int x=-1;
    if(IsEmpty())
    {
        std::cout <<"queue is Underlowed:" <<"\n";
    }
    else
    {
        LinkedListQueue *temp = front;
        front = front->next;
        x = temp->data;
        delete temp;
    }
    return x;
}

bool Queue::IsEmpty()
{
    if(front==nullptr)
    {
        return true;
    }

    return false;
}

// bool Queue::IsFull()
// {
//     if(rear==size-1)
//     {
//         return true;
//     }
//     return false;
// }


 
void Queue::display() {
    LinkedListQueue* p = front;
    while (p){
        std::cout << p->data << " ";
        p = p->next;
        if (p != nullptr){
            std::cout << " <- " << " ";
        }
    }
    std::cout <<"\n";
}

int main() 
{
    Queue q;
 
    // Enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
 
    // Overflow
    
    q.display();
    // Dequeue
    for (int i=0; i<7; i++){
        q.dequeue();
    }
    std::cout<<"\n";
    // // Underflow
    std::cout << q.dequeue() << "\n";

}
