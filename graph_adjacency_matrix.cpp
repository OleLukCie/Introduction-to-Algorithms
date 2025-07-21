#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class GraphAdjMat {
    vector<int> vertices;
    vector<vector<int>> adjMat;

public:
    GraphAdjMat(const vector<int>& vertices, const vector<vector<int>>& edges) {
        for (int val : vertices) {
            addVertex(val);
        }
        for (const vector<int>& edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    int size() const {
        return vertices.size();
    }

    void addVertex(int val) {
        int n = size();
        vertices.push_back(val);
        adjMat.emplace_back(vector<int>(n, 0));
        for (vector<int>& row : adjMat) {
            row.push_back(0);
        }
    }

    void removeVertex(int index) {
        if (index < 0 || index >= size()) {
            throw out_of_range("��������Խ�磬ɾ��ʧ��");
        }
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        for (vector<int>& row : adjMat) {
            row.erase(row.begin() + index);
        }
    }

    void addEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("�����������Ϸ�����ӱ�ʧ��");
        }
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    void removeEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("�����������Ϸ���ɾ����ʧ��");
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    int findVertexIndex(int val) const {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == val) {
                return i;
            }
        }
        return -1;
    }

    vector<int> getAdjacentVertices(int index) const {
        if (index < 0 || index >= size()) {
            throw out_of_range("��������Խ��");
        }
        vector<int> adjVertices;
        for (int j = 0; j < size(); j++) {
            if (adjMat[index][j] == 1) {
                adjVertices.push_back(vertices[j]);
            }
        }
        return adjVertices;
    }

    bool isAdjacent(int val1, int val2) const {
        int i = findVertexIndex(val1);
        int j = findVertexIndex(val2);
        if (i == -1 || j == -1 || i == j) {
            return false;
        }
        return adjMat[i][j] == 1;
    }

    void printVector(const vector<int>& vec) const {
        cout << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void printVectorMatrix(const vector<vector<int>>& mat) const {
        for (const vector<int>& row : mat) {
            cout << "  ";
            printVector(row);
        }
    }

    void print() const {
        cout << "===== ͼ��Ϣ =====" << endl;
        cout << "�����б�����-ֵ����" << endl;
        for (int i = 0; i < size(); i++) {
            cout << "  ����" << i << "��" << vertices[i] << endl;
        }
        cout << "�ڽӾ�����-�ж�Ӧ����������1=�бߣ�0=�ޱߣ���" << endl;
        printVectorMatrix(adjMat);
        cout << "==================" << endl << endl;
    }
};


int main() {
    vector<int> vertices = { 1, 2, 3, 4 };
    vector<vector<int>> edges = { {0, 1}, {0, 3}, {1, 2}, {2, 3} };

    GraphAdjMat graph(vertices, edges);
    cout << "��ʼͼ��" << endl;
    graph.print();

    int idx = graph.findVertexIndex(3);
    cout << "����ֵ3��������" << idx << endl;

    vector<int> adj = graph.getAdjacentVertices(0);
    cout << "����0��ֵ1�����ڽӶ��㣺";
    graph.printVector(adj);

    bool isAdj = graph.isAdjacent(2, 4);
    cout << "����2��4�Ƿ����ڣ�" << (isAdj ? "��" : "��") << endl;

    graph.addVertex(5);
    graph.addEdge(4, 0);
    cout << "��Ӷ���5�����ӵ�1��" << endl;
    graph.print();

    return 0;
}