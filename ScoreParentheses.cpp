#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Precedence(char c) {
    if (c == '*') {
        return 2;
    } else if (c == '+') {
        return 1;
    } else {
        return -1;
    }
}

string GetPostfixExpression(string infix)
{
    stack<char> st;

    st.push('N');

    int len = infix.length();
    string postfix;

    for (int i = 0; i < len; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix += infix[i];
            postfix += " ";
        } else if (infix[i] == '(') {
            st.push('(');
        } else if (infix[i] == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();

                postfix += c;
                postfix += " ";
            }

            if (st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        } else {
            while (st.top() != 'N' && Precedence(infix[i]) <= Precedence(st.top())) {
                char c = st.top();
                st.pop();
                postfix += c;
                postfix += " ";
            }

            st.push(infix[i]);
        }
    }

    while (st.top() != 'N') {
        char c = st.top();
        st.pop();

        postfix += c;
    }

    return postfix;
}

int CalculatePostfixExpression(string postfix) 
{
    stack<string> st;

    int ans = 0;

    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ') {
            continue;
        }

        if (isdigit(postfix[i])) {
            st.push(postfix.substr(i, 1));
        } else {
            int val1 = stoi(st.top());
            st.pop();

            int val2 = stoi(st.top());
            st.pop();

            switch (postfix[i]) {
                case '+': st.push(to_string(val2 + val1)); break;
                case '*': st.push(to_string(val2 * val1)); break;
                default: break;
            }
        }
    }

    return stoi(st.top());
}

void solution()
{
    string input;
    cin >> input;

    string prefixString = "";

    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i] == '(') {
            if (input[i + 1] == ')') {
                prefixString += "1+";
                i++;
            } else {
                prefixString += "2*(";
            }
        } else {
            prefixString += "0)+";
        }
    }    

    cout << prefixString << endl;

    prefixString += "0";
    string infixString = prefixString;

    for (int i = 0; i <= prefixString.size(); i++) {
        if (prefixString[i] == '(') {
            infixString += ")";
        }    
    }


    cout << infixString << endl;

    cout << GetPostfixExpression(infixString) << endl;

    // cout << CalculatePostfixExpression(GetPostfixExpression(infixString)) << endl;

    cout << CalculatePostfixExpression(GetPostfixExpression(infixString)) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

}