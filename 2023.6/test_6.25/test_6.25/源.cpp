#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

template <typename ElementType>
class Stack {
public:
    Stack();
    ~Stack();
    void push(ElementType obj)      throw(std::bad_alloc);
    void pop()                      throw(std::logic_error);
    ElementType getTop() const      throw(std::logic_error);
    bool isEmpty() const;

private:
    struct Node
    {
        ElementType element;
        Node* next;
    };
    Node* top;
};

template <typename ElementType>
Stack<ElementType>::Stack()
{
    top = NULL;
}

template <typename ElementType>
Stack<ElementType>::~Stack()
{

}

template <typename ElementType>
void Stack<ElementType>::push(ElementType obj) throw(std::bad_alloc)
{
    Node* temp;
    try {
        temp = new Node;
        temp->element = obj;
        temp->next = top;
        top = temp;
    }
    catch (std::bad_alloc e) {
        throw;
    }
}

template <typename ElementType>
void Stack<ElementType>::pop() throw(std::logic_error)
{
    Node* temp;
    if (top != NULL) {
        temp = top;
        top = top->next;
        delete temp;
    }
    else {
        throw std::logic_error("pop from empty Stack");
    }
}

template <typename ElementType>
ElementType Stack<ElementType>::getTop() const throw(std::logic_error)
{
    if (top != NULL) {
        return top->element;
    }
    else {
        throw std::logic_error("getTop from empty Stack");
    }
}

template <typename ElementType>
bool Stack<ElementType>::isEmpty() const
{
    return top == NULL;
}

int main()
{
    Stack<int> stack;

    for (int i = 1; i <= 9; i++)
        stack.push(i);

    while (!stack.isEmpty()) {
        cout << stack.getTop() << " ";
        stack.pop();
    }
}