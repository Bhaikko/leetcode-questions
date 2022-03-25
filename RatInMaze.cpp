#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    int x;
    int y;
    bool isBlocked;
    bool isTraversed;
    
    int parentX;
    int parentY;
};

int numPaths = 0;

string FillPath(Node** grid, int n)
{
    string path = "";

    Node current = grid[n - 1][n - 1];

    while (current.parentX != -1) {
        Node parent = grid[current.parentX][current.parentY];

        // cout << parent.x << " " << parent.y << endl;

        if (parent.x - current.x == 1) {
            path = "L" + path;
        } else  if (parent.x - current.x == -1) {
            path = "R" + path;
        } else if (parent.y - current.y == 1) {
            path = "U" + path;
        } else {
            path = "D" + path;
        }

        current = parent;
    }

    return path;
}

void FindPath(
    Node** grid,
    int n,
    int currentX,
    int currentY,
    vector<string>& paths
) {
    if (
        grid[currentX][currentY].isTraversed || 
        grid[currentX][currentY].isBlocked
    ) {
        return;
    }
    
    if (currentX == n - 1 && currentY == n - 1) {
        numPaths++;
        paths.push_back(FillPath(grid, n));
        return;
    }


    grid[currentX][currentY].isTraversed = true;

    if (currentX + 1 < n) {
        if (!grid[currentX + 1][currentY].isTraversed) {
            grid[currentX + 1][currentY].parentX = currentX;
            grid[currentX + 1][currentY].parentY = currentY;

            FindPath(grid, n, currentX + 1, currentY, paths);
        }
    }

    if (currentX - 1 >= 0) {
        if (!grid[currentX - 1][currentY].isTraversed) {
            grid[currentX - 1][currentY].parentX = currentX;
            grid[currentX - 1][currentY].parentY = currentY;

            FindPath(grid, n, currentX - 1, currentY, paths);
        }
    }

    if (currentY + 1 < n) {
        if (!grid[currentX][currentY + 1].isTraversed) {
            grid[currentX][currentY + 1].parentX = currentX;
            grid[currentX][currentY + 1].parentY = currentY;

            FindPath(grid, n, currentX, currentY + 1, paths);
        }
    }

    if (currentY - 1 >= 0) {
        if (!grid[currentX][currentY - 1].isTraversed) {
            grid[currentX][currentY - 1].parentX = currentX;
            grid[currentX][currentY - 1].parentY = currentY;

            FindPath(grid, n, currentX, currentY - 1, paths);
        }
    }

    grid[currentX][currentY].isTraversed = false;
}

void solution()
{
    int n;
    cin >> n;

    Node** grid = new Node*[n];
    for (int i = 0; i < n; i++) {
        grid[i] = new Node[n];
        for (int j = 0; j < n; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;

            bool a; cin >> a;
            grid[i][j].isBlocked = !a;

            grid[i][j].parentX = -1;
            grid[i][j].parentY = -1;

            grid[i][j].isTraversed = false;
        }
    }

    vector<string> paths;

    FindPath(grid, n, 0, 0, paths);

    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << " ";
    }
    cout << endl;

    // cout << numPaths << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}