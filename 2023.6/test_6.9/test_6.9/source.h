using namespace std;
class MyDate
{
    int year;
    int month;
    int day;
};
class Person
{
public:
    string name;
    string address;
    string phoneNumber;
    string email;
    virtual string toString() const
    {
        return "Person";
    }
};

class Employee :public Person
{
public:
    string office;
    int salary;
    MyDate dateHired;
    string toString() const
    {
        return "Employee";
    }

};

class Student :public Person
{
public:
    enum class_status { frssman, sophomore, junior, senior };
    class_status status;
    string toString() const
    {
        return "Student";
    }

};

class Faculty :public Employee
{
public:
    string officeHours;
    int rank;
    string toString() const
    {
        return "Faculty";
    }
};

class Staff :public Employee
{
public:
    string title;
    string toString() const
    {
        return "Staff";
    }
};

