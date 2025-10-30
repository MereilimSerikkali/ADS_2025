#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            result.push_back(A[i]);
            i++;
        } else {
            result.push_back(B[j]);
            j++;
        }
    }
    
    while (i < n) {
        result.push_back(A[i]);
        i++;
    }
    
    while (j < m) {
        result.push_back(B[j]);
        j++;
    }
    
    for (int k = 0; k < result.size(); k++) {
        cout << result[k];
        if (k < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}