

///problem link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
class Solution {
public:
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

    int removeStones(vector<vector<int>>& stones) {

        int mxrow=0,mxcol=0,n;

        for(auto u:stones)
        {
            mxrow=max(mxrow,u[0]);
            mxcol=max(mxcol,u[1]);
        }
        int totalnodes=mxrow+mxcol+1;

        vector<int> parent(totalnodes+1);
        iota(parent.begin(), parent.end(), 0);

        vector<int> size(totalnodes+1, 1);


        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + mxrow + 1;
            unionbysize(nodeRow, nodeCol,parent,size);

        }


        set<int> components;

        for (auto it : stones) {

            int nodeRow = it[0];
            int par = findpar(nodeRow, parent);
            components.insert(par);

            int nodeCol = it[1] + mxrow + 1;
            par = findpar(nodeCol, parent);
            components.insert(par);

        }

        return stones.size() - components.size();
    }
};

