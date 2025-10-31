#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int fail;
    vector<int> output; // list of pattern indices ending here
    Node() {
        memset(next, -1, sizeof(next));
        fail = -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; i++)
            cin >> patterns[i];

        string text;
        cin >> text;

        // Build trie
        vector<Node> trie(1); // node 0 = root
        for (int i = 0; i < n; i++) {
            int node = 0;
            for (char c : patterns[i]) {
                int idx = c - 'a';
                if (trie[node].next[idx] == -1) {
                    trie[node].next[idx] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node].next[idx];
            }
            trie[node].output.push_back(i);
        }

        // Build failure links (BFS)
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            int nxt = trie[0].next[c];
            if (nxt != -1) {
                trie[nxt].fail = 0;
                q.push(nxt);
            } else trie[0].next[c] = 0;
        }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < 26; c++) {
                int nxt = trie[v].next[c];
                if (nxt != -1) {
                    trie[nxt].fail = trie[trie[v].fail].next[c];
                    // merge outputs
                    for (int idx : trie[trie[nxt].fail].output)
                        trie[nxt].output.push_back(idx);
                    q.push(nxt);
                } else {
                    trie[v].next[c] = trie[trie[v].fail].next[c];
                }
            }
        }

        // Count occurrences
        vector<int> freq(n, 0);
        int node = 0;
        for (char c : text) {
            node = trie[node].next[c - 'a'];
            for (int idx : trie[node].output)
                freq[idx]++;
        }

        int mx = *max_element(freq.begin(), freq.end());
        cout << mx << "\n";
        for (int i = 0; i < n; i++)
            if (freq[i] == mx)
                cout << patterns[i] << "\n";
    }
    return 0;
}