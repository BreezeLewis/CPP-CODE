//#include <iostream>
//#include "point.h"
//using namespace std;
//
//int main()
//{
//    double x, y;
//    cin >> x >> y;
//    point p1(x, y);
//    p1.print();
//    cout << point::count << endl;
//    cin >> x >> y;
//    point p2(x, y);
//    cin >> x >> y;
//    point p3(x, y);
//    if (p1.judge(p2, p3)) {
//        cout << "True" << endl;
//    }
//    else {
//        cout << "False" << endl;
//    }
//    cout << point::count << endl;
//    return 0;
//}
//#include "point.h"
//#include <iostream>
//using namespace std;
//int point::count = 0;
//void point::print()
//{//(1,1)
//	cout << "(" << this->x << "," << this->y << ")" << endl;
//}
//bool point::judge(const point& p2, const point& p3)
//{
//	double k1 = (p2.y - this->y) / (p2.x - this->x);
//	double k2 = (p3.y - this->y) / (p3.x - this->x);
//	if (k1 == k2)
//		return true;
//	return false;
//}

