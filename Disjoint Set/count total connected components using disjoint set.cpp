#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, ultimate_parent, size;
public:
    DisjointSet(int n) {
        ultimate_parent.resize(n);
        size.resize(n, 1);
        iota(ultimate_parent.begin(), ultimate_parent.end(), 0);
    }

    int findUPar(int node) {
        if (node == ultimate_parent[node])
            return node;
        return ultimate_parent[node] = findUPar(ultimate_parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            ultimate_parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            ultimate_parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int countConnectedComponents(int n, vector<vector<int>>& edges) {
    DisjointSet ds(n);
    for (auto edge : edges) {
        ds.unionBySize(edge[0], edge[1]);
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
       if (ds.findUPar(i) == i)
           components++;
    }
    return components;
}

int main() {
    int n, m; // Number of nodes and edges in the graph
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int components = countConnectedComponents(n, edges);
    cout << "Number of connected components: " << components << endl;

    return 0;
}
/*
input:(0 based index)
6 4
1 2
3 2
5 0
4 0

output: 2

*/
