#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to construct Optimal BST and return minimum cost
float optimalBST(const vector<float>& p, int n) {
    vector<vector<float>> cost(n + 2, vector<float>(n + 1, 0));  // cost[i][j]
    vector<vector<float>> sum(n + 2, vector<float>(n + 1, 0));   // sum of probabilities
    vector<vector<int>> root(n + 2, vector<int>(n + 1, 0));      // root[i][j]

    for (int i = 1; i <= n; ++i) {
        cost[i][i] = p[i - 1];
        sum[i][i] = p[i - 1];
    }

    for (int l = 2; l <= n; ++l) { // l is chain length
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            cost[i][j] = numeric_limits<float>::max();
            sum[i][j] = sum[i][j - 1] + p[j - 1];

            for (int r = i; r <= j; ++r) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << "Root Table:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << root[i][j] << " ";
        cout << endl;
    }

    return cost[1][n];
}

int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    vector<float> p(n);
    cout << "Enter access/search probabilities for each key:\n";
    for (int i = 0; i < n; ++i) {
        cout << "p[" << i + 1 << "]: ";
        cin >> p[i];
    }

    float minCost = optimalBST(p, n);
    cout << "Minimum expected search cost: " << minCost << endl;

    return 0;
}
