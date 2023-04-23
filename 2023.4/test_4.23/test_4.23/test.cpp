#include <iostream>
using namespace std;

class cmp {

public:

    bool operator() (const int& a, const int& b)

    {

        return a >= b;

    }

};

int main()

{

    cmp f;

    std::cout << f(3, 4) << std::endl;

    std::cout << f(4, 3) << std::endl;

    return 0;

}