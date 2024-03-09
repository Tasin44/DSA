
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
vector<int> adj[mx];
int depth[mx],height[mx];
bool dfs(int vertex, int par)
{
    for(auto child : adj[vertex])
    {
         if(child==par )continue;
         depth[child]=depth[vertex]+1;
         dfs(child,vertex);
         height[vertex]=max(height[vertex],height[child]+1);
    }
}

int main()
{
         optimize();
         int n;
         cin >> n;
         for(int i = 0;i <n-1;i++)//edge n-1 porjonto hobe
         {
            int u,v;
            cin >> u >> v;
            adj[u].push_back ( v );
            adj[v].push_back ( u );
         }
         dfs(1,0);
         for(int i=1;i<=n;i++)
         {
             cout<<depth[i]<<" "<<height[i]<<endl;
         }
    return 0;
}

/*
Example-
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/

