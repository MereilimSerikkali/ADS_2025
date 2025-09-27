#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstGreaterEqual(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2; // divide by 2
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int firstGreater(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = (l + r) / 2; 
        if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int countRange(const vector<int>& a, int L, int R) {
    if (L > R) return 0;
    return firstGreater(a, R) - firstGreaterEqual(a, L);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = countRange(a, l1, r1);
        int c2 = countRange(a, l2, r2);

        // overlap
        int L = max(l1, l2);
        int R = min(r1, r2);
        int cOverlap = countRange(a, L, R);

        cout << (c1 + c2 - cOverlap) << "\n";
    }
    return 0;
}
