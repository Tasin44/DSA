#include<iostream>
using namespace std;
void dfs(int u,vector<int>&vis,vector<int> adj[],vector<int> &st)
{
       vis[u]=1;
       for(auto it:adj[u])
       {
         if(vis[it]==0)
         dfs(it,vis,adj,st);
       }

st.push_back(u);
}

//vector<int> topoSort(int V, vector<int> adj[])
int main()
{
	   //int vis[V]={0};
	     int n, m,i,x;
         cin >> n >> m;
         vector<vector<int>>adj(n);
         for (i = 1; i <= m; i++ )
         {
            int u,v;
            cin>>u>>v;
            //u--->v
            adj[u].push_back(v);
         }
	   vector<int>vis(V,0);
	   vector<int>st;
	   for(i=0;i<V;i++)
	   {
	     if(vis[i]==0)
	     dfs(i,vis,adj,st);
	   }
	   /*
	   vector<int>ans;
	while(!st.empty())
	{
	  //int x=;
	  ans.push_back(st.top());
	  st.pop();
	}*/
	reverse(st.begin(),st.end());
	for(auto u:st)
        cout<<u<<" ";
    cout<<endl;

}

