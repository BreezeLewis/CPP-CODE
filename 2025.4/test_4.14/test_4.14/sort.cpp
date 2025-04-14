#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

// ��ӡ���麯��
void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ������ʵ����������㷨
// ����: ð������ʾ��
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ѡ������ʾ��
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

// ��������ʾ��
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ��������ʾ��
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // ���������������
    std::random_device rd;
    std::mt19937 gen(rd());

    // ����һ������20��Ԫ�ص���������
    const int SIZE = 20;
    std::vector<int> array(SIZE);

    // ��1��100֮�����������������
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < SIZE; i++) {
        array[i] = dis(gen);
    }

    // ��ӡԭʼ����
    printArray(array, "����ǰ������:");

    // ����һ�������Ա���Բ�ͬ�������㷨
    std::vector<int> arrayCopy = array;

    // ������������㷨
    // ȡ��ע������Ҫ���Ե������㷨

    // ð������
    // bubbleSort(arrayCopy);
    // printArray(arrayCopy, "ð������������:");

    // ѡ������
    // selectionSort(arrayCopy);
    // printArray(arrayCopy, "ѡ������������:");

    // ��������
    // insertionSort(arrayCopy);
    // printArray(arrayCopy, "��������������:");

    // ��������
    // quickSort(arrayCopy, 0, arrayCopy.size() - 1);
    // printArray(arrayCopy, "��������������:");

    // ʹ��C++��׼���������������֤
    std::sort(array.begin(), array.end());
    printArray(array, "ʹ��std::sort����������:");

    return 0;
}