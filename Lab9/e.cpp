#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPrefixSuffix(const string &s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n - 1];
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        int n = s.length();
        int p = longestPrefixSuffix(s);
        long long ans = n + (k - 1) * (n - p);
        cout << ans << "\n";
    }
    
    return 0;
}