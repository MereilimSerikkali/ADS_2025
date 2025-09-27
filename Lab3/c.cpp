#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstGreaterEqual(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int firstGreater(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int countRange(const vector<long long>& a, long long L, long long R) {
    if (L > R) return 0;
    return firstGreater(a, R) - firstGreaterEqual(a, L);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = countRange(a, l1, r1);
        int c2 = countRange(a, l2, r2);

        cout << (c1 + c2) << "\n";
    }

    return 0;
}
