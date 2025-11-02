#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> a;
unordered_set<string> setList;

string calculateHash(const string &s) {
    const long long MOD = 1000000007;
    const long long BASE = 11;

    long long h = 0;
    long long power = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        long long temp = ((long long)(s[i]) - 47) * power;
        temp %= MOD;
        h = (h + temp) % MOD;
        power = (power * BASE) % MOD;
    }

    if (h < 0) h += MOD;
    return to_string(h);
}

bool findHashFromInput(const string &s) {
    return setList.find(s) != setList.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n * 2; i++) {
        string s;
        cin >> s;
        a.push_back(s);
        setList.insert(s);
    }

    int cnt = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        if (cnt == n) break;
        string hashCode = calculateHash(a[i]);
        if (findHashFromInput(hashCode)) {
            cout << "Hash of string \"" << a[i] << "\" is " << hashCode << endl;
            cnt++;
        }
    }

    return 0;
}
