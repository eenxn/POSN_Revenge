#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:

    struct Node
    {
        T a;
        Node *next;
        Node(T a)
        {
            this->a = a;
            this->next = nullptr;
        }
    };
    Node *top;

public:

    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        cout << "clear stack";
        while(top != nullptr)
        {
            Node *cur = top;
            top = top->next;
            delete cur;

        }
    }

    void push(T data)
    {
        Node *b = new Node(data);
        b->next = top;
        top = b;
    }

    void pop()
    {
        if(top == nullptr)
        {
            cout<< "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp; 
    }

    T peek()
    {
        if(top == nullptr)
        {
            cout << "nullptr" << endl;
            return T();
        }
        else 
        {
            return top->a;
        }
    }

    bool isEmpty()
    {
        if(top == nullptr) return true;
        return false;
    }

    void toString()
    {
        Node *cur = top;
        while(cur != nullptr)
        {
            cout << cur->a << endl;
            cur = cur->next;
            
        }
    }
};


int main()
{
    Stack<int> ee007;
    ee007.isEmpty();
    ee007.push(100);
    ee007.push(65);
    ee007.peek();
    ee007.toString();
    ee007.pop();

    return 0;
}