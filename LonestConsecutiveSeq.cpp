#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> occured;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        occured[arr[i]] = 0;
    }

    int maxCount = 0;

    for (int el: arr) {
        if (occured.find(el - 1) == occured.end()) {
            int k = el;
            int count = 1;

            while (occured.find(k) != occured.end()) {
                if (occured[k] == 0) {
                    occured[k++] = count++;
                } else {
                    // So we dont update map value twice
                    if (el != k) {
                        occured[el] = occured[k] + count;
                    }
                    break;

                }
            }

        } 
    }

    for (auto it: occured) {
        maxCount = max(maxCount, it.second);
        // cout << it.first << " " << it.second << endl;
    }

    cout << maxCount << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}