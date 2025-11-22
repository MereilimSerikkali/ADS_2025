#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;
    edges.reserve(m);

    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.emplace_back(u, v);
    }

    vector<int> color(n+1, 0), parent(n+1, -1);
    vector<int> cycle_nodes;

    function<bool(int)> dfs = [&](int u){
        color[u] = 1;
        for(int v : adj[u]){
            if(color[v] == 0){
                parent[v] = u;
                if(dfs(v)) return true;
            } else if(color[v] == 1){
                int cur = u;
                cycle_nodes.push_back(v);
                while(cur != v){
                    cycle_nodes.push_back(cur);
                    cur = parent[cur];
                }
                reverse(cycle_nodes.begin(), cycle_nodes.end());
                return true;
            }
        }
        color[u] = 2;
        return false;
    };

    for(int i=1;i<=n && cycle_nodes.empty();i++){
        if(color[i] == 0) dfs(i);
    }

    if(cycle_nodes.empty()){
        cout << "YES";
        return 0;
    }

    vector<pair<int,int>> cycle_edges;
    for(int i=0;i<(int)cycle_nodes.size();i++){
        int a = cycle_nodes[i];
        int b = cycle_nodes[(i+1) % cycle_nodes.size()];
        cycle_edges.emplace_back(a, b);
    }

    vector<int> indeg0(n+1, 0);
    for(auto &e : edges) indeg0[e.second]++;

    for(auto &rem : cycle_edges){
        vector<int> indeg = indeg0;
        indeg[rem.second]--;

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indeg[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for(int v : adj[u]){
                if(u == rem.first && v == rem.second) continue;
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }

        if(cnt == n){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
