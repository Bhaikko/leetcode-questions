#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Leetcode Solution
void solution()
{
    string input;
    int k;

    cin >> input >> k;

    unordered_map<char, int> freq;

    for (int i = 0; i < input.size(); i++) {
        freq[input[i]] = 0;
    }

    for (int i = 0; i < input.size(); i++) {
        freq[input[i]]++;
    }

    int count = 0;
    for (auto i = freq.begin(); i != freq.end(); i++) {
        count += (freq[i->first] % 2);
    }

    cout << (count <= k) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

// My Solution
// struct Element {
//     char character;
//     int occurence;
// };

// void solution()
// {
//     string input;
//     int k;
//     cin >> input >> k;

//     unordered_map<string, int> freq;
//     for (int i = 0; i < input.length(); i++) {
//         freq[input.substr(i, 1)] = 0;
//     }

//     for (int i = 0; i < input.length(); i++) {
//         freq[input.substr(i, 1)]++;
//     }

//     vector<Element> elements;
//     cout << freq.size() << endl;
//     int index = 0;
//     for (auto i = freq.begin(); i != freq.end(); i++) {
        
//         elements.push_back({
//             i->first[0],
//             i->second
//         });
//     }

//     sort(elements.begin(), elements.end(), [](Element a, Element b) -> bool {
//         return a.occurence < b.occurence;
//     });

//     int i;
//     bool answer = true;

//     for (i = 0; i < elements.size(); i++) {
//         if (k == 1) {
//             bool oneOddOccuered = false;

//             while (true) {
//                 if (elements[i].occurence % 2 == 0) {
//                     // i++;
//                 } else {
//                     if (oneOddOccuered) {
//                         answer = false;
//                     } else {
//                         oneOddOccuered = true;
//                     }
//                 }

//                 i++;

//                 if (i >= elements.size()) {
//                     k--;
//                     break;
//                 }
//             }
            

//         } else {
//             k--;
//         }
//     }

//     if (k != 0) {
//         cout << "false" << endl;
//     } else {
//         if (answer) {
//             cout << "true" << endl;
//         } else {
//             cout << "false" << endl;
//         }
//     }

// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     solution();

//     return 0;
// }

// /*
// abcdefghijklmnopqrstuvwxyz
// 25


// */