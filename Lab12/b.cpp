#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<ll> dijkstra(int start, const vector<vector<pair<int, int>>>& graph, int n) {
    vector<ll> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int s, t1, t2, g;
    cin >> s >> t1 >> t2 >> g;
    s--; t1--; t2--; g--;
    
    vector<ll> dist_s = dijkstra(s, graph, n);
    vector<ll> dist_t1 = dijkstra(t1, graph, n);
    vector<ll> dist_t2 = dijkstra(t2, graph, n);
    ll ans = INF;
    
    if (dist_s[t1] < INF && dist_t1[t2] < INF) {
        vector<ll> dist_t2_to_g = dijkstra(t2, graph, n);
        if (dist_t2_to_g[g] < INF) {
            ans = min(ans, dist_s[t1] + dist_t1[t2] + dist_t2_to_g[g]);
        }
    }
    
    if (dist_s[t2] < INF && dist_t2[t1] < INF) {
        vector<ll> dist_t1_to_g = dijkstra(t1, graph, n);
        if (dist_t1_to_g[g] < INF) {
            ans = min(ans, dist_s[t2] + dist_t2[t1] + dist_t1_to_g[g]);
        }
    }
    
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}