////#include <iostream>
////#include <vector>
////#include <stdexcept>
////using namespace std;
////
////int main() {
////	int n = 5;
////	int m = 3;
////	vector<int> a;
////	for (int i = 0; i < n; i++) {
////		a.push_back(i);
////	}
////	for (int i = 0; i < m; i++) {
////		a.erase(a.begin() + i);
////	}
////	try {
////		for (int j = 0; j < n - m + 1; j++) 
////		{
////			cout << a.at(j) << " ";
////		}
////	}
////	catch (out_of_range& exc) {
////		cout << exc.what();
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//using namespace std;
//
//int main() {
//	int n = 5;
//	int m = 4;
//	vector<int> a;
//	for (int i = 0; i < n; i++) {
//		a.push_back(i);
//	}
//	for (int i = 0; i < m; i++) {
//		a.erase(a.begin() + i);
//	}
//	try {
//		for (int j = 0; j < n - m + 1; j++) {
//			cout << a[j] << endl;
//		}
//	}
//	catch (out_of_range& exc) {
//		cout << exc.what();
//	}
//	return 0;
//}