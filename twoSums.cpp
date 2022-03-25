#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Element {
    int value;
    int index;
};

void solution()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Element elements[n];
    for (int i = 0; i < n; i++) {
        elements[i].value = arr[i];
        elements[i].index = i;
    }

    sort(elements, elements + n, [](Element a, Element b) -> bool {
        return a.value < b.value;
    });

    int index1, index2;
    int leftIndex = 0, rightIndex = n - 1;

    while (true) {
        int currentSum = elements[leftIndex].value + elements[rightIndex].value;

        if (currentSum == k) {
            index1 = elements[leftIndex].index;
            index2 = elements[rightIndex].index;
            break;
        }

        if (currentSum < k) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }

    cout << index1 << " " << index2 << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();


    return 0;
}