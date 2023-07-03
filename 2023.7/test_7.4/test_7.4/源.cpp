#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//int main()
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//		if (*itor == 300)
//			itor = array.erase(itor);
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//		cout << *itor << " ";
//
//	return 0;
//}


//int main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(100);
//	v.resize(20);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(50);
//	v.resize(5);
//	cout << v.size() << ":" << v.capacity() << endl;
//}
//
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto& e : freq) {
            
            if (e.second == 1) {
                ans = e.first;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 0,1,0,1,0,1,99 };
    Solution().singleNumber(nums);
    
    return 0;
}