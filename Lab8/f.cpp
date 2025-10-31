#include <bits/stdc++.h>
using namespace std;

struct State {
    int len, link;
    map<char, int> next;
};

struct SuffixAutomaton {
    vector<State> st;
    int last;

    SuffixAutomaton(int n = 0) {
        st.reserve(2 * n);
        st.push_back({0, -1, {}});
        last = 0;
    }

    void extend(char c) {
        int cur = st.size();
        st.push_back({st[last].len + 1, 0, {}});
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = st.size();
                st.push_back({st[p].len + 1, st[q].link, st[q].next});
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    long long countDistinctSubstrings() {
        long long ans = 0;
        for (int i = 1; i < (int)st.size(); i++)
            ans += st[i].len - st[st[i].link].len;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    SuffixAutomaton sa(s.size());
    for (char c : s) sa.extend(c);

    cout << sa.countDistinctSubstrings() << "\n";
    return 0;
}
