/*
DFS subtree:
1.precompution using dfs
2.subtree sum queries
3.Even odd counts in subtree
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
//bool vis[mx];
vector<int> adj[mx];
//bool isLoopExist=false;
//check whether a graph contains any cycle or not from LUv
int subtree_sum[mx];
int even_cnt[mx];
int val[mx];
void dfs(int vertex,int par=0)
{
    subtree_sum[vertex]+=val[vertex];
    if(vertex%2==0)even_cnt[vertex]++;
    for (auto child : adj[vertex])
    {
        if( child==par )continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_cnt[vertex]+=even_cnt[child];
    }

}

int main()
{
        optimize();
        int n,q;
        cin >> n >>q;
        for(int i = 0; i < n-1; i++)
        {
            int u,v;
            cin >> u >> v;
            val[u]=u;//here vertex value same as node number
            val[v]=v;
            adj[u].push_back ( v );
            adj[v].push_back ( u );
        }
        dfs(1);
        /*
        for(int i=1;i<=n;i++)
        {
            cout<<subtree_sum[i]<<" "<<even_cnt[i]<<endl;
        }
        */

        int v;
        while(q--)
        {
           cin>>v;
           cout<<subtree_sum[v]<<" "<<even_cnt[v]<<endl;
        }

        //for(int i=1;i<=n;i++)
       // cout<<val[i]<<endl;

    return 0;
}

/*
Example:
13 1
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









/*



DFS subtree:
1.precompution using dfs
2.subtree sum queries
3.Even odd counts in subtree


#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
//bool vis[mx];
vector<int> adj[mx];
//bool isLoopExist=false;
//check whether a graph contains any cycle or not from LUv
int subtree_sum[mx];
int even_cnt[mx];
void dfs(int vertex,int par=0)
{
    subtree_sum[vertex]+=vertex;
    if(vertex%2==0)even_cnt[vertex]++;
    for (auto child : adj[vertex])
    {
        if( child==par )continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_cnt[vertex]+=even_cnt[child];
    }

}

int main()
{
        optimize();
        int n,q;
        cin >> n >>q;
        for(int i = 0; i < n-1; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back ( v );
            adj[v].push_back ( u );
        }
        dfs(1);

        for(int i=1;i<=n;i++)
        {
            cout<<subtree_sum[i]<<" "<<even_cnt[i]<<endl;
        }


        int v;
        while(q--)
        {
           cin>>v;
           cout<<subtree_sum[v]<<" "<<even_cnt[v]<<endl;
        }

    return 0;
}
*/
/*
Example:
13 1
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










