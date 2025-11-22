#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> parent(n+1, -1);
    vector<int> children(n+1, 0);
    vector<int> vis(n+1, 0);

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;

        vector<int> comp;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        comp.push_back(i);

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                    comp.push_back(v);
                }
            }
        }

        int root = *min_element(comp.begin(), comp.end());

        q.push(root);
        parent[root] = -1;
        vector<int> used(n+1, 0);
        used[root] = 1;

        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(!used[v]){
                    used[v] = 1;
                    parent[v] = u;
                    children[u]++;
                    q.push(v);
                }
            }
        }

        for(int v : comp){
            if(v == root) ans++;
            else if(children[v] > children[parent[v]]) ans++;
        }
    }

    cout << ans;
    return 0;
}
