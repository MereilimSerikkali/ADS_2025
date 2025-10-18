#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    

    sort(points.begin(), points.end());
    

    int minDiff = INT_MAX;
    for (int i = 1; i < n; i++) {
        int diff = points[i] - points[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    vector<int> result;
    for (int i = 1; i < n; i++) {
        if (points[i] - points[i - 1] == minDiff) {
            result.push_back(points[i - 1]);
            result.push_back(points[i]);
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}