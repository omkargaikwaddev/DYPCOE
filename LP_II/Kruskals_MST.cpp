#include <iostream>      // For input and output
#include <vector>        // For using vector
#include <algorithm>     // For sorting edges

using namespace std;

// Structure to represent an edge
struct Edge {

    int source;       // Starting vertex of edge

    int destination;  // Ending vertex of edge

    int weight;       // Weight of edge
};

// Function to compare edges by weight
bool compare(Edge a, Edge b) {

    // Sort edges in ascending order
    return a.weight < b.weight;
}

// Disjoint Set class for Union-Find
class DisjointSet {

    vector<int> parent;   // Parent array

public:

    // Constructor
    DisjointSet(int n) {

        // Resize parent vector
        parent.resize(n);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    // Function to find parent of node
    int find(int node) {

        // If node is parent of itself
        if (parent[node] == node) {

            return node;
        }

        // Recursively find ultimate parent
        return parent[node] = find(parent[node]);
    }

    // Function to unite two sets
    void unite(int u, int v) {

        // Find parent of first node
        int parentU = find(u);

        // Find parent of second node
        int parentV = find(v);

        // Connect one set to another
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

    // Sort edges according to minimum weight
    sort(edgeList.begin(),
         edgeList.end(),
         compare);

    // Create Disjoint Set object
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

        // If vertices belong to different sets
        if (parentSource != parentDestination) {

            // Print selected edge
            cout << e.source
                 << " - "
                 << e.destination
                 << " : "
                 << e.weight
                 << endl;

            // Add edge weight to total cost
            totalCost += e.weight;

            // Union both vertices
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
Simple Explanation
What is Kruskal’s Algorithm?

Kruskal’s Algorithm is a Greedy Algorithm used to find:

Minimum Spanning Tree (MST)

It connects all vertices:

With minimum total cost
Without forming cycles
Greedy Approach

At every step:

Select the smallest weight edge
Add it only if it does not create a cycle
Why is it Greedy?

Because it always chooses:

The minimum available edge first
Working Example

Given edges:

Edge	Weight
0-1	    10
0-2	    6
0-3	    5
1-3	    15
2-3	    4

After sorting:

2-3 = 4
0-3 = 5
0-2 = 6
0-1 = 10
1-3 = 15

Selected MST edges:

2-3 = 4
0-3 = 5
0-1 = 10

Total Cost:

4 + 5 + 10 = 19
Time Complexity
Operation	            Complexity
Sorting Edges	        O(E log E)
Union-Find Operations	Nearly O(1)
Overall Complexity	    O(E log E)
*/