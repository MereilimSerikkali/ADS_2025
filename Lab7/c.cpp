#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            cout << A[i] << " ";
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return 0;
}