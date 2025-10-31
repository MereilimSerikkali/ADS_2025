#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> a;
unordered_set<string> set;

long long powerOfNumber(long long n, long long power){
    if(power == 0) return 1;
    if(power == 1) return n;
    long long result = 1;
    for(int i = 0; i < power; i++){
        result *= 11;
        result %= (1000000007);
    }
    return result;
}

string calculateHash(string s){
    long long h = 0;
    for(int i = 0; i < s.size(); i++){
        long long temp = (((long long)(s[i]) - 47) % (1000000007)) * (powerOfNumber(11, i));
        h += temp;
        h %= (1000000007);
    }

    return to_string(h);
}

bool findHashFromInput(string s){
    // for(int i = 0; i < a.size(); i++){
    //     if(s == a[i]){
    //         return true;
    //     }
    // }
    // return false;

    // time complexity O(1)
    if (set.find(s) != set.end()) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n*2; i++){
        string s;
        cin >> s;

        a.push_back(s);
        set.insert(s);
    }

    int cnt = 0;

    for(int i = 0; i < a.size(); i++){
        if(cnt == n) break;
        string hashCode = calculateHash(a[i]);
        if(findHashFromInput(hashCode)){
            cout << "Hash of string \"" << a[i] << "\"" << " is " << hashCode << endl;
            cnt++;
        }
    }
}