#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0) return 0;
    
    vector<int> lps = computeLPS(pattern);
    int i = 0; 
    int j = 0; 
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            return i - j;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    if (s1.length() != s2.length()) {
        cout << -1 << endl;
        return 0;
    }
    
    string doubled = s1 + s1;
    
    int pos = kmpSearch(doubled, s2);
    
    if (pos == -1) {
        cout << -1 << endl;
    } else {
        int n = s1.length();
        int shift = (n - pos) % n;
        cout << shift << endl;
    }
    
    return 0;
}