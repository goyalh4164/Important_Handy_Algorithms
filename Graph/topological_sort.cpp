#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);

    // calculate indegree
    for (int i = 0; i < n; i++) {
        for (auto v : adj[i]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    // push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (auto v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    return topo;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> ans = topoSort(n, adj);

    for (int x : ans)
        cout << x << " ";
}
