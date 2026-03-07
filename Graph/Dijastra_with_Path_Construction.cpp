#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> roads,int n){

    vector<vector<pair<int,int>>> adj(n+1);

    for(auto &v : roads){
        adj[v[0]].push_back({v[1],v[2]});
        adj[v[1]].push_back({v[0],v[2]});
    }

    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1);

    for(int i=1;i<=n;i++)
        parent[i]=i;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int d = it.first;

        for(auto &nbr : adj[node]){
            int v = nbr.first;
            int wt = nbr.second;

            if(d + wt < dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
                parent[v] = node;
            }
        }
    }

    // reconstruct path
    vector<int> path;
    int node = n;

    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);
    reverse(path.begin(),path.end());

    return path;
}
