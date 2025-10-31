#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, sub;
    cin >> s1 >> s2 >> sub;

    unordered_set<int> pos2;
    for (size_t p = s2.find(sub); p != string::npos; p = s2.find(sub, p + 1))
        pos2.insert(p);

    int cnt = 0;
    for (size_t p = s1.find(sub); p != string::npos; p = s1.find(sub, p + 1))
        if (pos2.count(p)) cnt++;

    cout << cnt;
}