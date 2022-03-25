#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];

    int N = n + m;
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        answer.push_back(arr1[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        answer.push_back(arr2[i]);
    }

    int gap = ceil(N / 2.0f);

    while (gap != 0) {

        int start = 0;
        int end = start + gap;

        while (end < N) {
            if (answer[start] > answer[end]) {
                swap(answer[start], answer[end]);
            }

            start++;
            end++;
        }

        gap /= 2;
    }

    if (answer[0] > answer[1]) {
        swap(answer[0], answer[1]);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
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