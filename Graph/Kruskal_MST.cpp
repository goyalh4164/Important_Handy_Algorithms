#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int kruskal(int n, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(),
         [](vector<int> &a, vector<int> &b) {
             return a[2] < b[2];
         });

    DSU dsu(n);
    int mstWeight = 0;

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (dsu.findParent(u) != dsu.findParent(v)) {
            dsu.unionBySize(u, v);
            mstWeight += w;
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;

    vector<vector<int>> edges = {
        {1,2,3},
        {1,3,1},
        {2,3,7},
        {2,4,5},
        {3,4,2}
    };

    cout << kruskal(n, edges);
}