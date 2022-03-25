#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> split(string s, string delimiter)
{
    vector<string> toreturn;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        toreturn.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    toreturn.push_back(s);
    return toreturn;
}

int solution()
{
    string v1, v2;
    cin >> v1 >> v2;

    vector<string> v1split = split(v1, ".");    
    vector<string> v2split = split(v2, ".");    

    int i;
    for (i = 0; i < min(v1split.size(), v2split.size()); i++) {
        int a = stoi(v1split[i]);
        int b = stoi(v2split[i]);

        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        }
    }

    if (i < v1split.size()) {
        for (i; i < v1split.size(); i++) {
            if (stoi(v1split[i]) != 0) {
                return 1;
            }
        }
    }

    if (i < v2split.size()) {
        for (i; i < v2split.size(); i++) {
            if (stoi(v2split[i]) != 0) {
                return -1;
            }
        }
    }

    return 0;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution() << endl; 

    return 0;
}