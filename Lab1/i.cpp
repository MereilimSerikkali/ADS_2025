#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    queue<int> qS, qK;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') qS.push(i);
        else qK.push(i);
    }

    while (!qS.empty() && !qK.empty()) {
        int iS = qS.front(); qS.pop();
        int iK = qK.front(); qK.pop();

        if (iS < iK) {
            qS.push(iS + n);
        } else {
            qK.push(iK + n);
        }
    }

    if (qS.empty()) cout << "KATSURAGI\n";
    else cout << "SAKAYANAGI\n";

    return 0;
}
