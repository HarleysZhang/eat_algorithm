// c++ 风格的排序函数代码实现

#include <stdio.h>
#include <iostream>
#include <vector> // Include the vector header file
#include <utility> // 包含 std::swap 的头文件

using namespace std;

// 冒泡排序函数
void bubbleSort(std::vector<int>& arr){
    int n = arr.size(); // 获取数组元素个数
    
    for(int i = 0; i< n; i++) {
        bool swapped =false;
        for(int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped) break; // 如果在一趟遍历中没有发生交换，说明数组已经有序，可以提前结束
    }

}


void InsertSort(int a[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = a[j]; // 待排序第一个元素
        int i = j - 1;  // 代表已经排过序的元素最后一个索引数
        while (i >= 0 && key < a[i])
        {
            // 从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
            // 其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key; // 找到合适的位置了，赋值,在i索引的后面设置key值。
    }
}

void SelectSort(int a[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j = i;j<n;j++){
            if (a[j] < a[minIndex]) minIndex = j;
        }
        if (minIndex != i){
            int temp = a[i]; 
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}


int main() {
    std::vector<int> arr = {10, 5, 6, 1, 2, 9, 89, 100};
    std::cout << "Unsorted array is: ";
    for(auto &num:arr) {
        std::cout << num << " ";
    }
    bubbleSort(arr);
    std::cout << "Sorted array is: ";
    for(auto &num:arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}