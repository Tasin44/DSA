#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
        optimize();
        int t=1;//cin>>t;
       for(int tt=1;tt<=t;tt++)
       {
         int n, m,i,x;
         cin >> n >> m;
         vector<vector<int>>adj(n);
         vector<int>indeg(n,0);//indegree te 0 initialize kora mandatory
         for (i = 1; i <= m; i++ )
         {
            int u,v;
            cin>>u>>v;
            //u--->v
            adj[u].push_back(v);
            indeg[v]++;
         }
         queue<int>pq;
         for(i=0;i<n;i++)
         {
            if(indeg[i]==0)//at first leaf node gulor indegree 0 hoy
            pq.push(i);
         }
         vector<int>v;
         while(!pq.empty())
         {
             x=pq.front();
             pq.pop();
             //cout<<x<<" ";
             v.push_back(x);
             for(auto it:adj[x])
             {
               indeg[it]--;
               if(indeg[it]==0)
               pq.push(it);
             }
         }
            cout<<v.size()<<endl;
         for(auto u:v)
            cout<<u<<endl;
    }
    return 0;
}


/*
test-1
4 3
0 1
1 2
2 3
output:0 1 2 3

test-2
3 3
0 1
1 2
2 0
output:null

test-3
4 4
0 1
1 2
2 3
3 1
output: 0
(ata draw korle buja jabe,ei graph e akta cycle ache,jeta 0 er por create hoiche,tai output a only 0 asche.
jodi puro element gulo asto,tar mane ei directed graph tai kono cycle nai)


*/



