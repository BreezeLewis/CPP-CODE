#pragma once
class B
{
public:
    int a, b;
    B(int x, int y)
    {
        a = x, b = y;
    }
    void show()
    {
        printf("a=%d\nb=%d", a, b);
    }
};