#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<vector<int>> adjMatrix;
vector<vector<int>> adjList;
map<int, string> places;
vector<bool> visited;

void DFS(int node) {
    visited[node] = true;
    cout << places[node] << " ";
    for (int i = 0; i < adjMatrix.size(); ++i)
        if (adjMatrix[node][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    vector<bool> vis(adjList.size(), false);
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << places[curr] << " ";
        for (int nbr : adjList[curr]) {
            if (!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of landmarks (nodes): ";
    cin >> n;

    adjMatrix.assign(n, vector<int>(n, 0));
    adjList.assign(n, vector<int>());
    visited.assign(n, false);

    cout << "Enter landmark names:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        cout << "Node " << i << ": ";
        cin >> ws;
        getline(cin, name);
        places[i] = name;
    }

    cout << "Enter number of paths (edges): ";
    cin >> e;
    cout << "Enter each path as: from to (node numbers):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start = 0;
    cout << "\nStarting DFS from: " << places[start] << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nStarting BFS from: " << places[start] << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}
