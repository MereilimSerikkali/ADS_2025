#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> mins; 
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 >= 0 && y1 >= 0) {
            mins.push_back(max(x2, y2));
        }    
    }

    if ((int)mins.size() < k) {
        cout << -1 << "\n";
        return 0;
    }

    sort(mins.begin(), mins.end());
    cout << mins[k-1] << "\n";
    return 0;
}
