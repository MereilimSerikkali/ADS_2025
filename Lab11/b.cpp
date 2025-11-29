#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<long long>& d, vector<bool>& visited, long long& totalCost) {
    visited[u] = true;
    long long minCost = LLONG_MAX;
    int bestV = -1;
    
    for (int v = 0; v < d.size(); v++) {
        if (!visited[v]) {
            long long cost = d[u] + d[v];
            if (cost < minCost) {
                minCost = cost;
                bestV = v;
            }
        }
    }
    
   
    if (bestV != -1) {
        totalCost += minCost;
        dfs(bestV, d, visited, totalCost);
    }
}

long long pureDFS(const vector<long long>& d) {
    int n = d.size();
    if (n <= 1) return 0;
    
   
    int start = min_element(d.begin(), d.end()) - d.begin();
    
    vector<bool> visited(n, false);
    long long totalCost = 0;
    dfs(start, d, visited, totalCost);
    
    return totalCost;
}

int main() {
  

    int n;
    cin >> n;

    vector<long long> d(n);
    long long sum = 0;
    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        mn = min(mn, d[i]);
    }

    cout << sum + (n - 2) * mn << endl;
    return 0;
}