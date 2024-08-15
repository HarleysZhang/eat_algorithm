#include <iostream>
#include <vector>

// 交换两个元素的工具函数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 分区函数，将数组分为两部分
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]); // 将基准元素放到正确的位置
    return i; // 返回基准元素的索引
}

// 快速排序函数
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1); // 递归排序基准左侧的子数组
        quicksort(arr, pivotIndex + 1, high); // 递归排序基准右侧的子数组
    }
}

int main() {
    std::vector<int> arr = {10, 5, 6, 1, 2, 9, 89, 100};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
