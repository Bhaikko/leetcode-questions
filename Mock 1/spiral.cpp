#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void fill(int** arr, int n, int number, int start)
{
    
    if (start >= n) {
        return;
    }

    for (int i = start; i <= n - start - 1; i++) {
        arr[start][i] = number++;
    }

    for (int i = start + 1; i <= n - start - 1; i++) {
        arr[i][n - 1 - start] = number++;
    }

    for (int i = n - 2 - start; i >= start; i--) {
        arr[n - 1 - start][i] = number++;
    }

    for (int i = n - 2 - start; i >= start + 1; i--) {
        arr[i][start] = number++;
    }

    fill(arr, n, number, start + 1);
}

void solution()
{
    int n;
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }


    fill(arr, n, 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
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