#include <vector>
#include <iostream>
#include <algorithm>  // 包含 std::max 函数的头文件
#include <map>
#include <stack>
#include <string>
#include <queue>

using namespace std;

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& elem : vec) {  // 使用范围遍历来访问每个元素
        std::cout << elem << " ";
    }
    std::cout << std::endl;  // 在所有元素打印完后换行
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> areas;
        for (int i=0; i<heights.size(); i++) {
            int left = i;
            int right = i;

            for(; left>=0; left--) {
                if (heights[left] < heights[i]) break;
            }

            for(; right<heights.size(); right++) {
                if (heights[right] < heights[i]) break;
            }

            int h = heights[i];
            int w = right-left-1;

            areas.push_back(h*w);
        }
        int max_area = *max_element(areas.begin(), areas.end());
        return max_area;
    }
  
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> u_map1;
        std::unordered_map<char, int> u_map2;
        if (s.size() != t.size()) return false;
        for (auto& c1:s) {
            u_map1[c1]++;
        }
        for (auto& c2:t) {
            u_map2[c2]++;
        }
        // 使用范围 for 循环遍历 map
        if (u_map1 != u_map2) return false;
        else return true;
    }

    string removeDuplicates(string s) {
        stack<char> st;
        for (auto& c: s) {
            if (!st.empty() && c == st.top()) st.pop();
            else st.push(c);
        }

        string result;
        while(st.size() > 0) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int max_num(queue<int> que) {
        int max_val = que.front();  // 假设第一个元素为最大值
        std::queue<int> temp_q = que;  // 复制一个临时队列用于遍历

        while (!temp_q.empty()) {
            if (temp_q.front() > max_val) {
                max_val = temp_q.front();  // 更新最大值
            }
            temp_q.pop();  // 移动到下一个元素
        }
        return max_val;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1 && k == 1) return nums;
        
        std::vector<int> res;
        queue<int> que;
        int max = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] >= max) max = nums[i];
            que.push(nums[i]);

            if (que.size() == k) {
                res.push_back(max_num(que));
                que.pop();
            }
        }
        printVector(res);
        return res;
    }
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == val) {
                for (int j=i+1; j<nums.size(); j++) {
                    nums[j-1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;
    }

    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        for (int i=0; i<s.size()/2; i++) {
            char tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            j--;
        }
    }
};


int main(){
    Solution s1 = Solution();
    vector<int> heights1 = {2,1,5,6,2,3};
    // int max_area = s1.largestRectangleArea(heights1);
    // cout << "max area of Bar Chart is " << max_area << std::endl;

    // string s = "rat";
    // string t = "car";

    // string S = "abbaca";
    vector<char> s = {'a', 'b', 'b', 'a', 'c', 'a'};

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // int k = 3;
    s1.reverseString(s);
    printVector(s);
}