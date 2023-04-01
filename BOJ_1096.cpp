#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,a[15][15],b[5010],c[5010],x[15],ans=INT_MIN;

void amel(int d[], vector<int> p)
{
    for(auto i:p) d[i]=1;
    if(p.size()==1) return;
    auto j=++p.begin();
    for(int i=p.size()>>1;i--;++j)
    {
        vector<int> tmp(j,p.end());
        for(auto k=j,l=tmp.begin();;++l)
        {
            --k;
            (*l)^=(*k);
            if(k==p.begin()) break;
        }
        amel(d,tmp);
    }
    --j;
    for(auto i=--p.end();i!=j;--i)
    {
        vector<int> tmp(p.begin(),i);
        for(auto k=i,l=--tmp.end();k!=p.end();++k,--l)
            (*l)^=(*k);
        amel(d,tmp);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",a[i]+j);
    vector<int> tmp;
    for(int i=0;i<n;i++) tmp.pb(1<<i);
    amel(b,tmp);
    tmp.clear();
    for(int i=0;i<m;i++) tmp.pb(1<<i);
    amel(c,tmp);
    for(int i=0;i<1<<n;i++)
        if(b[i])
        {
            memset(x,0,sizeof(x));
            for(int j=0;i>>j;j++)
                if(i>>j&1)
                    for(int k=0;k<m;k++) x[k]+=a[j][k];
            for(int j=0;j<1<<m;j++)
                if(c[j])
                {
                    int cnt=0;
                    for(int k=0;j>>k;k++)
                        if(j>>k&1) cnt+=x[k];
                    ans=max(ans,cnt);
                }
        }
    cout<<ans;
    return 0;
}