#include <iostream>      // For input and output
#include <queue>         // For priority queue
#include <vector>        // For vector
#include <cmath>         // For abs() function

using namespace std;

// Structure to represent each cell/node
struct Node {

    int x, y;            // Coordinates of the node

    int g;               // Cost from start node to current node

    int h;               // Heuristic cost to goal node

    int f;               // Total cost = g + h

    // Constructor
    Node(int x, int y, int g, int h) {

        this->x = x;     // Assign x coordinate

        this->y = y;     // Assign y coordinate

        this->g = g;     // Assign actual cost

        this->h = h;     // Assign heuristic cost

        this->f = g + h; // Calculate total cost
    }
};

// Comparator for priority queue
// Node with smaller f value gets higher priority
struct Compare {

    bool operator()(Node a, Node b) {

        return a.f > b.f;
    }
};

// Function to calculate heuristic value
// Using Manhattan Distance
int heuristic(int x1, int y1, int x2, int y2) {

    // Return Manhattan distance
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* Algorithm function
void AStar(vector<vector<int>>& grid,
           pair<int, int> start,
           pair<int, int> goal) {

    // Get number of rows
    int rows = grid.size();

    // Get number of columns
    int cols = grid[0].size();

    // Priority queue for open list
    priority_queue<Node, vector<Node>, Compare> openList;

    // Visited array
    vector<vector<bool>> visited(rows,
                                 vector<bool>(cols, false));

    // Possible movement directions
    int dx[] = {-1, 1, 0, 0}; // Up, Down
    int dy[] = {0, 0, -1, 1}; // Left, Right

    // Get heuristic value for start node
    int h = heuristic(start.first,
                      start.second,
                      goal.first,
                      goal.second);

    // Push start node into priority queue
    openList.push(Node(start.first,
                       start.second,
                       0,
                       h));

    // Continue until open list becomes empty
    while (!openList.empty()) {

        // Get node with smallest f value
        Node current = openList.top();

        // Remove node from queue
        openList.pop();

        // Get current coordinates
        int x = current.x;
        int y = current.y;

        // Skip if already visited
        if (visited[x][y]) {
            continue;
        }

        // Mark current node as visited
        visited[x][y] = true;

        // Print current node
        cout << "(" << x << "," << y << ") ";

        // Check if goal node is reached
        if (x == goal.first &&
            y == goal.second) {

            cout << "\nGoal Reached!" << endl;

            return;
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {

            // Calculate new x coordinate
            int newX = x + dx[i];

            // Calculate new y coordinate
            int newY = y + dy[i];

            // Check boundaries
            if (newX >= 0 &&
                newX < rows &&
                newY >= 0 &&
                newY < cols) {

                // Check obstacle and visited
                if (grid[newX][newY] == 0 &&
                    !visited[newX][newY]) {

                    // Calculate new g cost
                    int newG = current.g + 1;

                    // Calculate new h cost
                    int newH = heuristic(newX,
                                         newY,
                                         goal.first,
                                         goal.second);

                    // Push new node into queue
                    openList.push(Node(newX,
                                       newY,
                                       newG,
                                       newH));
                }
            }
        }
    }

    // If no path exists
    cout << "\nNo Path Found!" << endl;
}

int main() {

    int rows, cols;

    // Input number of rows
    cout << "Enter number of rows: ";
    cin >> rows;

    // Input number of columns
    cout << "Enter number of columns: ";
    cin >> cols;

    // Create grid
    vector<vector<int>> grid(rows,
                             vector<int>(cols));

    cout << "Enter grid values:" << endl;
    cout << "0 = Free Path" << endl;
    cout << "1 = Obstacle" << endl;

    // Input grid values
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cin >> grid[i][j];
        }
    }

    int sx, sy;

    // Input start coordinates
    cout << "Enter start coordinates (x y): ";
    cin >> sx >> sy;

    int gx, gy;

    // Input goal coordinates
    cout << "Enter goal coordinates (x y): ";
    cin >> gx >> gy;

    // Call A* Algorithm
    cout << "\nPath Traversed: ";

    AStar(grid,
          {sx, sy},
          {gx, gy});

    return 0;
}

/*
Example Input
Enter number of rows: 5
Enter number of columns: 5

Enter grid values:
0 0 0 1 0
1 0 0 1 0
0 0 0 0 0
0 1 1 0 1
0 0 0 0 0

Enter start coordinates (x y): 0 0
Enter goal coordinates (x y): 4 4
*/
/*
Example Output
Path Traversed:
(0,0) (0,1) (1,1) (2,1) (2,2) (2,3) (3,3) (4,3) (4,4)

Goal Reached!
*/
/*
Simple Explanation of A* Algorithm
A* uses:
g → Distance from start node
h → Estimated distance to goal node
f = g + h
It always chooses:

The node with the smallest f value.

Heuristic Used:

Manhattan Distance:
h = |x1 - x2| + |y1 - y2|
This heuristic is suitable for grid-based pathfinding where movement 
is allowed in four directions (up, down, left, right).
*/