#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<typename Key, typename Comparable>
class BinarySearchTree {
private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const Comparable& e, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr) :element(e), left(lt), right(rt)
        {}
    };
    BinaryNode* root;
public:

    BinarySearchTree() :root(nullptr)
    {}
    //copy constructor
    BinaryNode* Copy(BinaryNode* root)
    {
        if (root == nullptr)
            return nullptr;
        else
            return new BinaryNode(root->element, root->left, root->right);
    }
    BinarySearchTree(const BinarySearchTree& rhs)
    {
        root = Copy(rhs.root);
    }

    //destructor
    void Clean(BinaryNode*& root)
    {
        if (root == nullptr)
            return;
        Clean(root->left);
        Clean(root->right);
        delete root;
        root = nullptr;
    }
    ~BinarySearchTree()
    {
        Clean(root);
    }

    //return true if empty, return false otherwise

    bool IsEmpty()const
    {
        return Size() == 0;
    }

    //return the number of elements
    size_t size(BinaryNode* root)const
    {
        if (root == nullptr)
            return 0;
        return size(root->left) + size(root->right) + 1;
    }
    size_t Size()const
    {
        return size(root);
    }

    //Precondition: Key���ͺ�Comparable���Ϳ��ԱȽϴ�С

   //�����ҷ�������ʹ�� k < d��k>d�ıȽ����㣬����k��������Key, d��������Comparable

   //return true if there is an element with key k and return it with e. 

   //return false otherwise.
    bool search(const Key& k, Comparable& e, BinaryNode* root)const
    {
        if (root == nullptr)
            return false;
        else if (k < root->element)
            return search(k, e, root->left);
        else if (k > root->element)
            return search(k, e, root->right);
        else
        {
            e = root->element;
            return true;
        }
    }
    bool Search(const Key& k, Comparable& e) const
    {
        return search(k, e, root);
    }

    //overloaded assignment or copy assignment

    BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
        if (root != rhs.root)
        {
            Clean(root);
            root = Copy(rhs.root);
        }
        return *this;
    }

    //Precondition: Comparable���͵�Ԫ��֮����ԱȽϴ�С

    //�����뷽������ʹ�� d1 < d2��d1>d2�ıȽ����㣬����d1��d2����������Comparable

   //insert element x 
    void insert(const Comparable& x, BinaryNode*& root)
    {
        if (root == nullptr)
            root = new BinaryNode(x);
        else if (x < root->element)
            insert(x, root->left);
        else if (x > root->element)
            insert(x, root->right);
    }
    void Insert(const Comparable& x)
    {
        insert(x, root);
    }

    //Precondition: Comparable���͵�Ԫ��֮����ԱȽϴ�С

   //��ɾ����������ʹ�� d1 < d2��d1>d2�ıȽ����㣬����d1��d2����������Comparable

   //erase element x
    void erase(const Comparable& x, BinaryNode*& root)
    {
        if (root == nullptr)
            return;
        else if (x < root->element)
            erase(x, root->left);
        else if (x > root->element)
            erase(x, root->right);
        else
        {
            BinaryNode* del = root;
            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            else
            {
                BinaryNode* minRight = root->right;
                while (minRight->left)
                    minRight = minRight->left;

                std::swap(root->element, minRight->element);
                erase(x, root->right);
            }  
            delete del;
        }
    }
    void Erase(const Comparable& x)
    {
        erase(x, root);
    }

    // apply visit to every element
    void inorder(void (*visit)(Comparable& x), BinaryNode* root)
    {
        if (root)
        {
            inorder(visit, root->left);
            visit(root->element);
            inorder(visit, root->right);
        }
    }
    void Inorder(void (*visit)(Comparable& x))
    {
        inorder(visit, root);
    }

};

struct Phone
{
    string name;
    int number;

    Phone(const string& n = "", int tel = 0) :name(n), number(tel)
    {}
};

bool operator<(const string& name, const Phone& phone)
{
    return name < phone.name;
}
bool operator>(const string& name, const Phone& phone)
{
    return name > phone.name;
}
bool operator<(const Phone& p1, const Phone& p2)
{
    return p1.name < p2.name;
}
bool operator>(const Phone& p1, const Phone& p2)
{
    return p1.name > p2.name;
}

void printPhone(Phone& x)
{
    cout << "����:" << x.name << "�绰:" << x.number << endl;
}

void test1();

int main()
{
    //BinarySearchTree<string, Phone> phonebook;

    //Phone p1("����", 123);
    //phonebook.Insert(p1);

    //Phone p2("����", 1234);
    //phonebook.Insert(p2);

    //Phone p3("����", 12345);
    //phonebook.Insert(p3);

    //cout << "����" << endl;
    //phonebook.Inorder(printPhone);
    //cout << "Size:" << phonebook.Size() << endl;


    //auto phonebook2 = phonebook;
    //phonebook2.Erase(p1);
    //phonebook2.Inorder(printPhone);

    //cout << &phonebook << endl;
    //cout << &phonebook2 << endl;
    ///*Phone q;
    //if (phonebook.Search("����", q))
    //{
    //    cout << "Found:";
    //    printPhone(q);
    //}
    //else
    //{
    //    cout << "Not found" << endl;
    //}*/


    test1();

    

    return 0;
}

void printPair(pair<int, int>& x)
{
    cout << x.first << " " << x.second << endl;
}

void test1()
{
    BinarySearchTree<int, pair<int, int>> bt;
    bt.Insert(make_pair(6, 13));
    bt.Insert(make_pair(34, 31));
    bt.Insert(make_pair(26, 31));
    bt.Insert(make_pair(12, 25));
    bt.Insert(make_pair(18, 3));

    bt.Inorder(printPair);

    cout << bt.Size() << endl;
}


/*
#include "AVLNode.h"

void insert( const Comparable & x, AvlNode * & t )
{
    if (t == nullptr)
        t = new BinaryNode(x);
    else if (x < t->element)
        insert(x, t->left);
    else if (x > t->element)
        insert(x, t->right);
}
*/