#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<string> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    stack<string> operandStack;
    for (string el: tokens) {
        if (
            el == "+" ||
            el == "-" ||
            el == "*" ||
            el == "/" 
        ) {
            int b = stoi(operandStack.top());
            operandStack.pop();

            int a = stoi(operandStack.top());
            operandStack.pop();

            if (el == "+") {
                operandStack.push(to_string(a + b));
            } else if (el == "-") {
                operandStack.push(to_string(a - b));
            } else if (el == "*") {
                operandStack.push(to_string(a * b));
            } else if (el == "/") {
                operandStack.push(to_string(a / b));
            }
        } else {
            operandStack.push(el);
        }
    }

    cout << operandStack.top() << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}