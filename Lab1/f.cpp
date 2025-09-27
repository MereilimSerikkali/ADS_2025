#include <iostream>
#include <queue>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int check = 2; check * check <= n; check++) {
        if (n % check == 0) return false;
    }
    return true;
}

int nth_prime(int num) {
    queue<int> q;
    int count = 2;
    int prime_count = 0;

    while (true) {
        if (is_prime(count)) {
            q.push(count);
            prime_count++;
            if (prime_count == num) {
                return q.back(); // last prime inserted
            }
        }
        count++;
    }
}

int main() {
    int n;
    cin >> n;
    cout << nth_prime(n);
    return 0;
}
