
///Find sum of all divisor of a number using prime factorization
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const ll mx = 1e6+123;
bitset<mx>is_prime;
vector<ll> prime;
ll divisor,cnt;

void primeGen(ll mx)
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

ll SOD(ll n)
{

    ll total=1;
    for (auto p : prime ){
         if ( 1LL * p * p > n ) break;
           if(n % p == 0){
            cnt=1;
            while(n % p == 0 )
            {
                n /= p;
                cnt++;
            }
            total*=(powl(p,cnt)-1)/(p-1);
        }
    }

    if(n>1){
        total*= ( n + 1 );
    }

    return total;
}

int main()
{
    optimize();
        primeGen(1e5);
        ll n;
        cin>>n;
        ll x=SOD(n);
        cout<<x<<endl;

    return 0;
}



