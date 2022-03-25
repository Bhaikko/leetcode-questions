#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string s;
    cin >> s;

    stack<char> occured;

    for (int i = 0; i < s.size(); i++) {
        if (
            s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '['
        ) {
            occured.push(s[i]);
            continue;
        }

        if (occured.size() == 0) {
            cout << "false" << endl;
            return;
        }

        if (s[i] == ')') {
            if (occured.top() == '(') {
                occured.pop();
            } else {
                cout << "false" << endl;
                return;

            }
        }

        if (s[i] == '}') {
            if (occured.top() == '{') {
                occured.pop();
            } else {
                cout << "false" << endl;
                return;       
            }
        }

        if (s[i] == ']') {
            if (occured.top() == '[') {
                occured.pop();
            } else {
                cout << "false" << endl;
                return;       
                
            }
        }
    }

    if (occured.size() == 0) {
        cout << "true" << endl; 
    } else {
        cout << "false" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}