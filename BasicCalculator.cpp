#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isNum(char a) {
    return a >= '0' && a <= '9';
}

void solution()
{
    string s;
    getline(cin, s);

    stack<string> operatorStack;
    stack<string> operandStack;

    string expression = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        }

        expression += s[i];
    }

    s = expression;

    for (int i = 0; i < s.size(); i++) {
        if (
            s[i] == '-' &&
            s[i + 1] == '(' &&
            s[i + 2] == '-'
        ) {
            s[i] = '+';
            s[i + 2] = ' ';
        }
    }

    vector<string> postfix;
    
    for (int i = 0; i < s.size();) {
        if (s[i] == ' ') {
            i++;
            continue;
        }

        if (isNum(s[i])) {
            int currIndex = i;
            while (isNum(s[i])) {
                i++;
            }
            postfix.push_back(s.substr(currIndex, i - currIndex));
        } else {
            if (s[i] == '+' || s[i] == '-') {
                if (
                    operatorStack.empty() ||
                    operatorStack.top()[0] == '('
                ) {
                    operatorStack.push(s.substr(i, 1));
                } else {
                    postfix.push_back(operatorStack.top());
                    operatorStack.pop();
                    operatorStack.push(s.substr(i, 1));
                }
            } else if (s[i] == ')') {
                while (!operatorStack.empty() && operatorStack.top()[0] != '(') {
                    postfix.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.pop();
            } else {
                if (s[i] == '(') {
                    operatorStack.push(s.substr(i, 1));
                } 
            }
            i++;
        }

    }

    while (!operatorStack.empty()) {
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }

    for (string a: postfix) {
        cout << a << " ";
    }
    cout << endl;

    for (string s: postfix) {
        if (s[0] == '+' || s[0] == '-') {
            if (s[0] == '+') {
                int b = stoi(operandStack.top());   operandStack.pop();
                int a = stoi(operandStack.top());   operandStack.pop();
                operandStack.push(to_string(a + b));
            } else {
                int b = stoi(operandStack.top());   operandStack.pop();
                if (operandStack.empty()) {
                    operandStack.push(to_string(-b));
                } else {
                    int a = stoi(operandStack.top());   operandStack.pop();
                    operandStack.push(to_string(a - b));
                }
            }

            // cout << operandStack.top() << endl;
        } else {
            // operandStack.push(to_string(a));
            operandStack.push(s);
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