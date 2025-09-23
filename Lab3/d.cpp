#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> freq(vals.size(), 0);
    for (long long x : a) {
        int idx = int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
        freq[idx]++;
    }
    vector<int> pref(vals.size(), 0);
    pref[0] = freq[0];
    for (int i = 1; i < (int)vals.size(); i++) {
        pref[i] = pref[i-1] + freq[i];
    }

    auto getCount = [&](long long L, long long R) -> int {
        if (L > R) return 0;
        int l = int(lower_bound(vals.begin(), vals.end(), L) - vals.begin());
        int r = int(upper_bound(vals.begin(), vals.end(), R) - vals.begin()) - 1;
        if (l >= (int)vals.size() || vals[l] > R) return 0;
        return pref[r] - (l > 0 ? pref[l-1] : 0);
    };

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = getCount(l1, r1);
        int c2 = getCount(l2, r2);
        int overlap = getCount(max(l1, l2), min(r1, r2));

        cout << (c1 + c2 - overlap) << "\n";
    }

    return 0;
}
