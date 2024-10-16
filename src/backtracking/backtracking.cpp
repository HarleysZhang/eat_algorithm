#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<string> checkerboard(n, string(n, '.')); // '.' 表示空，'Q' 表示皇后，初始化空棋盘
        backtrack(checkerboard, 0);
        return res;
    }

    void backtrack(vector<string>& board, int row) {

    }
};

int main() {

}
