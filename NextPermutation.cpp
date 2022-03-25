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

    int index1 = -1, index2;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index1 = i;
            break;
        }
    }

    if (index1 == -1) {
        sort(arr, arr + n);
    } else {
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] > arr[index1]) {
                index2 = i;
                break;
            }
        }

        swap(arr[index1], arr[index2]);

        reverse(arr + index1 + 1, arr + n);
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