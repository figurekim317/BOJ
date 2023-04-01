#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 10010
#define M 1010

ll n,m,p;

ll percentage(ll p,ll q)
{
    ll ret=(ll)((double)q/p*100);
    while(p*ret<q*100) ret++;
    while(p*ret>q*100) ret--;
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    p=percentage(n,m);
    ll lf=1,rg=n*100;
    while(lf<rg)
    {
        ll mid=lf+rg>>1;
        if(percentage(n+mid,m+mid)!=p) rg=mid;
        else lf=mid+1;
    }
    cout<<((rg!=n*100)?rg:-1);
    return 0;
}