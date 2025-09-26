#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k;
vector<long long> a;
bool canDo(long long cap) {
    long long flights = 0;
    for (long long x : a) {
        flights += (x + cap - 1) / cap; 
        if (flights > k) return false;  
    }
    return flights <= k;
}

int main() {

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long lo = 1, hi = *max_element(a.begin(), a.end());
    long long ans = hi;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (canDo(mid)) {
            ans = mid;
            hi = mid - 1; 
        } else {
            lo = mid + 1; 
        }
    }

    cout << ans << "\n";
    return 0;
}
