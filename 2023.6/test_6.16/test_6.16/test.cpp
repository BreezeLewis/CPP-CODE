#include <iostream>
using namespace std;
class Plant {
protected:
    string name;

public:
    /* 此处已省略给name赋值的构造函数 */
    Plant(string name = "")
    {
        this->name = name;
    }
    virtual Plant* clone() const {
        cout << "Plant " << name << " has been cloned." << endl;
        return new Plant(*this);
    }
};

class Tree : public Plant {
public:
    Tree(string name = "")
        :Plant(name)
    {

    }
    /* 此处已省略构造函数 */
    virtual Tree* clone() const {
        cout << "Tree " << name << " has been cloned." << endl;
        return new Tree(*this);
    }
};
int main()
{
    Plant* ptrP = new Plant("Skyflower");
    Tree* ptrT = dynamic_cast<Tree*>(ptrP->clone());
    if (ptrT) auto ptr = ptrT->clone();
	return 0;
}