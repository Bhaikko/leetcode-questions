#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, m;
    cin >> n >> m;

    int count = n * m;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int lc = 0,
        rc = m - 1,
        lr = 0,
        ur = n - 1;

    vector<int> answer(count);
    int current = 0;
    int i = 0;
    while (current < count) {
        i = lc;
        while (i <= rc) {
            // cout << matrix[lr][i] << " ";
            answer[current++] = matrix[lr][i++];
            // i++;
            // current++;   
        }
        lr++;
        if (current >= count) break;

        i = lr;
        while (i <= ur) {
            // cout << matrix[i][rc] << " ";
            // i++;
            // current++;
            answer[current++] = matrix[i++][rc];
        }
        rc--;
        if (current >= count) break;

        i = rc;
        while (i >= lc) {
            // cout << matrix[ur][i] << " ";
            // i--;
            // current++;
            answer[current++] = matrix[ur][i--];
        }
        ur--;
        if (current >= count) break;

        i = ur;
        while (i >= lr) {
            // cout << matrix[i][lc] << " ";
            // i--;
            // current++;
            answer[current++] = matrix[i--][lc];
        }
        lc++;
        if (current >= count) break;
    }

    // cout << endl;

    for (int a: answer) {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}