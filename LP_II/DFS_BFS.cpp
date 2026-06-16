#include <iostream>     // For input and output
#include <vector>       // For using vector
#include <queue>        // For using queue in BFS

using namespace std;

// Graph class
class Graph {
    int vertices;                          // Stores number of vertices
    vector<vector<int>> adjList;          // Adjacency list to store graph

public:

    // Constructor to initialize graph
    Graph(int v) {
        vertices = v;                     // Assign total vertices
        adjList.resize(v);                // Resize adjacency list
    }

    // Function to add an edge in undirected graph
    void addEdge(int u, int v) {

        // Add v to u's adjacency list
        adjList[u].push_back(v);

        // Add u to v's adjacency list
        // because graph is undirected
        adjList[v].push_back(u);
    }

    // Recursive DFS function
    void DFS(int start, vector<bool>& visited) {

        // Mark current node as visited
        visited[start] = true;

        // Print current vertex
        cout << start << " ";

        // Traverse all adjacent vertices
        for (int neighbor : adjList[start]) {

            // Visit only unvisited nodes
            if (!visited[neighbor]) {

                // Recursive call for DFS
                DFS(neighbor, visited);
            }
        }
    }

    // BFS function
    void BFS(int start) {

        // Create visited array
        vector<bool> visited(vertices, false);

        // Create queue for BFS
        queue<int> q;

        // Mark starting node as visited
        visited[start] = true;

        // Push starting node into queue
        q.push(start);

        // Continue until queue becomes empty
        while (!q.empty()) {

            // Get front element from queue
            int current = q.front();

            // Remove front element
            q.pop();

            // Print current node
            cout << current << " ";

            // Traverse adjacent vertices
            for (int neighbor : adjList[current]) {

                // If neighbor is not visited
                if (!visited[neighbor]) {

                    // Mark it visited
                    visited[neighbor] = true;

                    // Push neighbor into queue
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {

    int vertices, edges;

    // Take number of vertices from user
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create graph object
    Graph g(vertices);

    // Take number of edges from user
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    // Loop to input all edges
    for (int i = 0; i < edges; i++) {

        int u, v;

        // Input edge vertices
        cin >> u >> v;

        // Add edge to graph
        g.addEdge(u, v);
    }

    int start;

    // Input starting vertex
    cout << "Enter starting vertex: ";
    cin >> start;

    // Create visited array for DFS
    vector<bool> visited(vertices, false);

    // Print DFS traversal
    cout << "\nDepth First Search (DFS): ";

    // Call DFS function
    g.DFS(start, visited);

    // Print new line
    cout << endl;

    // Print BFS traversal
    cout << "Breadth First Search (BFS): ";

    // Call BFS function
    g.BFS(start);

    return 0;   // End program
}

/*
Example Input
Enter number of vertices: 5
Enter number of edges: 4
Enter edges (u v):
0 1
0 2
1 3
1 4
Enter starting vertex: 0
*/