#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int evenIndex = 0;
    int oddIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            answer[evenIndex] = arr[i];
            evenIndex += 2;
        } else {
            answer[oddIndex] = arr[i];
            oddIndex += 2;
        }
    }

    for (int i = 0; i < n; i++) {
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