
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e5+123;
vector<int>adj[mx];
int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back ( v );
        adj[v].push_back ( u ); /// remove this line for weighted graph
    }

    for ( int i = 1; i <= n; i++ ) {
        cout << "Adjacent nodes of node " << i << " : ";
        for ( auto u : adj[i] ) {
            cout << u << " ";
        }
        cout << endl;
    }


    return 0;
}
