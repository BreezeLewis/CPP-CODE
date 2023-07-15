const int MAX_LEN = 5;
template<class T>
class Stack
{
public:
    explicit Stack()
        :stack_size(0)
    {
        //data = new T[MAX_LEN];
    }
    bool empty() const
    {
        return stack_size == 0;
    }
    int size() const
    {
        return stack_size;
    }
    T& top()
    {
        if (empty())
        {
            throw 1;
        }
        return data[stack_size];
    }
    const T& top() const
    {
        if (empty())
        {
            throw 1;
        }
        return data[stack_size];
    }
    void push(const T& x)
    {
        if (x > top())
        {
            pop();
        }
        else
        {
            return;
        }
        data[stack_size++] = x;
    }
    void pop()
    {
        stack_size--;
    }
private:
    T data[MAX_LEN];
    int stack_size;
};