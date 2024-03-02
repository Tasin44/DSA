

///Find 1 to n prime numbers using sieve(find prime in a range)
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int mx = 1e6+123;
bitset<mx>is_prime;///bitset normal bool theke 32 gun faster,memory o kom use kore onk,
                    ///bitset use korle time complexity O(n/32) hoye jay
/*
Bitwise Sieve shekha ki important?
bitset diye implement korlei hoy.
Bitset diye same memory n/64.
normal sieve er code, just array declare na kore bitset
*/
vector<int> prime;

void primeGen (int mx)
{
    for ( int i = 3; i <= mx; i += 2 ) is_prime[i] =true;

    for (int i = 3; i * i <= mx; i += 2)
    {
      if (is_prime[i] == true)
      {
      for (int j = i * i;j<= mx; j += i + i){
                    is_prime[j] = false;    ///ekhane is_prime er majkane j hobe,i dibo na vulew is_prime[j]
                }
      }
    }
    prime.push_back (2);
    for (int i = 3; i <= mx; i += 2) {
        if ( is_prime[i] == true) prime.push_back ( i );
    }
}


int main()
{
    optimize();
    int n;
    cin>>n;
    primeGen (n);///n er jaygay mx dile 1 to mx all prime number print hobe
    for(auto u:prime)cout<<u<<endl;

}










/*
///we can do it in main function as well
#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
#define endl '\n'
#define w(t)  ll t;cin>>t;while(t--)
ll i,t,p,q,cnt,z,j,n,diff,prime1,prime2;
const long long int N=1e6+100;
bitset<N> marked;
int32_t main()
{
                ios_base::sync_with_stdio(false);
                cin.tie(0);
                cout.tie(0);
                for (i = 2; i * i <= N; i += 1){
                if (marked[i] == false) {///i is prime
                  for (j = i * i;j<= N; j +=i){
                        marked[j] = true; //j is non prime
                  }
                }
              }
            while(cin>>n)
            {
                if(marked[n]==false) //that means n is prime hole
                {

                }
            }

}
*/

