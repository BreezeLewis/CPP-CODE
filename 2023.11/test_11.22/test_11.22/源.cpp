#include <iostream>
using namespace std;

int BinarySearch(int A[], int x, int bot, int top)
{
    int left = bot, right = top;
    while (left <= right)
    {
        //int mid = (left + right) >> 1;
        int mid = left + ((right - left) >> 1);//·ÀÖ¹Òç³ö
        if (A[mid] > x)
            right = mid - 1;
        else if (A[mid] < x)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int A[] = { 1,3,4,5,6,7,8,10,12,15,16,20,55 };

    int n = 21310386 % 2 + 8;

    cout << BinarySearch(A, 10, 1, n);

	return 0;
}