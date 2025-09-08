#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a[100000];
    int ans[100000];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    stack<int> st;  

    for (int i = 0; i < N; i++) {
        int x = a[i];


        while (!st.empty() && st.top() > x) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(x);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i + 1 == N) {
            cout << '\n';  
        } else {
            cout << ' ';   
        }
    }

    return 0;
}
