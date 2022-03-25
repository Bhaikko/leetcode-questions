#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<vector<int>> answer(0);

    answer.push_back(vector<int>(1));
    answer[0][0] = 1;

    for (int i = 1; i < n; i++) {
        int newSize = answer[i - 1].size() + 1;
        answer.push_back(vector<int>(newSize, 1));

        for (int j = 1; j < answer[i].size() - 1; j++) {
            answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
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
};