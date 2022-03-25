#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int rot(int** arr, int n, int currentMinute, int currentRowIndex, int currentColIndex)
{
    if (currentRowIndex >= n || currentColIndex >= n) {
        return 0;
    }

    if (arr[currentRowIndex][currentRowIndex] == 2) {
        // Rotten
        if (currentRowIndex - 1 >= 0) {
            if (arr[currentRowIndex - 1][currentColIndex] == 2) {
                arr[currentRowIndex - 1][currentColIndex] = 2;
                rot(arr, n, currentMinute, currentRowIndex - 1, currentColIndex);
            }
        }

        if (currentRowIndex + 1 < n) {
            if (arr[currentRowIndex + 1][currentColIndex] == 2) {
                arr[currentRowIndex + 1][currentColIndex] = 2;
                rot(arr, n, currentMinute, currentRowIndex + 1, currentColIndex);
            }
        }

        if (currentColIndex - 1 >= 0) {
            if (arr[currentRowIndex][currentColIndex - 1] == 2) {
                arr[currentRowIndex][currentColIndex - 1] = 2;
                rot(arr, n, currentMinute, currentRowIndex, currentColIndex - 1);
            }
        }

        if (currentColIndex + 1 < n) {
            if (arr[currentRowIndex][currentColIndex + 1] == 2) {
                arr[currentRowIndex][currentColIndex + 1] = 2;
                rot(arr, n, currentMinute, currentRowIndex, currentColIndex + 1);
            }
        }
    }


    return currentMinute + 1;
}

void solution()
{
    int n;
    cin >> n;
    int** grid = new int*[n];
    for (int i = 0; i < n; i++) {
        grid[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << rot(grid, n, 0, 0, 0) << endl;



}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}