#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *head;
    Node *tail;

public:

    Queue()
    {
        head = tail = nullptr;
    }

    ~Queue()
    {
        while (!(isEmpty()))
        {
            Node *temp = head;
            head = head -> next;
            delete temp;
        }
        
        tail = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void enqueue(T data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;

            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }

    T dequeue()
    {
        Node *temp = head;
        head = head->next;
        T n = temp->data;
        delete temp;
        return n;
    }

    T front()
    {
        return head->data;
    }

    T back()
    {
        return tail->data;
    }

    void toString()
    {
        Node *cur = head;
        cout << "head -> ";
        while (cur != nullptr)
        {
            cout << cur->data << " -> ";
            cur = cur -> next;
        }
        cout << "tail" << endl;
    }

};

int main()
{
    Queue<int> q;
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.toString();
    cout << "front: " <<q.front() << endl;

    q.dequeue();
    q.dequeue();
    q.enqueue(9);
    q.toString();
    cout << "back: " << q.back() << endl;

    return (0);
}