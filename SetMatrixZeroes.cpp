#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int m, n;
    cin >> m >> n;

    int matrix[m][n];
    vector<pp> zeros;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] == 0) {
                zeros.push_back(pp(i, j));
            }
        }
    }

    for (int i = 0; i < zeros.size(); i++) {
        for (int row = zeros[i].first; row < m; row++) {
            matrix[row][zeros[i].second] = 0;
        }

        for (int row = zeros[i].first; row >= 0; row--) {
            matrix[row][zeros[i].second] = 0;
        }

        for (int col = zeros[i].second; col < n; col++) {
            matrix[zeros[i].first][col] = 0;
        }

        for (int col = zeros[i].second; col >= 0; col--) {
            matrix[zeros[i].first][col] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " "; 
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