#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void floodFill(
    vector<vector<int>>& image, 
    int currentR, 
    int currentC, 
    int oldColor,
    int newColor, 
    int m, int n
) {
    if (
        currentR < 0 || currentR >= m ||
        currentC < 0 || currentC >= n ||
        image[currentR][currentC] != oldColor ||
        image[currentR][currentC] == newColor
    ) {
        return;
    }
    
    // oldColor = image[currentR][currentC];
    image[currentR][currentC] = newColor;
    
    floodFill(image, currentR + 1, currentC, oldColor, newColor, m, n);
    floodFill(image, currentR - 1, currentC, oldColor, newColor, m, n);
    floodFill(image, currentR, currentC + 1, oldColor, newColor, m, n);
    floodFill(image, currentR, currentC - 1, oldColor, newColor, m, n);
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    floodFill(image, sr, sc, image[sr][sc], newColor, image.size(), image[0].size());
    
    return image;
}

void solution()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    floodFill(image, sr, sc, newColor);


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}