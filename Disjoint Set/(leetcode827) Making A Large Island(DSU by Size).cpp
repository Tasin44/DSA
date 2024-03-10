
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
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
public:

    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);//total number of nodes

        // step - 1(connect all 4 dimentional valid adjacent 1 to store them a single ultimate parent)
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int x = row * n + col;
                        int y = newr * n + newc;
                        ds.unionBySize(x,y);
                    }
                }
            }
        }


        // step 2(By converting every single 0 & check
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) and (grid[newr][newc] == 1))
                    {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];///finding the total size after converting every 0
                }
                mx = max(mx, sizeTotal + 1);///finding the max size after converting every 0
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);//if all the element of the matrix is 1
        }
        return mx;
    }
};


int main() {

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.largestIsland(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}
