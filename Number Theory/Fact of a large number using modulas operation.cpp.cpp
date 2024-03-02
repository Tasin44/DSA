
#include<bits/stdc++.h>
using namespace std;
using ll=long long int
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
vector<ll>fact(1000005,1);
void factr(ll range)
{
    for(i=2;i<range;i++)
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
                  cin>>d;
                  cout<<fact[d]<<endl;
                }
                return 0;
}










