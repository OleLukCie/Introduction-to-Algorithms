#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Vertex {
public:
    int val;
    Vertex(int v) : val(v) {}
};

vector<int> vetsToVals(const vector<Vertex*>& vets) {
    vector<int> vals;
    for (const Vertex* vet : vets) {
        vals.push_back(vet->val);
    }
    return vals;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

class GraphAdjList {
public:
    unordered_map<Vertex*, vector<Vertex*>> adjList;

    void remove(vector<Vertex*>& vec, Vertex* vet) {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] == vet) {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    GraphAdjList(const vector<vector<Vertex*>>& edges) {
        for (const vector<Vertex*>& edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    int size() {
        return adjList.size();
    }

    void addEdge(Vertex* vet1, Vertex* vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
            throw invalid_argument("���㲻���ڻ򶥵���ͬ");
        }
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    void removeEdge(Vertex* vet1, Vertex* vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
            throw invalid_argument("���㲻���ڻ򶥵���ͬ");
        }
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    void addVertex(Vertex* vet) {
        if (adjList.count(vet)) {
            return;
        }
        adjList[vet] = vector<Vertex*>();
    }

    void removeVertex(Vertex* vet) {
        if (!adjList.count(vet)) {
            throw invalid_argument("���㲻����");
        }
        adjList.erase(vet);
        for (auto& pair : adjList) {
            remove(pair.second, vet);
        }
    }

    void print() {
        cout << "�ڽӱ�" << endl;
        for (const auto& pair : adjList) {
            Vertex* vertex = pair.first;
            const vector<Vertex*>& neighbors = pair.second;
            cout << vertex->val << " ���ڽӶ��㣺";
            printVector(vetsToVals(neighbors));
        }
        cout << endl;
    }
};

int main() {
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    vector<vector<Vertex*>> edges = { {v1, v2}, {v1, v3}, {v2, v3}, {v2, v4} };

    GraphAdjList graph(edges);
    cout << "=== ��ʼͼ��4�����㣬4���ߣ� ===" << endl;
    graph.print();

    Vertex* v5 = new Vertex(5);
    graph.addVertex(v5);
    graph.addEdge(v3, v5);
    cout << "=== ��Ӷ���5�ͱ�(3-5)�� ===" << endl;
    graph.print();

    graph.removeEdge(v2, v3);
    cout << "=== ɾ����(2-3)�� ===" << endl;
    graph.print();

    graph.removeVertex(v2);
    cout << "=== ɾ������2�� ===" << endl;
    graph.print();

    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;

    return 0;
}