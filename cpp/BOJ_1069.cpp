#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 60010
#define M 100010

int n,m,b;
double a;

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    a=hypot((double)n,(double)m);
    cin>>n>>m;
    if(n<=m) {printf("%.9f",a); return 0;}
    if(a<=(double)n) {printf("%.9f",min((double)m*2,min(a,(double)m+n-a))); return 0;}
    b=((int)a)/n;
    printf("%.9f",min(a-(double)b*n,(double)m)+(double)b*m);
    return 0;
}
