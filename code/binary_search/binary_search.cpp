#include <iostream>
#include <vector>

// 二分查找函数
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 检查中间元素是否为目标值
        if (arr[mid] == target) {
            return mid; // 找到目标值，返回其索引
        }
        // 如果目标值小于中间元素，缩小右边界
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // 如果目标值大于中间元素，缩小左边界
        else {
            left = mid + 1;
        }
    }

    return -1; // 未找到目标值，返回 -1
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}