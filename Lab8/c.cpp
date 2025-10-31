#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int BASE1 = 911382323, BASE2 = 972663749;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

vector<ll> pow1, pow2;

void build_pow(int n) {
    pow1.resize(n + 1);
    pow2.resize(n + 1);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow1[i] = (pow1[i-1] * BASE1) % MOD1;
        pow2[i] = (pow2[i-1] * BASE2) % MOD2;
    }
}

struct Hash {
    vector<ll> h1, h2;
    Hash(const string &s) {
        int n = s.length();
        h1.resize(n + 1);
        h2.resize(n + 1);
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i+1] = (h2[i] * BASE2 + s[i]) % MOD2;
        }
    }
    pair<ll, ll> get(int l, int r) {
        // hash of s[l..r-1]
        ll res1 = (h1[r] - h1[l] * pow1[r-l]) % MOD1;
        if (res1 < 0) res1 += MOD1;
        ll res2 = (h2[r] - h2[l] * pow2[r-l]) % MOD2;
        if (res2 < 0) res2 += MOD2;
        return {res1, res2};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    int n = S.length();
    build_pow(n);

    Hash bigHash(S);

    int m;
    cin >> m;
    vector<string> small(m);
    vector<pair<ll, ll>> smallHashes(m);
    vector<int> len(m);

    for (int i = 0; i < m; i++) {
        cin >> small[i];
        len[i] = small[i].length();
        // compute hash of small[i]
        ll h1 = 0, h2 = 0;
        for (char c : small[i]) {
            h1 = (h1 * BASE1 + c) % MOD1;
            h2 = (h2 * BASE2 + c) % MOD2;
        }
        smallHashes[i] = {h1, h2};
    }

    vector<bool> covered(n, false);

    for (int i = 0; i < m; i++) {
        int L = len[i];
        if (L > n) continue;
        auto target = smallHashes[i];
        for (int start = 0; start + L <= n; start++) {
            if (bigHash.get(start, start + L) == target) {
                for (int j = start; j < start + L; j++) {
                    covered[j] = true;
                }
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!covered[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}