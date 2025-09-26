#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long H;
vector<long long> bags;

bool canSteal(long long K) {
    long long hours = 0;
    for (long long x : bags) {
        hours += (x + K - 1) / K; 
        if (hours > H) return false;
    }
    return hours <= H;
}

int main() {
    cin >> n >> H;
    bags.resize(n);
    for (int i = 0; i < n; i++) cin >> bags[i];

    long long lo = 1, hi = *max_element(bags.begin(), bags.end());
    long long ans = hi;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (canSteal(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
