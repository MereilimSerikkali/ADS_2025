#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int q = 0; q < t; q++) {
        int x = queries[q];
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == x) {
                    cout << i << " " << j << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << -1 << "\n";
    }

    return 0;
}




    return 0;
}