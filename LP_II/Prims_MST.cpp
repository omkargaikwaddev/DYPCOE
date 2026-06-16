#include <iostream>      // For input and output
#include <vector>        // For using vector
#include <climits>       // For INT_MAX value

using namespace std;

int main() {

    int vertices;   // Variable to store number of vertices

    // Ask user for number of vertices
    cout << "Enter number of vertices: ";

    // Take input from user
    cin >> vertices;

    // Create adjacency matrix
    vector<vector<int>> graph(vertices,
                              vector<int>(vertices));

    cout << "Enter adjacency matrix:" << endl;
    cout << "(Enter 0 if no edge exists)" << endl;

    // Input adjacency matrix
    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {

            cin >> graph[i][j];
        }
    }

    // Array to store parent of MST
    vector<int> parent(vertices);

    // Array to store minimum edge weight
    vector<int> key(vertices);

    // Array to track visited vertices
    vector<bool> mstSet(vertices, false);

    // Initialize all keys with infinity
    for (int i = 0; i < vertices; i++) {

        key[i] = INT_MAX;
    }

    // Start from vertex 0
    key[0] = 0;

    // First node has no parent
    parent[0] = -1;

    // Loop for all vertices
    for (int count = 0;
         count < vertices - 1;
         count++) {

        int min = INT_MAX;

        int u;   // Variable to store minimum vertex

        // Find minimum key vertex
        for (int v = 0; v < vertices; v++) {

            // Select unvisited vertex with minimum key
            if (mstSet[v] == false &&
                key[v] < min) {

                min = key[v];

                u = v;
            }
        }

        // Mark selected vertex as visited
        mstSet[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < vertices; v++) {

            // Conditions:
            // 1. Edge exists
            // 2. Vertex not visited
            // 3. Smaller weight found
            if (graph[u][v] &&
                mstSet[v] == false &&
                graph[u][v] < key[v]) {

                // Set parent
                parent[v] = u;

                // Update minimum weight
                key[v] = graph[u][v];
            }
        }
    }

    // Variable to store total minimum cost
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    // Print MST edges
    for (int i = 1; i < vertices; i++) {

        cout << parent[i]
             << " - "
             << i
             << " : "
             << graph[i][parent[i]]
             << endl;

        // Add edge weight to total cost
        totalCost += graph[i][parent[i]];
    }

    // Print total minimum cost
    cout << "\nTotal Minimum Cost = "
         << totalCost
         << endl;

    return 0;   // End program
}

/*
Example Input
Enter number of vertices: 5

Enter adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/

/*
Example Output
Edges in Minimum Spanning Tree:
0 - 1 : 2
1 - 2 : 3
0 - 3 : 6
1 - 4 : 5

Total Minimum Cost = 16
*/

/*
Simple Explanation
What is Prim’s Algorithm?

Prim’s Algorithm is a Greedy Algorithm used to find:

Minimum Spanning Tree (MST)

It connects all vertices with:

Minimum total edge weight
No cycles
Greedy Approach

At every step:

Choose the minimum weight edge
Connect a new vertex to MST
Why is it Greedy?

Because it always chooses:

The locally minimum edge available

Working

Suppose graph is:

0 --2-- 1
|      / \
6     3   5
|   /      \
3 -------- 4

Selected edges:

0-1 = 2
1-2 = 3
1-4 = 5
0-3 = 6

Total Cost:

2 + 3 + 5 + 6 = 16
Time Complexity
Operation	Complexity
Finding Minimum Vertex	O(V²)
Overall Complexity	O(V²)
*/