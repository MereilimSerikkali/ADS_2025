#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            char a = s[j], b = s[j + 1];
            bool va = isVowel(a);
            bool vb = isVowel(b);

            if ((!va && vb) || (va == vb && a > b)) {
                swap(s[j], s[j + 1]);
            }
        }
    }

    cout << s;
}
