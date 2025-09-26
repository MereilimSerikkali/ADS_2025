#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> len(n), prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i];
        prefix[i] = len[i] + (i > 0 ? prefix[i - 1] : 0);
    }

    for (int j = 0; j < m; j++) {
        long long line;
        cin >> line;
        int lo = 0, hi = n - 1, ans = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (prefix[mid] >= line) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << (ans + 1) << "\n"; 
    }

    return 0;
}
