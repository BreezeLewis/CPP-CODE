//#include <iostream>
//using namespace std;
//class Integer
//{
//    int i;
//public:
//    Integer(int ii) : i(ii) {}
//    const Integer operator+(const Integer& rv) const
//    {
//        cout << "operator+" << endl;
//        return Integer(i + rv.i);
//    }
//    Integer& operator+=(const Integer& rv)
//    {
//        cout << "operator+=" << endl;
//        i += rv.i;
//        return *this;
//    }
//};
//int main()
//{
//    int i = 1, j = 2, k = 3;
//    k += i + j;
//    Integer ii(1), jj(2), kk(3);
//    kk += ii + jj;
//}

//#include <windows.h>
//void open_web(const char* website)
//{
//	ShellExecuteA(0, "open", website, 0, 0, 1);
//}
//int main()
//{
//	ShellExecuteA(0, "open", "https://www.2345.com/?kcys123", 0, 0, 1);
//	return 0;
//}

#include <windows.h>
int main()
{
	ShellExecuteA(0, "open", "https://www.bilibili.com/", 0, 0, 1);
	
	return 0;
}