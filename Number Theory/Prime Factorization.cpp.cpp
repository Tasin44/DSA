// a single number's prime factorization
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const ll mx = 1e6+123;
bitset<mx>is_prime;
vector<ll> prime;
void primeGen (ll mx)
{
    for ( ll i = 3; i <= mx; i += 2 ) is_prime[i] =true;
    for (ll i = 3; i * i <= mx; i += 2)
    {
      if (is_prime[i] == true){
      for (ll j = i * i;j<= mx; j += i + i){
                    is_prime[j] = false;
                }
            }
    }
    prime.push_back (2);
    for (ll i = 3; i <= mx; i += 2) {
        if ( is_prime[i] == true) prime.push_back ( i );
    }
}

//this factorization function more optimized then it's 2nd function
vector<ll> factorization(ll n) {
    vector<ll> ret;
    ll i = 0;
    while (n > 1 && i < prime.size()) {
        while (n % prime[i] == 0) {
            ret.push_back(prime[i]);
            n /= prime[i];
        }
        i++;
    }
    if (n > 1)
        ret.push_back(n);
    return ret;
}

/*
vector<ll> factorization(ll n )
{
    vector<ll > ret;
    for ( auto p : prime ) {
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 ) {

            while ( n % p == 0 )
            {

                ret.push_back ( p );
                n /= p;
            }
        }
    }
    if ( n > 1 ) ret.push_back(n);
    return ret;
}
*/

int main()
{
    optimize();
    primeGen(1e5);
    ll n;
    cin>>n;
    vector<ll> ans = factorization(n);
        for(auto p:ans) cout<<p<<" ";
        cout<<endl;
    return 0;
}





//multiple numbers from a vector prime factorization calculation

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using ld = long double;
#define ff first
#define ss second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(a,v)  memset(a,v,sizeof(a))
#define LOOP1(i,m,n)for(ll i=m;i<(ll)n;++i)
#define loop1(i,n)LOOP1(i,0,n)
#define max3(a,b,c)   max(a,max(b,c))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 10000000000000007

///*================ actual code starts here ============*/
const ll mx = 2e5+123;
bitset<mx>is_prime;
vector<ll> prime;
void primeGen (ll mx)
{
    for ( ll i = 3; i <= mx; i += 2 ) is_prime[i] =true;
    for (ll i = 3; i * i <= mx; i += 2)
    {
      if (is_prime[i] == true){
      for (ll j = i * i;j<= mx; j += i + i){
                    is_prime[j] = false;
                }
            }
    }
    prime.push_back (2);
    for (ll i = 3; i <= mx; i += 2) {
        if ( is_prime[i] == true) prime.push_back ( i );
    }
}

vector<ll> factorization(ll n) {
    vector<ll> ret;
    ll i = 0;
    while (n > 1 && i < prime.size()) {
        while (n % prime[i] == 0) {
            ret.push_back(prime[i]);
            n /= prime[i];
        }
        i++;
    }
    if (n > 1)
        ret.push_back(n);
    return ret;
}

int main()
{
    optimize();
    primeGen(2e5);
    ll n;
    cin>>n;
    vector<ll>v;
    ll zero=0;
    map<ll,vector<ll>>mp;
    loop1(i,n)
    {
        ll x;
        cin>>x;
        if(x==0)
        {
            zero++;
            continue;
        }
        vector<ll> ans = factorization(x);
        mp[x]=ans;
    }

    for (auto& pair : mp) {
        cout << pair.ff << " : ";
        for (ll value : pair.ss) {
            cout << value <<" "; // Print vector elements
        }
        cout << endl;
    }
    return 0;
}





