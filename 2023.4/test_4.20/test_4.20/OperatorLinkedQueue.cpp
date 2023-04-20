#include "OperatorLinkedQueue.h"

OperatorLinkedQueue::OperatorLinkedQueue()
{
    arr = new int[100];
    front = 0;
    back = -1;
    size = 0;
}
OperatorLinkedQueue::OperatorLinkedQueue(const OperatorLinkedQueue& other)
{
    arr = new int[100];
    front = other.front;
    back = other.back;
    size = other.size;
    for (int i = front; i <= back; i++)
        arr[i] = other.arr[i];
}
OperatorLinkedQueue::~OperatorLinkedQueue()
{
    delete[] arr;
    arr = nullptr;
}

int OperatorLinkedQueue::GetSize() const
{
    return size;
}

int& OperatorLinkedQueue::operator[] (const int& index)
{
    return arr[front + index];
}
int OperatorLinkedQueue::operator[] (const int& index) const
{
    return arr[front + index];
}
OperatorLinkedQueue OperatorLinkedQueue::operator= (const OperatorLinkedQueue& right)
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
    arr = new int[100];
    front = right.front;
    back = right.back;
    size = right.size;
    for (int i = 0; i < size; i++)
        arr[i] = right.arr[i];
    return *this;
}
OperatorLinkedQueue OperatorLinkedQueue::operator+= (const int& ele)
{
    if (size == 100)
        return *this;
    arr[size++] = ele;
    back++;
    if (back > 99)
        back = 0;
    return *this;
}
OperatorLinkedQueue OperatorLinkedQueue::operator-- ()
{
    if (size == 0)
        return *this;
    front++;
    size--;
    if (front > 99)
        front = 0;
    return *this;
}
OperatorLinkedQueue OperatorLinkedQueue::operator-- (int)
{
    if (size == 0)
        return *this;
    OperatorLinkedQueue ret(*this);
    front++;
    size--;
    if (front > 99)
        front = 0;
    return ret;
}

ostream& operator << (ostream& os, const OperatorLinkedQueue& object)
{
    int size = object.GetSize();
    if (size == 0)
    {
        return os;
    }
    for (int i = object.front; i < object.back; i++)
    {
        os << object.arr[i] << "->";
    }
    return os << object.arr[object.back];
}