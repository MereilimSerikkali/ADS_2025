#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

void KMP(string text, string pattern) {
    string s = pattern + "#" + text;

    int n = s.size();
    int m = pattern.size();
    vector <int> v;
    vector<int> pi = prefix_function(s);
    for (int i = m + 1; i < n; i++) {
        if (pi[i] == m) {
            int pos = i - 2 * m;
            v.push_back(pos);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] + 1 << " ";
    }
}

int main() {
    string text, pattern;

    cin >> text;

    cin >> pattern;

    KMP(text, pattern);

    return 0;
}