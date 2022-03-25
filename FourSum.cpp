#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<pp> TwoSum(vector<int>& arr, int l, int r, int target)
{
    vector<pp> indexes;
    while (l < r) {
        
        int sum = arr[l] + arr[r];

        if (sum == target) {
            indexes.push_back(pp(l++, r--));
           
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }

    return indexes;
    
}

string Getkey(vector<int> answer)
{
    return to_string(answer[0]) + "," +
           to_string(answer[1]) + "," +
           to_string(answer[2]) + "," +
           to_string(answer[3]);
}

void solution()
{
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    sort(arr.begin(), arr.end());
    
    vector<vector<int>> answers;
    unordered_map<string, bool> occurred;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            

            vector<pp> indexes = TwoSum(arr, j + 1, n - 1, target - arr[i] - arr[j]);

            if (indexes.size() > 0) {
                for (pp x: indexes) {
                    vector<int> answer;
                    answer.push_back(arr[i]);
                    answer.push_back(arr[j]);
                    answer.push_back(arr[x.first]);
                    answer.push_back(arr[x.second]);

                    if (occurred.find(Getkey(answer)) == occurred.end()) {
                        answers.push_back(answer);
                        occurred[Getkey(answer)] = true;
                    }
                }
            }
        

        }
    }


    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i][0] << " ";
        cout << answers[i][1] << " ";
        cout << answers[i][2] << " ";
        cout << answers[i][3] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}