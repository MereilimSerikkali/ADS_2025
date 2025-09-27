#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n < 2) {
        cout << "NO";
        return 0;
    }

    stack<long long> st;
    for (long long i = 2; i * i <= n; i++) {
        st.push(i);
    }

    bool prime = true;
    while (!st.empty()) {
        long long x = st.top();
        st.pop();
        if (n % x == 0) {
            prime = false;
            break;
        }
    }

    cout << (prime ? "YES" : "NO");
    return 0;
}
