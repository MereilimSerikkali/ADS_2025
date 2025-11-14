#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    cin >> t;
    int n = t.size();

    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }

    int p = n - pi[n - 1];
    cout << p;
    return 0;
}