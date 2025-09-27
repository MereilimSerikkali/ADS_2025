#include <iostream>
#include <vector>
using namespace std;

int binarySearchRow(const vector<int>& row, int x) {
    int l = 0, r = (int)row.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (row[mid] == x) return mid;
        else if (row[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
            int j = binarySearchRow(arr[i], x);
            if (j != -1) {
                cout << i << " " << j << "\n";
                found = true;
            }
        }
        if (!found) cout << -1 << "\n";
    }

    return 0;
}

