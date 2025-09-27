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

int nth_super_prime(int num) {
    queue<int> q;  
    int count = 2;             
    int index = 0;              
    int super_prime_count = 0;   

    while (true) {
        if (is_prime(count)) {
            q.push(count);
            index++;
            if (is_prime(index)) {   // index itself prime
                super_prime_count++;
                if (super_prime_count == num) {
                    return q.back(); // last pushed prime
                }
            }
        }
        count++;
    }
}

int main() {
    int n;
    cin >> n;
    cout << nth_super_prime(n);
    return 0;
}
