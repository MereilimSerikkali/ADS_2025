#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> dq;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "!") {
            break;
        } 
        else if (cmd == "+") {
            int x; cin >> x;
            dq.push_front(x);
        } 
        else if (cmd == "-") {
            int x; cin >> x;
            dq.push_back(x);
        } 
        else if (cmd == "*") {
            if (dq.empty()) {
                cout << "error\n";
            } else if (dq.size() == 1) {
                int x = dq.front();
                cout << (x + x) << "\n"; 
                dq.pop_front();
            } else {
                int sum = dq.front() + dq.back();
                cout << sum << "\n";
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    return 0;
}
