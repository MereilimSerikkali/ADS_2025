#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    string res;
    long long prev = 0;
    long long power = 1; // 2^0

    for (int i = 0; i < n; i++) {
        long long diff = v[i] - prev;
        long long val = diff / power;       // (s[i] - 97)
        char c = char(val + 97);            // restore char
        res.push_back(c);
        prev = v[i];
        power <<= 1; // multiply by 2
    }

    cout << res << '\n';
    return 0;
}