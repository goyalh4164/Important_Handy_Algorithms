#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // relax edges n-1 times
    for (int i = 0; i < n-1; i++) {
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check negative cycle
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative cycle detected\n";
            break;
        }
    }

    return dist;
}

int main() {
    int n = 5;

    vector<vector<int>> edges = {
        {0,1,6},
        {0,2,7},
        {1,2,8},
        {1,3,5},
        {1,4,-4},
        {2,3,-3},
        {2,4,9},
        {3,1,-2},
        {4,3,7}
    };

    vector<int> dist = bellmanFord(n, edges, 0);

    for (int d : dist)
        cout << d << " ";
}
