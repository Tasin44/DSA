
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
ll i,j,a,b,c,d,p,r,k,n,m,t,x,y,z,mn,l,ans;

/*
১টা ট্রি দেয়া থাকবে ,যেটার নোড সংখ্যা n এবং edge সংখ্যা n-1।
তারপর নোড গুলোর উপর ভিত্তি করে q সংখ্যক query দেয়া থাকবে ,
বলতে হবে 1st node থেকে সবচেয়ে shortest দূরত্বে কোন
নোড টা আছে । যদি একই দূরত্বে একাধিক নোড থাকে , তবে যে নোডটার
ভেলু কম, সেটাই হবে এন্সার .
*/

const int mx = 1e4+123;///এই ভেলু গুলো প্রব্লেমের উপর ভিত্তি করে চেঞ্জ হতে পারে
vector<ll>adj[mx];
ll level[mx];
void bfs (ll u )
{
    memset(level,-1,sizeof(level));
    level[u] = 0;
    queue<ll> q;
    q.push( u );
    while ( !q.empty() ) {
         p = q.front();
        q.pop();
        for ( auto v : adj[p] ) {
            if ( level[v] == -1 ) {
                level[v] = level[p] + 1;
                q.push( v );
            }
        }
    }
}

int main()
{
    optimize();
    ll  tt;
    cin >> tt;
    while ( tt-- ){

        for (i = 0;i < mx;i++)
        adj[i].clear();

        cin >> n;
        for (i = 1;i <=n-1;i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb ( v );
            adj[v].pb ( u );
        }
        bfs ( 1 );
        ll query;
        cin>>query;
        ll ans=1e18,value_of_node=1e18;///এই ভেলু গুলো প্রব্লেমের উপর ভিত্তি করে চেঞ্জ হতে পারে
        while(query--)
        {
          cin>>b;
          if(level[b]<=ans)
          {
           ans=level[b];
           value_of_node =min(value_of_node,b);
          }

        }
        cout << value_of_node << endl;
    }
    return 0;
}
///@author Tasin Mahmud
/*****************ALHAMDULILLAH*****************/

/*
input
1
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

output: 3
*/
