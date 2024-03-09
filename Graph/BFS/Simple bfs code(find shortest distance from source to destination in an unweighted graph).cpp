#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//find shortest distance from source to destination(1 to n) in an unweighted(same weighted) graph
int main() {
    optimize();
    ll tt = 1;
    cin >> tt;

    for (ll t = 1; t <= tt; t++) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> adj(n + 1);
        for (ll i = 1; i <= m; i++) {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<ll> dist(n + 1, -1);
        queue<ll> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            ll x = q.front();
            q.pop();
            for (auto u : adj[x]) {
                if (dist[u] == -1) {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                }
            }
        }

        cout << dist[n] << endl;
    }

    return 0;
}
