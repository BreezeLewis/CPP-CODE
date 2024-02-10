#include <iostream>
#include <vector>

using namespace std;

// ð��������
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // ����ð��������
    bubbleSort(arr);

    cout << "���������飺" << endl;
    printArray(arr);

    return 0;
}
