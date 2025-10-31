#include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_set>
    using namespace std;

    using ll = long long;

    const ll MOD1 = 1e9+7;
    const ll MOD2 = 1e9+9;
    const ll BASE1 = 31;
    const ll BASE2 = 37;

    int main() {
        int k;
        cin >> k;
        vector<string> strings(k);
        int min_len = 1e9;
        int max_len = 0;
        for (int i=0; i<k; i++) {
            cin >> strings[i];
            if (strings[i].length() < min_len) min_len = strings[i].length();
            if (strings[i].length() > max_len) max_len = strings[i].length();
        }
        vector<ll> pow1(max_len+1), pow2(max_len+1);
        pow1[0] = 1;
        pow2[0] = 1;
        for (int i=1; i<=max_len; i++) {
            pow1[i] = (pow1[i-1] * BASE1) % MOD1;
            pow2[i] = (pow2[i-1] * BASE2) % MOD2;
        }
        vector<vector<ll>> pre1(k), pre2(k);
        for (int i=0; i<k; i++) {
            int n = strings[i].length();
            pre1[i].resize(n+1);
            pre2[i].resize(n+1);
            pre1[i][0] = 0;
            pre2[i][0] = 0;
            for (int j=0; j<n; j++) {
                pre1[i][j+1] = (pre1[i][j] * BASE1 + (strings[i][j] - 'a' + 1)) % MOD1;
                pre2[i][j+1] = (pre2[i][j] * BASE2 + (strings[i][j] - 'a' + 1)) % MOD2;
            }
        }

        int low = 1, high = min_len;
        string candidate = "";
        while (low <= high) {
            int mid = (low+high)/2;
            unordered_set<ll> common_set;
            for (int start=0; start <= strings[0].length()-mid; start++) {
                ll h1 = (pre1[0][start+mid] - pre1[0][start] * pow1[mid] % MOD1 + MOD1) % MOD1;
                ll h2 = (pre2[0][start+mid] - pre2[0][start] * pow2[mid] % MOD2 + MOD2) % MOD2;
                ll combined = h1 * (MOD2) + h2;
                common_set.insert(combined);
            }

            // Check other strings
            for (int i=1; i<k; i++) {
                unordered_set<ll> set_i;
                for (int start=0; start <= strings[i].length()-mid; start++) {
                    ll h1 = (pre1[i][start+mid] - pre1[i][start] * pow1[mid] % MOD1 + MOD1) % MOD1;
                    ll h2 = (pre2[i][start+mid] - pre2[i][start] * pow2[mid] % MOD2 + MOD2) % MOD2;
                    ll combined = h1 * (MOD2) + h2;
                    set_i.insert(combined);
                }
                // Intersect: common_set = common_set ∩ set_i
                unordered_set<ll> new_common;
                for (ll h : common_set) {
                    if (set_i.count(h)) {
                        new_common.insert(h);
                    }
                }
                common_set = new_common;
                if (common_set.empty()) break;
            }

            if (!common_set.empty()) {
                for (int start=0; start <= strings[0].length()-mid; start++) {
                    ll h1 = (pre1[0][start+mid] - pre1[0][start] * pow1[mid] % MOD1 + MOD1) % MOD1;
                    ll h2 = (pre2[0][start+mid] - pre2[0][start] * pow2[mid] % MOD2 + MOD2) % MOD2;
                    ll combined = h1 * (MOD2) + h2;
                    if (common_set.count(combined)) {
                        candidate = strings[0].substr(start, mid);
                        break;
                    }
                }
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        cout << candidate << endl;
    }