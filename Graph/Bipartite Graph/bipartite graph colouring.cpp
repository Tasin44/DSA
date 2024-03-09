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
ll i,j,a,b,c,d,p,q,r,k,n,m,t,x,y,z,mn,l,ans;

/*
একটা বাই পারটাইট গ্রাফে কোন কালার টা বেশি করা হয়েছে ,
সেটা বের করার কোড
*/

const int mx = 2e4+123;
bool vis[mx];
vi adj[mx];
bool isNode[mx];
int cnt, cnt1;

///size of connected component - cnt
///total num of 1 coloured nodes - cnt1
///bool isNode[mx]  will detect is the node i is present or not

void dfs ( int u, int col )
{
    vis[u] = 1;
    if ( col == 1 ) cnt1++;
    cnt++;
    int tmp;
    if ( col == 1 ) tmp = 2;
    else tmp = 1;
    for ( auto v : adj[u] ) {
        if (  vis[v] == 0 ) {
            dfs ( v, tmp );
        }
    }
}
/*
কোনো নোডের কালার ১ হলে ,পাশের নোডের কালার ২ করে দেয়াই ট্যাম্প ভেরিয়েবলের কাজ ।
*/
int main()
{
    optimize();
    int T;
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ )
    {
        for ( int i = 0; i < mx; i++ )
        {
            adj[i].clear();
            isNode[i] = 0;
            vis[i] = 0;
        }
        /*
        গ্রাফের প্রব্লেম গুলোতে একাধিক টেস্ট কেইস থাকলে
        অপারেশন শুরুর আগেই সব ভেক্টর,এরেকে ক্লিয়ার/শুন্য করে নিবো ,
        নয়তো আগের টেস্ট কেইসের জন্য initialized ভেলু গুলো
        সমস্যা করবে ।
        */
        int m;
        cin >> m;
        for ( int i = 1; i <= m; i++ )
        {
            int u, v;
            cin >> u >> v;
            adj[u].PB ( v );
            adj[v].PB ( u );
            isNode[u] = 1;
            isNode[v] = 1;
        }
        int ans = 0;
        for ( int i = 1; i <=mx; i++ )
        {
            if ( isNode[i] == 1 && vis[i] == 0 )
            {
                cnt = 0, cnt1 = 0;
                dfs ( i, 1 );
                ans += max ( cnt1, cnt - cnt1 );
            }
        }
        /*
        কোন কালার টা সবচেয়ে বেশি ব্যবহার হয়েছে,সেটা ডিটেক্ট করবে  ans.
        */
        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}

///@author Tasin Mahmud
/*****************ALHAMDULILLAH*****************/
