#include <iostream>
#include <queue>
#include <string>
using namespace std;

string process(string &s) {
    string temp;
    for (char c : s) {
        if (c == '#') {
            if (!temp.empty()) temp.pop_back();
        } else {
            temp.push_back(c);
        }
    }

    // put into queue
    queue<char> q;
    for (char c : temp) q.push(c);

    // rebuild
    string result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main() {
    string m, n;
    cin >> m >> n;
    if (process(m) == process(n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
