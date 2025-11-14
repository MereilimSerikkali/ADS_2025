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
long long KMP(string text, string pattern){
    string s = pattern + '#' + text;
    int n = s.size();
    int m = pattern.size();
    long long k = 0;
    vector <int> pi = prefix_function(s);
    for(int i = m + 1; i < n; i++){
        if(pi[i] == m){
            int pos = i - 2 * m;
            k++;
        }
    }
    return k;
}
int main() {
    
    string text, pattern;

    cin >> pattern;
    long long p;
    cin >> p;
    cin >> text;
    if(KMP(text, pattern) < p){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}