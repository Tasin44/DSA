#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll i,j,a,b,c,p,q,r,k,n,m,x,y,ans,sum,mn,h,l;

const int mx=900000;
bitset<mx>is_prime;
vector<ll>prime;

void primegen()
{
    //ll mx = 900000;
    for(i=3;i<mx;i+=2)is_prime[i]=true;
    for(i=3;i*i<mx;i+=2)
    {
      if(is_prime[i]==true)
      {
        for(j=i*i;j<mx;j+=i+i)
        {
           is_prime[j]=false;
        }
      }
    }
    prime.push_back(2);
    for(i=3;i<=mx;i+=2)
    {
        if(is_prime[i]==true)
        prime.push_back(i);
    }
}

int main()
{
        optimize();
        primegen();
        ll tt=1;
        cin>>tt;
        while(tt--)
        cin>>n,cout<<prime[n-1]<<endl;

return 0;
}

