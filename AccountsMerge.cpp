#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    void dfs(
        unordered_map<string, set<string>>& graph, 
        string current, 
        unordered_map<string, bool>& visited,
        vector<string>& currentEmails
    ) {        
        if (visited[current]) {
            return;
        }
        
        // cout << current << " "; 
        currentEmails.push_back(current);
        visited[current] = true;
        
        set<string> neighbors = graph[current];
        for (auto neighbor: neighbors) {
            dfs(graph, neighbor, visited, currentEmails);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> graph;
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;
        
        for (auto account: accounts) {
            for (int i = 1; i < account.size(); i++) {
                visited[account[i]] = false;
                parent[account[i]] = account[0];
                
                if (graph.find(account[i]) == graph.end()) {
                    graph[account[i]] = set<string>();
                }
                
                for (int j = i + 1; j < account.size(); j++) {
                    graph[account[i]].insert(account[j]);
                    graph[account[j]].insert(account[i]);
                }
            }
        }
        
        vector<vector<string>> answer;
        for (auto current: graph) {
            // cout << current.first << " ";
            
            if (!visited[current.first]) {
                vector<string> currentEmails;
                currentEmails.push_back(parent[current.first]);
                    
                dfs(graph, current.first, visited, currentEmails);
                // cout << endl;
                sort(currentEmails.begin() + 1, currentEmails.end());
                answer.push_back(currentEmails);
            }
        }
        
        
        return answer;
    }
};

void solution()
{
    int n;
    cin >> n;

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}