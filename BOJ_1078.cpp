#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m;
ll a[15]={1};

int amel(int p)
{
    if(!p) return 0;
    return 10-p;
}

ll check(int p,int q,ll r)
{
    if(p>=q) return r?-1:0;
    ll ret=a[q-1]-a[p-1];
    int k=amel((abs(r)/a[p-1])%10);
    if(p!=1)
    {
        ll tmp=check(p+1,q-1,r+ret*k);
        if(~tmp) return tmp+a[p-1]*k;
    }
    ll tmp=check(p+1,q-1,r-ret*k);
    if(~tmp) return tmp+((p==1&&!k)?(a[q-1]+1):(a[q-1]*k));
    return -1;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=n;i;i/=10) m++;
    for(int i=1;i<15;i++) a[i]=a[i-1]*10;
    for(int i=m;i<=m<<1;i++)
    {
        ll tmp = check(1,i,n);
        if(~tmp) {cout<<tmp; return 0;}
    }
    printf("-1");
    return 0;
}