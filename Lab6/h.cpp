#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    char target;
    cin >> target;
    char result = ' ';
    for (int i = 0; i < n; i++) {
        if (arr[i] > target) {
            result = arr[i];
            break;
        }
    }
    if (result == ' ') {
        result = arr[0];
    }
    
    cout << result << endl;
    
    return 0;
}