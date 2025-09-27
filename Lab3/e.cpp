#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> mins;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 >= 0 && y1 >= 0) {
            mins.push_back(max(x2, y2));
        }
    }

    if ((int)mins.size() < k) {
        cout << -1 << "\n";
        return 0;
    }

    // ищем рэндж
    long long lo = 0, hi = 0;
    for (long long v : mins) hi = max(hi, v);

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        int cnt = 0;
        for (long long v : mins) {
            if (v <= mid) cnt++;
        }
        if (cnt >= k) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}
