#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, U, L;
    cin >> n >> U >> L;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer[n][n];
    bool flag = true;

    for (int i = 0; i < n; i++) {
        if (U <= 0 && L <= 0) {
            flag = false;
            break;
        }

        if (arr[i] == 0) {
            answer[0][i] = 0;
            answer[1][i] = 0;
        } else if (arr[i] == 2) {
            answer[0][i] = 1;
            answer[1][i] = 1;

            U--;
            L--;
        } else {

            if (U >= L) {
                answer[0][i] = 1;
                answer[1][i] = 0;
                U--;
            } else {
                answer[0][i] = 0;
                answer[1][i] = 1;
                L--;
            }
        }
    }

    if (flag) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cout << answer[i][j] << " ";
            } 
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

// LEETCODE SOLUTION
/*  
    class Solution {
public:
    vector<vector<int>> reconstructMatrix(int U, int L, vector<int>& colsum) {
        vector<vector<int>> answer;
        bool flag = true;
        
        vector<int> row1;
        vector<int> row2;

        for (int i = 0; i < colsum.size(); i++) {
            if (U <= 0 && L <= 0) {
                if (colsum[i] != 0) {
                    flag = false;
                    break;  
                }
            }

            if (colsum[i] == 0) {
                row1.push_back(0);
                row2.push_back(0);
            } else if (colsum[i] == 2) {
                if (U <= 0 || L <= 0) {
                    flag = false;
                    break;
                }
                
                row1.push_back(1);
                row2.push_back(1);

                U--;
                L--;
            } else {

                if (U >= L) {
                    row1.push_back(1);
                    row2.push_back(0);
                    U--;
                } else {
                    row1.push_back(0);
                    row2.push_back(1);
                    L--;
                }
            }
        }
                
        if (!flag || U > 0 || L > 0) {
            vector<vector<int>> empty;
            return empty;
        }
        
        answer.push_back(row1);
        answer.push_back(row2);
        
        return answer;
    }
};
*/