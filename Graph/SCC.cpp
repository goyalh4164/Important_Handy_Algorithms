#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for (auto v : adj[node]) {
        if (!vis[v])
            dfs1(v, adj, vis, st);
    }

    st.push(node);
}

void dfs2(int node, vector<vector<int>> &rev, vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";

    for (auto v : rev[node]) {
        if (!vis[v])
            dfs2(v, rev, vis);
    }
}

void findSCC(int n, vector<vector<int>> &adj) {
    vector<int> vis(n, 0);
    stack<int> st;

    // Step 1
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs1(i, adj, vis, st);
    }

    // Step 2: reverse graph
    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++) {
        for (auto v : adj[i]) {
            rev[v].push_back(i);
        }
    }

    // Step 3
    fill(vis.begin(), vis.end(), 0);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            dfs2(node, rev, vis);
            cout << endl; // one SCC
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    findSCC(n, adj);
}
