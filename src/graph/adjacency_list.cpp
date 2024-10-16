#include <iostream>
#include <vector>
#include <list>

using namespace std;

class GraphAdjList {
private:
    vector<list<int>> adjList; // 邻接表

public:
    GraphAdjList(int numNodes) {
        adjList.resize(numNodes); // 初始化邻接表
    }

    // 添加边（有向图）,i/j 是节点序号
    void addEdge(int i, int j) {
        adjList[i-1].push_back(j-1);
        // adjList[j].push_back(i); // 如果是有向图则去掉这一行
    }

    // 打印邻接表
    void printList() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Node " << i+1 << ":";
            for (int neighbor : adjList[i]) {
                cout << " " << neighbor+1;
            }
            cout << endl;
        }
    }
};

int main() {
    GraphAdjList graph(5); // 创建一个有 5 个节点的图

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(2, 4);
    graph.addEdge(4, 1);
    graph.addEdge(4, 2);
    graph.addEdge(5, 4);
    graph.addEdge(5, 3);

    graph.printList(); // 打印邻接表

    return 0;
}