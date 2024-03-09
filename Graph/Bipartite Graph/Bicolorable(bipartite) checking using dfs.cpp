#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
bool dfs(ll u,ll c,vector<vector<ll>>&adj,vector<ll>&color,vector<ll>&vis)
{
    vis[u] =  1;
    color[u]=c;
    for (auto v :adj[u])
    {
        if(vis[v] == 0)
        {
            if(dfs(v,~c,adj,color,vis)==false)//or c^1
            return false;
        }
        else
        {
            if(color[u]==color[v])return false;//parent color==child color
        }
    }

    return true;
}
/*
~ is using to make
every child node's
color opposite of their
parent node.

~c means if c==0,
then it will be 1,
else if c==1,
then it will be 0.

istead of ~(telda),we can
use,^(xor)
c^1 means
if c==0
0^1=1
else if c==1
1^1=0
that's mean it will
make opposite color
to the child node.

*/
int main()
{
        optimize();
        ll t=1,i;
        cin>>t;
        for(ll tt=1;tt<=t;tt++)
        {

         ll n,m;
         cin >> n >> m;
         vector<vector<ll>>adj(n+1);
         vector<ll>vis(n+1,0);
         vector<ll>color(n+1,0);
         for ( i = 1; i <= m; i++ )
         {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back ( v );
            adj[v].push_back ( u );
         }

         bool res;
         for(i=1;i<=n;i++)
         {
          if(vis[i]==0)
          {
              res =dfs(i,0,adj,color,vis);///base color hisebe 0 dhora hocche
              if(res==false)
              {
                  break;
              }
          }
        }
        if(res)
        {
            printf("BICOLORABLE(Bipartite)\n");
        }

        else
        {
            printf("Non BICOLORABLE(non bipartite)\n");
        }

    }
    return 0;
}

/*
#It's vertices can be divided into two disjoint and independent sets U and V such that every edge
connects a into U to one int V
#The graph doesn't contain any odd-length cycles
(such that triangle)
#the graph is 2 colorable

*/
/*
test case 1:

5 4
1 2
2 3
1 3
4 5
ans - non bicolorable

test 2-
5 3
1 2
2 3
4 5

ans- bicolorable(bipartite)

test-3
3 3
0 1
1 2
2 0
ans-non bicolorable(because triangle)

*/
