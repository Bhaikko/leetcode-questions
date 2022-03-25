#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int rowMax = 0,
        colMax = 0;

    vector<vector<int>> answer(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(m);
        answer[i] = row;

    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            rowMax = 0; colMax = 0;
            // Finding max in Row
            for (int i = 0; i < m; i++) {
                rowMax = max(rowMax, arr[row][i]);
            }

            // Finding max in Col
            for (int i = 0; i < n; i++) {
                colMax = max(colMax, arr[i][col]);
            }

            int maxHeight = min(rowMax, colMax);
            answer[row][col] = maxHeight;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answer[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}