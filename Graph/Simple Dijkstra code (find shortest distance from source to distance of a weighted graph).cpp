#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ff first
#define ss second
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll i,j,a,b,c,d,p,q,h,r,k,l,n,m,x,y,z,ans,mx,sum,mn,cnt;
//Simple Dijkstra code (find shortest distance from source to distance of a weighted graph
int main() {
    optimize();
    ll tt = 1;
    // cin >> tt;
    // factr(1000);
    read:
    for (ll t = 1; t <= tt; t++) {
        cin >> n;
        vector<pair<ll,ll>> pr[n];

        for (ll i = 0; i < n - 1; i++) {
            cin >> a >> b >> c;
            pr[i].push_back({i + 1, a});//i to i+1th node connected,weight a
            pr[i].push_back({c - 1, b});//i to c-1th node connected,weight b
        }

        vector<ll> dist(n, 1e18);//must be put here 1e18 ,it's max value of long long int
        dist[0] = 0;//source distance is always 0

        set<pair<ll,ll>> st;

        for (ll i = 0; i < n; i++)
            st.insert({dist[i], i});

        while (st.size()) {
            auto nod = *st.begin();
            ll vrtx = nod.ss;
            //no need of nod.ff here,which is every source node's weight

            st.erase(st.begin());

            for (auto u : pr[vrtx]) {
                ll child_vrtx = u.ff;
                ll wt = u.ss;
                if (dist[vrtx] + wt < dist[child_vrtx]) {
                    dist[child_vrtx] = dist[vrtx] + wt;
                    st.insert({dist[child_vrtx], child_vrtx});
                }
            }
        }
        cout << dist[n - 1] << endl;//source to destination node's final distance
    }

    return 0;
}

