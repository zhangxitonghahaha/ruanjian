#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// ���ڱ�ʾͼ�еı�
struct Edge 
{
    int source, destination, weight;
};

// ��������ͼ
vector<vector<int>> createGraph(int numVertices, vector<Edge>& edges) 
{
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INT_MAX));

    for (const auto& edge : edges) {
        graph[edge.source][edge.destination] = edge.weight;
        graph[edge.destination][edge.source] = edge.weight;
    }

    for (int i = 0; i < numVertices; ++i) {
        graph[i][i] = 0;  // ���㵽����ľ���Ϊ0
    }

    return graph;
}

// ʹ��Floyd�㷨������·��
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

    cout << "�����붥���������";
    cin >> numVertices;

    cout << "������ߵ�������";
    
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "������ߵ���Ϣ����ʽΪ <Դ����> <Ŀ�궥��> <Ȩ��>��" << endl;
    for (int i = 0; i < numEdges; ++i) 
    {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    vector<vector<int>> graph = createGraph(numVertices, edges);
    vector<vector<int>> shortestPaths = floydShortestPaths(graph);

    cout << "ͼ�Ľṹ��" << endl;
    for (const auto& row : graph) 
    {
        for (const auto& weight : row) 
        {
            if (weight == INT_MAX) 
            {
                cout << "�� ";
            }
            else {
                cout << weight << " ";
            }
        }
        cout << endl;
    }

    cout << endl << "������������֮������·����" << endl;
    for (int i = 0; i < numVertices; ++i) 
    {
        for (int j = i + 1; j < numVertices; ++j) 
        {
            cout << "���� " << i << " ������ " << j << " �����·������Ϊ��";
            if (shortestPaths[i][j] == INT_MAX) 
            {
                cout << "�����" << endl;
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
