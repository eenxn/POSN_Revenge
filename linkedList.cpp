#include <iostream>
using namespace std;

template<typename T>
class LinkedList
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

public:

LinkedList()
{
    head = nullptr;
}

~LinkedList()
{
    clear();
}

void push_front(T data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void push_back(T data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void toString()
{
    if (head == nullptr)
    {
        cout << "Head -> null" << endl;
        return;
    }

    Node *cur = head;
    cout << "Head -> ";
    while (cur != nullptr)
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "null" << endl;
}
};

int main()
{
    LinkedList<int> L;
    L.push_front(1);
    L.push_back(2);
    L.toString();
    return (0);
}