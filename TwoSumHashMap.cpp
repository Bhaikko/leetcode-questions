#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> map;
    vector<int> answer(2);

    for (int i = 0; i < n; i++) {
        int sumToFind = k - arr[i];

        if (map.find(sumToFind) != map.end()) {
            answer[0] = map[sumToFind];
            answer[1] = i;

            break;
        } else {
            map[arr[i]] = i;
        }
    }

    cout << answer[0] << " " << answer[1] << endl;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}