#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;

        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return false;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        components--;
        return true;
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

    DSU alice(n), bob(n);
    int removed = 0;

    // type 3 edges (shared)
    for(auto &e : edges){
        if(e[0] == 3){
            bool a = alice.unite(e[1], e[2]);
            bool b = bob.unite(e[1], e[2]);

            if(!a && !b) removed++;
        }
    }

    // type 1 edges (Alice)
    for(auto &e : edges){
        if(e[0] == 1){
            if(!alice.unite(e[1], e[2]))
                removed++;
        }
    }

    // type 2 edges (Bob)
    for(auto &e : edges){
        if(e[0] == 2){
            if(!bob.unite(e[1], e[2]))
                removed++;
        }
    }

    if(alice.components > 1 || bob.components > 1)
        return -1;

    return removed;
}
