

///problem link: https://www.geeksforgeeks.org/problems/number-of-islands/1
#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
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
};
class Solution {
private:
    //bool isValid(int adjr, int adjc, int n, int m) {
    //    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    //}

   bool isValid(int i,int j,int n,int m)
   {
       return i<n and i>=0 and j<m and j>=0;
   }
public:
    vector<int> numOfIslands(int n, int m,
                             vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1) //if it is already land,no need to do any operation to make it land
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            // row - 1, col
            // row , col + 1
            // row + 1, col
            // row, col - 1;
            int dr[] = {-1,0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int ind = 0; ind < 4; ind++)//now we'll traverse 4 dimensionally
            {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];

                if (isValid(adjr, adjc, n, m))
                {
                    if (vis[adjr][adjc] == 1) //if any valid adjacent cell is land,then we can connect
                    {
                      //now connect (row,col) with (adjr,ajdc)
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                /*
                Generally, a cell is represented by two parameters i.e. row and column.
                But to connect two cells as we have done with nodes,
                we need to first represent each cell with a single number.*/

        ///formula : number = (row of the current cell*total number of columns)+column of the current cell

                       if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                       {
                        /*if their ultimate par is not same,that means they're not already connected,
                        so we need to connect them & decrease the cnt because after connection,they
                        will act like a single land,but the cnt was increased before*/
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                       }

                    }
                }
            }
            //after 4 dimentional operation,store the cnt in ans
            ans.push_back(cnt);
        }
        return ans;
    }
};



int main() {

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
