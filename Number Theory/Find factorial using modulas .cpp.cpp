#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
/*************** #Template FUNCTIONS# **************/
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD);}
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2);}
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b));}

ll i,j,a,b,c,d,f,p,q,r,k,l,n;
vector<ll>fact(1000005,1);
void factr(ll range)
{
    for( i=2;i<range;i++)
    {
        fact[i]=modMul(fact[i-1],i);
    }
}
int main()
{
                optimize();
                factr(200002);
                ll t;
                cin>>t;
                while(t--)
                {
                  //solution();
                  cin>>d;
                  //d=2*n;
                  cout<<fact[d]<<endl;
                }
                return 0;
}

