

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, ultimate_parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        ultimate_parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            ultimate_parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == ultimate_parent[node])
            return node;//that means this is the ultimate parent
              ///return findUPar(parent[node]); //this is the normal recursive way,will take logn time
        return ultimate_parent[node] = findUPar(ultimate_parent[node]);//this is the optimized way,constant time
    }   ///This is the path compressor way

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;//that means they belongs to the same component

        if (rank[ulp_u] < rank[ulp_v]) {
            ultimate_parent[ulp_u] = ulp_v;///smaller guy get attached to the greater guy
            ///means ulp_u er ultimate parent hoye jabe ulp_v,
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            ultimate_parent[ulp_v] = ulp_u;
            ///means ulp_v er ultimate parent hoye jabe ulp_u
        }
        else {
            ultimate_parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
         //cout<<ulp_u<<" "<<ulp_v<<endl;
        //cout<<rank[ulp_u]<<endl;
       // cout<<rank[ulp_v]<<endl;
    }
};



int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}





