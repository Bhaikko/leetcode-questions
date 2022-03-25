#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, k = 0;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    int l = 0,
        r = 0;
    
    while (r < n) {
        if (arr[l] != arr[r]) {
            l++;
            swap(arr[l], arr[r]);
            k++;
        }
        r++;
    }

    for (int i = 0; i <= k; i++) {
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