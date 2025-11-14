#include <iostream>
#include <vector>
using namespace std;
vector <int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
bool KMP(string text, string pattern) {
    string s = pattern + "#" + text;
    int n = s.size();
    int m = pattern.size();

    vector<int> pi = prefix_function(s);

    for (int i = m + 1; i < n; i++) {if (pi[i] == m) {
            int pos = i - 2 * m;
            return true;
        }
    }
    return false;
}
int main() {
    string a, b;
    cin >> a >> b;
    string q = a;
    int k = 1;
    while(q.size() < b.size()){
        q = q + a;
        k++;
    }
    for (int i = 0; i < 3; i++) {
        if (KMP(q, b)) {
            cout << k << endl;
            return 0;
        }
        q = q + a;
        k++;
    }
    
    cout << -1 << endl;
    return 0;
}