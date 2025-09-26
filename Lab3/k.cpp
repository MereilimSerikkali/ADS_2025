#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<long long>& prefix, int left, int right, long long target) {
    int ans = right + 1; 
    while (left <= right) {
        int mid = (left + right) / 2;
        if (prefix[mid] >= target) {
            ans = mid;       
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
    return ans;
}

int main() {

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n+1), prefix(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }

    int ans = n + 1;

    for (int l = 1; l <= n; l++) {
        long long target = prefix[l-1] + k;
        int r = binarySearch(prefix, l, n, target);
        if (r <= n) {
            ans = min(ans, r - (l-1));
        }
    }

    cout << ans << "\n";
    return 0;
}
