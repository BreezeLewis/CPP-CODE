#include <iostream>
#include <vector>

using namespace std;

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 打印数组函数
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // 示例输入数组
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    cout << "原始数组：" << endl;
    printArray(arr);

    // 调用冒泡排序函数
    bubbleSort(arr);

    cout << "排序后的数组：" << endl;
    printArray(arr);

    return 0;
}
