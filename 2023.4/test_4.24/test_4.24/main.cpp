<<<<<<< HEAD
#include <iostream>
#include <Rectangle.hpp>
using namespace std;

int main()
{
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    Rectangle rect1(w1, h1);
    Rectangle rect2(w2, h2);

    if (isSquare(rect1))
        std::cout << "rect1 is a square" << std::endl;
    else
        std::cout << "rect1 is not a square" << std::endl;
    if (isSquare(rect2))
        std::cout << "rect2 is a square" << std::endl;
    else
        std::cout << "rect2 is not a square" << std::endl;

    if (rect1 < rect2)
        cout << "rect2's area bigger than rect1" << endl;
    else
        cout << "rect1's area bigger than rect2" << endl;

    return 0;
=======
#include <iostream>
#include <Rectangle.hpp>
using namespace std;

int main()
{
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    Rectangle rect1(w1, h1);
    Rectangle rect2(w2, h2);

    if (isSquare(rect1))
        std::cout << "rect1 is a square" << std::endl;
    else
        std::cout << "rect1 is not a square" << std::endl;
    if (isSquare(rect2))
        std::cout << "rect2 is a square" << std::endl;
    else
        std::cout << "rect2 is not a square" << std::endl;

    if (rect1 < rect2)
        cout << "rect2's area bigger than rect1" << endl;
    else
        cout << "rect1's area bigger than rect2" << endl;

    return 0;
>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}