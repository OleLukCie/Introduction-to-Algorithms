#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

// Vertex class to represent a node in the graph
// Each vertex contains a value
class Vertex {
public:
    int val;  // Value stored in the vertex
    Vertex(int v) : val(v) {}  // Constructor to initialize vertex value
};

// Graph representation using adjacency list
// Key: pointer to a Vertex, Value: vector of adjacent vertices
struct GraphAdjList {
    std::unordered_map<Vertex*, std::vector<Vertex*>> adjList;
};

/* Breadth-First Search traversal */
// Use adjacency list to get all adjacent vertices of a given vertex
std::vector<Vertex*> graphBFS(GraphAdjList& graph, Vertex* startVet) {
    // Store the traversal sequence
    std::vector<Vertex*> res;
    // Hash set to record visited vertices
    std::unordered_set<Vertex*> visited = { startVet };
    // Queue for BFS implementation
    std::queue<Vertex*> que;
    que.push(startVet);

    // Start from the given vertex, traverse until all reachable vertices are visited
    while (!que.empty()) {
        Vertex* vet = que.front();
        que.pop();          // Dequeue the front vertex
        res.push_back(vet); // Record the visited vertex

        // Traverse all adjacent vertices of the current vertex
        for (auto adjVet : graph.adjList[vet]) {
            if (visited.count(adjVet))
                continue;            // Skip already visited vertices
            que.push(adjVet);        // Enqueue only unvisited vertices
            visited.emplace(adjVet); // Mark the vertex as visited
        }
    }
    // Return the traversal sequence
    return res;
}

/* Depth-First Search helper function */
void dfs(GraphAdjList& graph, std::unordered_set<Vertex*>& visited,
    std::vector<Vertex*>& res, Vertex* vet) {
    res.push_back(vet);   // Record the visited vertex
    visited.emplace(vet); // Mark the vertex as visited

    // Traverse all adjacent vertices of the current vertex
    for (Vertex* adjVet : graph.adjList[vet]) {
        if (visited.count(adjVet))
            continue; // Skip already visited vertices
        // Recursively visit adjacent vertices
        dfs(graph, visited, res, adjVet);
    }
}

/* Depth-First Search traversal */
// Use adjacency list to get all adjacent vertices of a given vertex
std::vector<Vertex*> graphDFS(GraphAdjList& graph, Vertex* startVet) {
    // Store the traversal sequence
    std::vector<Vertex*> res;
    // Hash set to record visited vertices
    std::unordered_set<Vertex*> visited;
    // Start DFS from the given vertex
    dfs(graph, visited, res, startVet);
    return res;
}

// Example usage
int main() {
    // 1. Create vertices
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);
    Vertex* v5 = new Vertex(5);

    // 2. Build the graph using adjacency list
    GraphAdjList graph;
    graph.adjList[v1] = { v2, v3 };    // v1 is connected to v2 and v3
    graph.adjList[v2] = { v1, v4, v5 };// v2 is connected to v1, v4 and v5
    graph.adjList[v3] = { v1 };        // v3 is connected to v1
    graph.adjList[v4] = { v2 };        // v4 is connected to v2
    graph.adjList[v5] = { v2 };        // v5 is connected to v2

    // 3. Perform BFS traversal starting from v1
    std::vector<Vertex*> bfsResult = graphBFS(graph, v1);
    std::cout << "BFS traversal order: ";
    for (Vertex* vet : bfsResult) {
        std::cout << vet->val << " ";
    }

    // 4. Perform DFS traversal starting from v1
    std::vector<Vertex*> dfsResult = graphDFS(graph, v1);
    std::cout << "\nDFS traversal order: ";
    for (Vertex* vet : dfsResult) {
        std::cout << vet->val << " ";
    }

    // 5. Release dynamically allocated memory
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;

    return 0;
}
