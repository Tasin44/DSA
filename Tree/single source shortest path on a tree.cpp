
//https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/description/
//Bishu and his Girlfriend
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ff first
#define ss second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOOP1(i,m,n)for(ll i=m;i<(ll)n;i++)
#define loop1(i,n)LOOP1(i,0,n)
#define max3(a,b,c)   max(a,max(b,c))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007

void dfs(ll u, vector<vector<ll>>& adj, vector<ll>& dis, vector<ll>& vis) {
    vis[u] = 1;
    for (auto child : adj[u]) {
        if (vis[child] == 0) {
            dis[child] = dis[u] + 1;
            dfs(child, adj, dis, vis);
        }
    }
}

int main() {
    optimize();
    ll n, x, y, gf, i;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> dist(n + 1, 0);
    vector<ll> vis(n + 1, 0);

    for (i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, adj, dist, vis);

    cin >> x;
    ll mn = 1e18;
    loop1(i, x) {
        cin >> y;
        if (dist[y] < mn) {
            mn = dist[y];
            gf = y;
        }
        else if (dist[y] == mn) {
            if (y < gf)
                gf = y;
        }
    }

    cout << gf << endl;

    return 0;
}
