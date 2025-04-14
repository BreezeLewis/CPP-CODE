#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

// 打印数组函数
void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// 在这里实现你的排序算法
// 例如: 冒泡排序示例
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

// 选择排序示例
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

// 插入排序示例
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

// 快速排序示例
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
    // 设置随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());

    // 创建一个包含20个元素的乱序数组
    const int SIZE = 20;
    std::vector<int> array(SIZE);

    // 用1到100之间的随机整数填充数组
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < SIZE; i++) {
        array[i] = dis(gen);
    }

    // 打印原始数组
    printArray(array, "排序前的数组:");

    // 复制一个数组以便测试不同的排序算法
    std::vector<int> arrayCopy = array;

    // 测试你的排序算法
    // 取消注释你想要测试的排序算法

    // 冒泡排序
    // bubbleSort(arrayCopy);
    // printArray(arrayCopy, "冒泡排序后的数组:");

    // 选择排序
    // selectionSort(arrayCopy);
    // printArray(arrayCopy, "选择排序后的数组:");

    // 插入排序
    // insertionSort(arrayCopy);
    // printArray(arrayCopy, "插入排序后的数组:");

    // 快速排序
    // quickSort(arrayCopy, 0, arrayCopy.size() - 1);
    // printArray(arrayCopy, "快速排序后的数组:");

    // 使用C++标准库的排序函数进行验证
    std::sort(array.begin(), array.end());
    printArray(array, "使用std::sort排序后的数组:");

    return 0;
}