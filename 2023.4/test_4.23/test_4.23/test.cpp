<<<<<<< HEAD
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

=======
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

>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}