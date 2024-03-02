
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const ll mx = 1e6+123;
bitset<mx>is_prime;
vector<ll> prime;
ll divisor,cnt;

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

ll NOD (ll n)// 60
{
    divisor = 1;
    for ( auto p : prime ) { // p = 5
        if ( 1LL * p * p > n ) break;
        if ( n % p == 0 ) {
            int cnt = 1;
            while ( n % p == 0 ) { // n = 5
                n /= p; // n = 5;
                cnt++; // 2
            }
            divisor *= cnt; // 1 * 3 * 2
        }
    }
    if ( n > 1 ) divisor *= 2;///(if n is a prime number) // 1 * 3 * 2  * 2 = 12
    return divisor;
}
int main()
{
    optimize();
    primeGen(1e5);
    ll n;
    cin>>n;
    ll x= NOD(n);
    cout<<x<<endl;
    return 0;
}



