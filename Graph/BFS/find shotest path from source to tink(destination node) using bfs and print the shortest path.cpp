#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using ld = long double;
using pll = pair<ll,ll>;
using vl = vector<ll>;
using vll = vector<pll>;//vector of pair
using vvl = vector<vl>;//vector of vector
using vs = vector<string>;
#define ri register int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define in insert
#define uq unique
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(a,v)  memset(a,v,sizeof(a))
#define LOOP1(i,m,n)for(ll i=m;i<(ll)n;i++)
#define loop1(i,n)LOOP1(i,0,n)
#define LOOP2(j,m,n)for(ll j=m;j<=(ll)n;j++)
#define loop2(j,n)LOOP2(j,1,n)
#define max3(a,b,c)   max(a,max(b,c))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
constexpr long double PI = 3.141592653589793238462643383279;
/*************** #Template FUNCTIONS# **************/
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD);}
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2);}
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b));}
ll cdiv(ll a, ll b) {ll ret = a / b; if (a % b) ret++; return ret;}
string rev(string s1){reverse(s1.begin(),s1.end());return s1;}
bool palindrome(string s1){return s1==rev(s1);}
ll lcm(ll a, ll b){return ((a/__gcd(a,b))*b);}
ll CountDivisor(ll n){ll divisor=0;for(ll i=1;i*i<=n;i++){if(i*i==n)divisor++;else if(n%i==0)divisor+=2;}return divisor;}
ll power(ll base,ll expo){ll cnt=1;for(ll i=0;i<expo;i++){cnt=cnt*base;}return cnt;}
bool isPowerOfTwo (ll x){return x && (!(x&(x-1)));}
bool isPerfectSquare(ll n){ll divisor=0;for(ll i=1;i*i<=n;i++){if(i*i==n)return 1;}return 0;}
void setPrecision(ll digit){cout<<fixed<<setprecision(digit);}
int stoi(string &s){
    int ans=0;
    int base=10;///it's base in decimal , in binary , octal , hexadecimal the base will be change
    for(int i=0;i<s.size();i++){
        ans=ans*base+s[i]-'0';
    }
    return ans;
}
ll nCr(ll n,ll r)
{
  ll p = 1;
  for(ll i = 1; i <= r; ++i) p *= i;
  ll ans = 1;
  for(ll i = n-r+1; i<= n; ++i){
  	ans *= (ll) (i/__gcd(i,p));
  	p /=__gcd(i,p);
  }
  return ans;
}
vector<ll>fact(1000005,1);
void factr(ll range)
{
    for(ll i=2;i<range;i++)
    {
        fact[i]=modMul(fact[i-1],i);
    }
}
ll permute(ll n,ll r) {///nPr
    if (r < 0 || r > n) return 0;
    return modDiv(fact[n],(fact[n - r]));
}
ll combination(ll n,ll r) {///nCr
    if (r < 0 || r > n) return 0;
    return modDiv(fact[n],modMul(fact[r],(fact[n - r])));
}
///*================ actual code starts here ============*/

///uva-762 no. problem

ll i,j,a,b,c,d,p,r,k,n,m,t,x,y,z,mn,l,ans;
map<string, vector<string>> adj;///node gula string and tader adjacent gulao string,and akadikh adjacent
 ///<node  ,  adjacent>          ///thakte pare,tai vector<string>

map<string, string> par;///kono akta node er parent rakhbo ekhane
map<string, ll> lev;

///shortest path ber korar BFS, jader node gula string
void bfs ( string s )
{
    lev.clear();///first e main function theke source asbe and ager level ta ke
                ///clear korbe

    queue<string> q;
    q.push( s );
    lev[s]= 1;///source er level 1 initialize kore rakhlam
    ///map er moddhe always 0 initialize hoye thake,tai visited hole eikhane 1 korbo

    while ( !q.empty() ) {
        string u = q.front();
        q.pop();

        for ( auto v : adj[u] )
        {
            if ( lev[v] == 0 ) { ///map e 0 initialized hoye thake,tai level 0 mane ai node er level akhono
                                ///calcultion kora hoy nai

                lev[v] = lev[u] + 1;
                par[v] = u;///v node ta jekhan theke asche,seitai holo v node er parent
                           ///kono akta node er parent sob somoy aktai hobe

                q.push( v );
            }
        }
    }
}


int main()
{
    optimize();

    bool ok = 0;

    while ( cin >> n ) {
        if(n==0)break;
        if ( ok ) cout << endl;
        ok = 1;
        ///last test case tar por endl print korte parbo na
        ///tai last test case tar por ei loop ta cholbe na
        ///tai tar pore endl o print hobe na
        adj.clear();
        par.clear();

        for (i = 1; i <= n; i++ ) {
            string u, v;
            cin >> u >> v;
            adj[u].pb ( v );
            adj[v].pb ( u );
        }

        string s,t; ///s==source node , t== tink(destination/last)node

        cin>>s>>t;//This line will contain the source and destination cities

        bfs (s);

        if ( lev[t] == 0 ) { ///destination er level 0,mane source theke
                            ///destination a jawar kono route pai nai,tai no route
            cout << "No route\n";
            continue;
        }

        vector<pair<string, string>> path;
        ///destination(last node) theke path calculation kora start korbo
       ///at first destination er parent ke seta ber korbo
      ///then sei parent ke child banabo and sei parent er parent ke ber korbo

        while (!par[t].empty()) ///destination theke every node er parent ber korte korte akdom
                                ///first node tate chole asbe, first node er kono parent nai,
                                ///tai thik tokhon e parent of node t==empty hobe
        {

            path.pb({ par[t], t });
            t = par[t];
        }

        reverse( path.begin(), path.end() );
        ///jehetu destination (last node) theke destination calculation korechi,
        ///tai path ta ke reverse kore dibo

        for ( auto u : path ) cout << u.first << " " << u.second << endl;
    }
    return 0;

}
///@author Tasin Mahmud
/*****************ALHAMDULILLAH*****************/
/*

input: 1
n=4//number of edges
1 4
5 3
4 2
1 5
0//for break

output:
1 4
4 2
2 3
3 5



input:2
n=3//number of edges

1 2
3 2
1 3

0//for break

output:
no route(from source to tink)


*/








