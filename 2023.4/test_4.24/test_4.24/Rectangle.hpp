class Rectangle
{
    int width;
    int height;
public:
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    int getArea()
    {
        return width * height;
    }
    friend int isSquare(Rectangle rect);

    int operator< (Rectangle rect)
    {
        int a = this->getArea();
        int b = rect.getArea();
        if (a < b)
            return 1;
        return 0;
    }
};

int isSquare(Rectangle rect)
{
    if (rect.width == rect.height)
        return 1;
    return 0;
}