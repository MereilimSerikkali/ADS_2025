#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    vector<long long> pref(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] + (i ? pref[i-1] : 0);
    }

    int q;
    cin >> q;
    while (q--) {
        long long p;
        cin >> p;
        int cnt = int(upper_bound(a.begin(), a.end(), p) - a.begin());
        long long sum = (cnt == 0) ? 0 : pref[cnt-1];
        cout << cnt << " " << sum << "\n";
    }

    return 0;
}
