#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    queue<pair<int, int>> q;
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    
    if (count == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int minutes = 0;
    int crushedMushrooms = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        int size = q.size();
        bool expanded = false;
        
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    crushedMushrooms++;
                    expanded = true;
                }
            }
        }
        
        if (expanded) {
            minutes++;
        }
    }
    if (crushedMushrooms == count) {
        cout << minutes << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}