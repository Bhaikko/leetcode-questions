#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// For finding number of elements <= k in every row
int countMin(vector<int>& arr, int k)
{
    int l = 0,
        r = arr.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] <= k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int matrixMedian(vector<vector<int>>& matrix, int halfSize, int l, int r)
{
    while (l <= r) {
        int count = 0,
            mid = (l + r) / 2;
        for (vector<int> a: matrix) {
            count += countMin(a, mid);
        }

        if (count > halfSize) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return l;

}

void solution()
{
    int n, m;
    cin >> n >> m;

    int maxEl = INT_MIN,
        minEl = INT_MAX;
    vector<vector<int>> matrix(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];

            maxEl = max(maxEl, matrix[i][j]);
            minEl = min(minEl, matrix[i][j]);
        }
    }

    int halfSize = n * m / 2;
    cout << matrixMedian(matrix, halfSize, minEl, maxEl) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}