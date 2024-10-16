#include <iostream>
#include <vector>

using namespace std;

class GraphAdjMatrix {
private:
    vector<vector<int>> adjMatrix; // 邻接矩阵

public:
    GraphAdjMatrix(int numNodes) {
        adjMatrix.resize(numNodes, vector<int>(numNodes, 0)); // 初始化矩阵
    }

    // 添加边（无向图）
    void addEdge(int i, int j, int weight = 1) {
        adjMatrix[i][j] = weight;
        adjMatrix[j][i] = weight; // 如果是有向图则去掉这一行
    }

    // 打印邻接矩阵
    void printMatrix() {
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphAdjMatrix graph(4); // 创建一个有 5 个节点的图

    graph.addEdge(1, 0);
    graph.addEdge(2, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 1);
    graph.addEdge(3, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);

    graph.printMatrix(); // 打印邻接矩阵

    return 0;
}