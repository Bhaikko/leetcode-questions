#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int m, n;
    cin >> m >> n;

    int orangesCount = 0;
    int minutes = 0;
    queue<pp> pending;
    pp halt = pp(-1, -1);

    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                orangesCount++;
            } else if (grid[i][j] == 2) {
                pending.push(pp(i, j));
                visited[i][j] = true;
            }
        }
    }

    pending.push(halt);

    while (!pending.empty()) {
        pp current = pending.front();
        pending.pop();

        // cout << current.first << " " << current.second << endl;
        if (current == halt) {
            pending.push(current);

            if (pending.front() == halt) {
                break;
            }
            minutes++;

            continue;
        }

        // 400 200 200 200


        if (current.first - 1 >= 0 && !visited[current.first - 1][current.second]) {
            if (grid[current.first][current.second] == 2) {
                if (grid[current.first - 1][current.second] == 1) {
                    grid[current.first - 1][current.second] = 2;
                    orangesCount--;
                    visited[current.first - 1][current.second] = true;
                    pending.push(pp(current.first - 1, current.second));
                }
            }

        }

        if (current.first + 1 < m && !visited[current.first + 1][current.second]) {
            if (grid[current.first][current.second] == 2) {
                if (grid[current.first + 1][current.second] == 1) { 
                    grid[current.first + 1][current.second] = 2;
                    orangesCount--;

                    visited[current.first + 1][current.second] = true;
                    pending.push(pp(current.first + 1, current.second));
                }

            }
        }

        if (current.second - 1 >= 0 && !visited[current.first][current.second - 1]) {
            if (grid[current.first][current.second] == 2) {
                if (grid[current.first][current.second - 1] == 1) {
                    grid[current.first][current.second - 1] = 2;
                    orangesCount--;

                    visited[current.first][current.second - 1] = true;
                    pending.push(pp(current.first, current.second - 1));
                }
            }

        }

        if (current.second + 1 < n && !visited[current.first][current.second + 1]) {
            if (grid[current.first][current.second] == 2) {
                if (grid[current.first][current.second + 1] == 1) {
                    grid[current.first][current.second + 1] = 2;
                    orangesCount--;
                    
                    visited[current.first][current.second + 1] = true;
                    pending.push(pp(current.first, current.second + 1));
                }
            }

        }

        // if (orangesCount <= 0) {
        //     break;
        // }
    }

    cout << (orangesCount == 0 ? minutes : -1) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}