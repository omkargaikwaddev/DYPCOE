#include <iostream>      // For input and output
#include <vector>        // For using vector
#include <algorithm>     // For sorting edges

using namespace std;

// Structure to store an edge
struct Edge {

    int source;     // Starting vertex

    int destination; // Ending vertex

    int weight;     // Weight of edge
};

// Function to compare edges by weight
bool compare(Edge a, Edge b) {

    // Sort edges in ascending order
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find) class
class DisjointSet {

    vector<int> parent;   // Stores parent of each node

public:

    // Constructor
    DisjointSet(int n) {

        // Resize parent vector
        parent.resize(n);

        // Initially every node is parent of itself
        for (int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    // Function to find parent of a node
    int find(int node) {

        // If node is its own parent
        if (parent[node] == node) {

            return node;
        }

        // Recursively find ultimate parent
        return parent[node] = find(parent[node]);
    }

    // Function to union two sets
    void unite(int u, int v) {

        // Find parents of both nodes
        int parentU = find(u);
        int parentV = find(v);

        // Connect one parent to another
        parent[parentU] = parentV;
    }
};

int main() {

    int vertices, edges;

    // Input number of vertices
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Vector to store all edges
    vector<Edge> edgeList;

    cout << "Enter source destination weight:" << endl;

    // Loop to input all edges
    for (int i = 0; i < edges; i++) {

        Edge e;

        // Input source vertex
        cin >> e.source;

        // Input destination vertex
        cin >> e.destination;

        // Input edge weight
        cin >> e.weight;

        // Store edge in vector
        edgeList.push_back(e);
    }

    // Sort edges according to weight
    sort(edgeList.begin(),
         edgeList.end(),
         compare);

    // Create disjoint set object
    DisjointSet ds(vertices);

    // Variable to store total MST cost
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    // Traverse all sorted edges
    for (Edge e : edgeList) {

        // Find parent of source
        int parentSource = ds.find(e.source);

        // Find parent of destination
        int parentDestination = ds.find(e.destination);

        // If both vertices belong to different sets
        if (parentSource != parentDestination) {

            // Include edge in MST
            cout << e.source
                 << " - "
                 << e.destination
                 << " : "
                 << e.weight
                 << endl;

            // Add edge weight to total cost
            totalCost += e.weight;

            // Union both sets
            ds.unite(e.source,
                     e.destination);
        }
    }

    // Print total minimum cost
    cout << "\nTotal Minimum Cost = "
         << totalCost
         << endl;

    return 0;   // End program
}

/*
Example Input
Enter number of vertices: 4
Enter number of edges: 5

Enter source destination weight:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/

/*
Example Output
Edges in Minimum Spanning Tree:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10

Total Minimum Cost = 19
*/

/*
What is Minimum Spanning Tree (MST)?

A Minimum Spanning Tree:

Connects all vertices
Has no cycles
Has minimum total edge weight
Greedy Method Used

This program uses Kruskal’s Algorithm.

It works by:

Sorting edges by smallest weight
Picking smallest edge first
Avoiding cycles
Repeating until all vertices are connected
Why is it Greedy?

Because at every step it chooses:

The minimum weight edge available

without worrying about future choices.

Time Complexity
Operation	            Complexity
Sorting Edges	        O(E log E)
Union-Find Operations	Almost O(1)
Overall	                O(E log E)
*/