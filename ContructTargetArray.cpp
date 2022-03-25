#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Element {
    int index;
    int value;
};

struct CompareValue {
    bool operator()(Element a, Element b) {
        if (a.value > b.value) {
            return true;
        } else {
            if (a.value == b.value) {
                return a.index > b.index;
            } 
        }

        return false;
    }
};

void solution()
{
    int n;
    cin >> n;

    Element elements[n];
    int solution[n];
    int currentSum = n;
    priority_queue<Element, vector<Element>, CompareValue> pending;

    for (int i = 0; i < n; i++) {
        cin >> elements[i].value;
        elements[i].index = i;
        pending.push(elements[i]);

        solution[i] = 1;
    }

    while (!pending.empty()) {
        Element current = pending.top();
        pending.pop();
        if (currentSum > solution[current.index]) {
            cout << "False" << endl;
            return;
        }

        int prevValue = solution[current.index];
        solution[current.index] = currentSum;
        currentSum += currentSum - prevValue;

        if (solution[current.index] != elements[current.index].value) {
            Element newElement;
            newElement.index = current.index;
            newElement.value = solution[9];
            pending.push(current);
        }

    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}