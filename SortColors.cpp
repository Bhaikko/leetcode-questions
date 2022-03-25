#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0,
        right = n - 1,
        mid = 0;

    while (mid <= right) {
        if (arr[mid] == 0) {
            swap(arr[left++], arr[mid]);
            mid++;
        } else if (arr[mid] == 1) {
            mid++;

        } else if (arr[mid] == 2) {
            swap(arr[right--], arr[mid]);
        }

    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
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