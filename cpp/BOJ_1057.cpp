#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

int n,a,b;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>a>>b;
    a--; b--;
    if(a>b) swap(a,b);
    for(int i=1;;i++)
    {
        if(b-a==1&&b&1) {cout<<i; return 0;}
        n>>=1; a>>=1; b>>=1;
    }
    return 0;
}
