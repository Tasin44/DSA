
#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e3+123;
int adjMat[mx][mx];

int main()
{
    optimize();

    int n;
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) cin >> adjMat[i][j];
    }


    return 0;
}
