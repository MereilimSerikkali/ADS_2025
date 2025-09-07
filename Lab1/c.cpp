// first  

#include <iostream>
using namespace std;

string process(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
            if (i > 0) { 
                s.erase(i - 1, 2);  
                i -= 2;             
            } else {
                s.erase(i, 1);      
                i -= 1;             
            }
        }
    }
    return s;
}

int main() {
    string m, n;
    cin >> m >> n;

    m = process(m);
    n = process(n);

    if (m == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

// second
string process(string &s){
    string result;
    for (char c:s){
        if (c == '#'){
            if (result.size() != 0){
                result.pop_back();
            }

        }
        else{
                result.push_back(c);
            }
    }
    return result;
}
int main(){
    string m, n;
    cin >> m >> n;
    if(result(m) == result(n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
