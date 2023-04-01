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

int n,m;
int p=INT_MAX,q=INT_MAX;

int main()
{
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i,j;m--;)
    {
        cin>>i>>j;
        p=min(p,i);
        q=min(q,j);
    }
    if(q*6<p) cout<<n*q;
    else cout<<min(p*(n/6)+q*(n%6),p*(n/6+1));
    return 0;
}
