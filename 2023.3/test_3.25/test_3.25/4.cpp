//#include <iostream>
//using namespace std;
//class Complex
//{
//public:
//    Complex(long long real, long long image)
//    {
//        this->real = real;
//        this->image = image;
//    }
//    void add(Complex& c2)
//    {
//        cout << "Add done!" << endl;
//        this->real += c2.real;
//        this->image += c2.image;
//    }
//    void mul(Complex& c2)
//    {
//        // a+bi   *    c+di   (3+3i )  *  (2 + 2i)
//        //  ac-bd  + ad+bci      
//        cout << "Mul done!" << endl;
//        long long real = this->real * c2.real - this->image * c2.image;
//        long long image = this->real * c2.image + this->image * c2.real;
//        this->real = real;
//        this->image = image;
//    }
//    void show()
//    {
//        cout << "real part: " << this->real << endl;
//        cout << "imaginary part: " << this->image << endl;
//    }
//private:
//    long long real = 0;
//    long long image = 0;
//};
//int main() {
//    int a, b;
//    cin >> a >> b;
//
//    int c, d;
//    cin >> c >> d;
//
//    Complex c1(a, b);
//    Complex c2(c, d);
//
//    cout << "Function show:" << endl;
//    c1.show();
//    cout << "Function show:" << endl;
//    c2.show();
//
//    cout << "Function add:" << endl;
//    c1.add(c2);
//    cout << "Function show:" << endl;
//    c1.show();
//
//    cout << "Function mul:" << endl;
//    c1.mul(c2);
//    cout << "Function show:" << endl;
//    c1.show();
//
//    return 0;
//}