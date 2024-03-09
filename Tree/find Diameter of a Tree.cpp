
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
vector<int> adj[mx];
int depth[mx];
void dfs(int vertex,int par)
{
    for(auto child : adj[vertex])
    {
        if(child==par)continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}

int main()
{
        optimize();
        int n,i,u,v;
        cin >> n;
        for(i = 0;i < n-1;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);

        int mx_depth=-1;
        int mx_depth_node;

        for(i=1;i<=n;i++)
        {
          if(mx_depth<depth[i])
           {
              mx_depth=depth[i];
              mx_depth_node=i;
           }
            depth[i]=0;
        }


        //cout<<mx_depth<<endl;
        //cout<<mx_depth_node<<endl;

        dfs(mx_depth_node,0);

        int mx_path=-1;

        for(i=1;i<=n;i++)
        {
          if(mx_path<depth[i])
           {
              mx_path=depth[i];
           }
        }

    cout<<mx_path<<endl;

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





