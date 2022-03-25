#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    int calculateSum(vector<vector<int>>& arr, int rowStart, int colStart, int size)
    {
        int sum = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum += arr[rowStart + i][colStart + j];
            }
        }

        return sum;
    }
*/

int calculateSum(
    int** arr, 
    int rowStart, 
    int colStart, 
    int size, 
    bool bInitial,
    int& tempSum
) {
    if (bInitial) {
        tempSum = 0;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tempSum += arr[rowStart + i][colStart + j];
            }
        }
    } else {
        cout << colStart - 1 << endl;
        for (int i = 0; i < size; i++) {
            tempSum -= arr[rowStart + i][colStart - 1];
            tempSum += arr[rowStart + i][colStart + size - 1];
        }
    }

    return tempSum;
}

void solution()
{
    int n, m, threshold;
    cin >> n >> m >> threshold;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int maxSizePossible = min(n, m);
    int answer = INT_MIN;

    int startSize = 1;
    int endSize = maxSizePossible;

    while (startSize <= endSize) {

        int currentSize = (startSize + endSize) / 2;

        int maxPossibleRow = n - currentSize;
        int maxPossibleCol = m - currentSize;

        bool bSmallerSumFound = false;
        int tempSum = 0;

        for (int i = 0; i <= maxPossibleRow; i++) {
            for (int j = 0; j <= maxPossibleCol; j++) {
                int sum = calculateSum(arr, i, j, currentSize, j == 0, tempSum);

                if (sum <= threshold) {
                    bSmallerSumFound = true;
                    if (currentSize > answer) {
                        answer = currentSize;
                    }
                }
            }
        }

        if (bSmallerSumFound) {
            startSize = currentSize + 1;
        } else {
            endSize = currentSize - 1;
        }
    }

    if (answer == INT_MIN) {
        cout << 0 << endl;
    } else {
        cout << answer << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

/*
4 4 6
1 1 1 1
1 0 0 0 
1 0 0 0
1 0 0 0 

3 7 4
1 1 3 2 4 3 2
1 1 3 2 4 3 2
1 1 3 2 4 3 2

5 5 1
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2

7 2 40184
18 70
61 1
25 85
14 40
11 96
97 96
63 45
*/