#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({4,1});

    vector<int> dist = dijkstra(n, adj, 0);

    for(int i=0;i<n;i++)
        cout << dist[i] << " ";
}
