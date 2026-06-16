#include <iostream>      // For input and output
#include <vector>        // For using vector
#include <climits>       // For INT_MAX

using namespace std;

int main() {

    int vertices;   // Variable to store number of vertices

    // Ask user for number of vertices
    cout << "Enter number of vertices: ";

    // Take input
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

    int source;   // Variable for source vertex

    // Input source vertex
    cout << "Enter source vertex: ";

    cin >> source;

    // Distance array
    vector<int> distance(vertices);

    // Visited array
    vector<bool> visited(vertices, false);

    // Initialize all distances with infinity
    for (int i = 0; i < vertices; i++) {

        distance[i] = INT_MAX;
    }

    // Distance of source vertex is 0
    distance[source] = 0;

    // Loop for all vertices
    for (int count = 0;
         count < vertices - 1;
         count++) {

        int min = INT_MAX;

        int u;   // Variable to store minimum distance vertex

        // Find unvisited vertex with minimum distance
        for (int v = 0; v < vertices; v++) {

            if (!visited[v] &&
                distance[v] <= min) {

                min = distance[v];

                u = v;
            }
        }

        // Mark selected vertex as visited
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++) {

            // Conditions:
            // 1. Vertex not visited
            // 2. Edge exists
            // 3. Distance is not infinity
            // 4. Shorter path found
            if (!visited[v] &&
                graph[u][v] &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {

                // Update shortest distance
                distance[v] =
                    distance[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest distances from source vertex "
         << source
         << ":" << endl;

    // Loop to print all distances
    for (int i = 0; i < vertices; i++) {

        cout << "Vertex "
             << i
             << " -> "
             << distance[i]
             << endl;
    }

    return 0;   // End program
}

/*
Example Input
Enter number of vertices: 5

Enter adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

Enter source vertex: 0
*/

/*
Example Output
Shortest distances from source vertex 0:
Vertex 0 -> 0
Vertex 1 -> 10
Vertex 2 -> 50
Vertex 3 -> 30
Vertex 4 -> 60
*/

/*
Simple Explanation
What is Dijkstra’s Algorithm?

Dijkstra’s Algorithm is a Greedy Algorithm used to find:

Shortest path from source vertex
To all other vertices in graph
Greedy Approach

At every step:

Choose the vertex with minimum distance
Update distances of adjacent vertices
Why is it Greedy?

Because it always selects:

The nearest unvisited vertex first
Working Example

Suppose source vertex is 0

Shortest paths become:

0 → 1 = 10
0 → 3 = 30
0 → 3 → 2 = 50
0 → 3 → 2 → 4 = 60
Distance Formula

Shortest distance update:

New Distance=Current Distance+Edge Weight

Time Complexity
Operation	Complexity
Finding Minimum Vertex	O(V²)
Overall Complexity	O(V²)
*/