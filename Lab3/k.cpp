#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int ans = n + 1;
    int l = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];

        while (sum >= k) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }

    cout << ans << "\n";
    return 0;
}
