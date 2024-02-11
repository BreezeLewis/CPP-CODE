#include <iostream>
#include <vector>

using namespace std;

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 将数组分区，并获取分区点
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        // 递归地对分区的两侧进行排序
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

    // 调用快速排序函数
    quickSort(arr, 0, arr.size() - 1);

    cout << "排序后的数组：" << endl;
    printArray(arr);

    return 0;
}
