#include <bits/stdc++.h>
using namespace std;

struct State {
    int link, len;
    array<int,26> next{};
    long long occ = 0;
    State() : link(-1), len(0) { next.fill(-1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int q;
    cin >> q;

    // 1. Build suffix automaton
    vector<State> st;
    st.reserve(2 * s.size());
    st.push_back(State());
    int last = 0;

    for (char ch : s) {
        int c = ch - 'a';
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        st[cur].occ = 1;

        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) st[cur].link = 0;
        else {
            int qv = st[p].next[c];
            if (st[p].len + 1 == st[qv].len) st[cur].link = qv;
            else {
                int clone = st.size();
                st.push_back(st[qv]);
                st[clone].len = st[p].len + 1;
                st[clone].occ = 0;
                while (p != -1 && st[p].next[c] == qv) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[qv].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    // 2. Count occurrences (propagate)
    vector<int> order(st.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b){ return st[a].len > st[b].len; });
    for (int v : order)
        if (st[v].link != -1)
            st[st[v].link].occ += st[v].occ;

    // 3. Process queries
    while (q--) {
        int l, r;
        cin >> l >> r;
        int v = 0;
        bool ok = true;
        for (int i = l - 1; i < r; ++i) {
            int c = s[i] - 'a';
            if (st[v].next[c] == -1) { ok = false; break; }
            v = st[v].next[c];
        }
        cout << (ok ? st[v].occ : 0) << "\n";
    }
}