
#include<bits/stdc++.h>
using namespace std;

int findpar(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        return findpar(parent[node], parent);
}

void unionbysize(int u, int v, vector<int>& parent, vector<int>& size) {
        int ulp_u = findpar(u, parent);
        int ulp_v = findpar(v, parent);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
}

void unionbyrank(int u,int v, vector<int>& ultimate_parent, int rank[])
{
        int ulp_u=findpar(u,ultimate_parent);
        int ulp_v=findpar(v,ultimate_parent);
        if(ulp_u==ulp_v)return ;//that means they belongs to the same component
        if (rank[ulp_u] < rank[ulp_v]) {
                ultimate_parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u])
            {
                ultimate_parent[ulp_v] = ulp_u;
            }
            else {
                ultimate_parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
}

int main() {
    int n = 7; // Number of elements in the disjoint set

    vector<int> parent(n + 1); // Array to store parent of each node
    vector<int> size(n + 1, 1); // Array to store size of each set, initialized to 1 for each node
    vector<int> rank(n + 1, 0); // Array to store rank of each set, initialized to 0 for each node

    // Initializing each node as its own parent
   // for (int i = 1; i <= n; ++i) {
   //     parent[i] = i;
   // }

    iota(parent.begin(), parent.end(), 0);

    // Union operations using union by size
    unionbysize(1, 2, parent, size);
    unionbysize(2, 3, parent, size);
    unionbysize(4, 5, parent, size);
    unionbysize(6, 7, parent, size);
    unionbysize(5, 6, parent, size);

    // Checking if nodes 3 and 7 belong to the same component
    if (findpar(3, parent) == findpar(7, parent)) {
        cout << "Same\n";
    }
    else {
        cout << "Not same\n";
    }

    // Union operation using union by size
    unionbysize(3, 7, parent, size);

    // Checking if nodes 3 and 7 belong to the same component after the union
    if (findpar(3, parent) == findpar(7, parent)) {
        cout << "Same\n";
    }
    else {
        cout << "Not same\n";
    }

    return 0;
}
