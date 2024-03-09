#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
bool vis[mx];
vector<int> adj[mx];
bool isLoopExist=false;
//check whether a graph contains any cycle or not from LUv

bool dfs(int vertex,int par)
{
    vis[vertex]=1;

    for (auto child : adj[vertex])
    {
        if(vis[child] && child==par )continue;
        if(vis[child])return true;
        //isLoopExist|=dfs(child,vertex);
        isLoopExist=dfs(child,vertex);
        if(isLoopExist)return true;
    }

    return isLoopExist;
}

int main()
{
    optimize();
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back ( v );
        adj[v].push_back ( u );
    }
    bool isLoopExits= false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        if(dfs(i,0))
        {
            isLoopExits=true;break;
        }

    }
    cout<<isLoopExits<<endl;
    return 0;
}
