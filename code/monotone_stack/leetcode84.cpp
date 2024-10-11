#include <vector>
#include <iostream>
#include <algorithm>  // 包含 std::max 函数的头文件
#include <map>

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
            if (c != st.top()) st.push(c);
            else st.pop();
        }
        string result;
        while(st.size() > 0) {
            result.push_back(st.top());
            st.pop()
        }
        return reverse(result.begin(), result.end());;
    }
};


int main(){
    Solution s1 = Solution();
    vector<int> heights1 = {2,1,5,6,2,3};
    // int max_area = s1.largestRectangleArea(heights1);
    // cout << "max area of Bar Chart is " << max_area << std::endl;

    string s = "rat";
    string t = "car";
    cout << s1.isAnagram(s,t) << " endl";
}