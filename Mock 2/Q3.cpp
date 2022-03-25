#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Coordinate
{
    int row;
    int col;
};


void HamiltonPaths(
    int** arr, 
    int n, 
    int m, 
    int row,
    int col, 
    bool** isVisited, 
    vector<Coordinate>& path,
    int walkableCount,
    int& numberOfPaths
) {
    if (path.size() == walkableCount + 1 && arr[row][col] == 2) {
        // cout << path.size() << " " << arr[row][col] << endl;
        numberOfPaths++;

        // for (Coordinate coordinate : path) {
        //     printf("(%i, %i) ", coordinate.row, coordinate.col);
        // }

        // printf("\n");

        return;
    }

    if (col - 1 >= 0) {
        // Left
        if (!isVisited[row][col - 1] && arr[row][col - 1] != -1) {
            isVisited[row][col - 1] = true;

            Coordinate coordinate;
            coordinate.row = row;
            coordinate.col = col - 1;
            path.push_back(coordinate);

            HamiltonPaths(
                arr,
                n,
                m,
                row,
                col - 1,
                isVisited,
                path,
                walkableCount,
                numberOfPaths
            );

            isVisited[row][col - 1] = false;
            path.pop_back();
        }
    }

    if (col + 1 < m) {
        // Right
        if (!isVisited[row][col + 1] && arr[row][col + 1] != -1) {
            isVisited[row][col + 1] = true;

            Coordinate coordinate;
            coordinate.row = row;
            coordinate.col = col + 1;
            path.push_back(coordinate);

            HamiltonPaths(
                arr,
                n,
                m,
                row,
                col + 1,
                isVisited,
                path,
                walkableCount,
                numberOfPaths
            );

            isVisited[row][col + 1] = false;
            path.pop_back();
        }
    }

    if (row - 1 >= 0) {
        // Up
        if (!isVisited[row - 1][col] && arr[row - 1][col] != -1) {
            isVisited[row - 1][col] = true;

            Coordinate coordinate;
            coordinate.row = row - 1;
            coordinate.col = col;
            path.push_back(coordinate);

            HamiltonPaths(
                arr,
                n,
                m,
                row - 1,
                col,
                isVisited,
                path,
                walkableCount,
                numberOfPaths
            );

            isVisited[row - 1][col] = false;
            path.pop_back();
        }
    }

    if (row + 1 < n) {
        // Down
        if (!isVisited[row + 1][col] && arr[row + 1][col] != -1) {
            isVisited[row + 1][col] = true;

            Coordinate coordinate;
            coordinate.row = row + 1;
            coordinate.col = col;
            path.push_back(coordinate);

            HamiltonPaths(
                arr,
                n,
                m,
                row + 1,
                col,
                isVisited,
                path,
                walkableCount,
                numberOfPaths
            );

            isVisited[row + 1][col] = false;
            path.pop_back();
        }
    }
}

void solution()
{
    int n, m;
    cin >> n >> m;

    int** arr = new int*[n];
    bool** visited = new bool*[n];

    int walkableCount = 0;
    Coordinate start, end;

    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        visited[i] = new bool[m];

        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 0) {
                walkableCount++;
            } else if (arr[i][j] == 1) {
                start.row = i;
                start.col = j;
            } else if (arr[i][j] == 2) {
                end.row = i;
                end.col = j;
            }
        }
    }

    // cout << walkableCount << endl;

    int numberOfPaths = 0;
    vector<Coordinate> path;

    visited[start.row][start.col] = true; 

    HamiltonPaths(
        arr,
        n,
        m,
        start.row,
        start.col,
        visited,
        path,
        walkableCount,
        numberOfPaths
    );

    cout << numberOfPaths << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}