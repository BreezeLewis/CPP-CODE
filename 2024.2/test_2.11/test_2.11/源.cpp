#include <iostream>
#include <vector>

using namespace std;

// ����������
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // ���������������ȡ������
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

        // �ݹ�ضԷ����������������
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// ��ӡ���麯��
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // ʾ����������
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    cout << "ԭʼ���飺" << endl;
    printArray(arr);

    // ���ÿ���������
    quickSort(arr, 0, arr.size() - 1);

    cout << "���������飺" << endl;
    printArray(arr);

    return 0;
}
