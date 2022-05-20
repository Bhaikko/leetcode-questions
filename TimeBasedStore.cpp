#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Time {
    string value;
    int timestamp;
};

class TimeMap {
private:
    unordered_map<string, vector<Time>> mappings; 
    
    
private:
    int search(vector<Time>& arr, int timestamp)
    {
        
        if (arr[arr.size() - 1].timestamp < timestamp) {
            return arr.size() - 1;
        }
        
        if (
            arr.size() == 0 ||
            arr[0].timestamp > timestamp
        ) {
            return -1;
        }
        
        return search(arr, 0, arr.size() - 1, timestamp);
    }
    
    int search(vector<Time>& arr, int l, int r, int timestamp)
    {        
        if (l > r) {
            return r;
        }
        
        int mid = (l + r) / 2;
        int currTimestamp = arr[mid].timestamp;
        
        if (currTimestamp == timestamp) {
            return mid;
        }
        
        if (currTimestamp < timestamp) {
            return search(arr, mid + 1, r, timestamp);
        } else {
            return search(arr, l, mid - 1, timestamp);
        }
        
    }
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mappings[key].push_back({
            value, timestamp
        });
    }
    
    string get(string key, int timestamp) {
        if (mappings.find(key) == mappings.end()) {
            return "";
        }
        
        int index = search(mappings[key], timestamp);
        
        cout << index << endl;
        
        return (index != -1 ? mappings[key][index].value : "");
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

void solution()
{
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}