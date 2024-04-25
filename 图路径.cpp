#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 用于表示图中的边
struct Edge 
{
    int source, destination, weight;
};

// 创建无向图
vector<vector<int>> createGraph(int numVertices, vector<Edge>& edges) 
{
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INT_MAX));

    for (const auto& edge : edges) {
        graph[edge.source][edge.destination] = edge.weight;
        graph[edge.destination][edge.source] = edge.weight;
    }

    for (int i = 0; i < numVertices; ++i) {
        graph[i][i] = 0;  // 顶点到自身的距离为0
    }

    return graph;
}

// 使用Floyd算法求解最短路径
vector<vector<int>> floydShortestPaths(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<vector<int>> distances = graph;

    for (int k = 0; k < numVertices; ++k) 
    {
        for (int i = 0; i < numVertices; ++i) 
        {
            for (int j = 0; j < numVertices; ++j) 
            {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX
                    && distances[i][k] + distances[k][j] < distances[i][j]) 
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    return distances;
}

int main() {
    int numVertices, numEdges;

    cout << "请输入顶点的数量：";
    cin >> numVertices;

    cout << "请输入边的数量：";
    
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "请输入边的信息，格式为 <源顶点> <目标顶点> <权重>：" << endl;
    for (int i = 0; i < numEdges; ++i) 
    {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    vector<vector<int>> graph = createGraph(numVertices, edges);
    vector<vector<int>> shortestPaths = floydShortestPaths(graph);

    cout << "图的结构：" << endl;
    for (const auto& row : graph) 
    {
        for (const auto& weight : row) 
        {
            if (weight == INT_MAX) 
            {
                cout << "∞ ";
            }
            else {
                cout << weight << " ";
            }
        }
        cout << endl;
    }

    cout << endl << "任意两个城市之间的最短路径：" << endl;
    for (int i = 0; i < numVertices; ++i) 
    {
        for (int j = i + 1; j < numVertices; ++j) 
        {
            cout << "城市 " << i << " 到城市 " << j << " 的最短路径长度为：";
            if (shortestPaths[i][j] == INT_MAX) 
            {
                cout << "无穷大" << endl;
            }
            else {
                cout << shortestPaths[i][j] << endl;
            }
        }
    }

    return 0;
}

/*
5
7
0 1 4
0 2 1
1 2 2
1 3 5
2 3 1
2 4 6
3 4 3

*/
