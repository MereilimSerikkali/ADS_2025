#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> boris, nursik;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        boris.push_back(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        nursik.push_back(x);
    }

    int moves = 0;
    const int LIMIT = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < LIMIT) {
        moves++;
        int b = boris.front();
        boris.pop_front();
        int n = nursik.front();
        nursik.pop_front();

        bool borisWins;
        if (b == 0 && n == 9) {
            borisWins = true;
        } else if (b == 9 && n == 0) {
            borisWins = false;
        } else {
            borisWins = (b > n);
        }

        if (borisWins) {
            boris.push_back(b);
            boris.push_back(n);
        } else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
    }

    if (moves >= LIMIT) {
        cout << "botva\n";
    } else if (boris.empty()) {
        cout << "Nursik " << moves << "\n";
    } else {
        cout << "Boris " << moves << "\n";
    }

    return 0;
}
