#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) structure for Union-Find
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
// Kruskal’s MST algorithm
void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare); // Sort edges by weight
    DSU dsu(V);

    vector<Edge> result;
    int totalCost = 0;

    for(Edge e : edges) {
        if (dsu.find(e.src) != dsu.find(e.dest)) {
            dsu.unite(e.src, e.dest);
            result.push_back(e);
            totalCost += e.weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (Edge e : result)
        cout << e.src << " -- " << e.dest << " == " << e.weight << "\n";

    cout << "Total cost of connecting all offices: " << totalCost << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of offices (vertices): ";
    cin >> V;
    cout << "Enter number of possible connections (edges): ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter each connection as: src dest cost\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(V, edges);

    return 0;
}
