#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 200010
#define M 100010

int n,ans=INT_MAX,m;
pii a[45];
vector<int> x;
map<pii,int> b;

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1,j;i<=n;i++)
    {
        cin>>a[i].ff>>a[i].ss>>j;
        b[a[i]]=j;
        m+=j;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) x.pb(a[i].ff);
    unique(x.begin(),x.end());
    for(int i=x.size()-1,xrg=n;i>=0;i--)
    {
        vector<int> y;
        for(int j=i,xlf=xrg;j>=0;j--)
        {
            while(xlf&&a[xlf].ff==x[j]) y.pb(a[xlf--].ss);
            sort(y.begin(),y.end());
            unique(y.begin(),y.end());
//                printf("%d %d / %d\n",x[j],x[i],p);
            for(int k=y.size()-1;k>=0;k--)
            {
                multiset<int,greater<int> > w;
                for(int l=k,p=m;l>=0;l--)
                {
                    for(int u=xlf+1;u<=xrg;u++) if(a[u].ss==y[l]) p-=b[a[u]],w.insert(b[a[u]]);
                    int now=x[i]-x[j]+y[k]-y[l]<<1,s=p,cnt=0;
                    for(auto u:w)
                    {
                        if(s>=now)
                        {
                            ans=min(ans,n-(int)w.size()+cnt);
                            break;
                        }
                        s+=u; cnt++;
                    }
                }
//                for(int l=xlf+1;l<=xrg;l++) if(a[l].ss==y[k]) q+=b[a[l]];
            }
        }
        while(xrg&&a[xrg].ff==x[i]) xrg--;
    }
    cout<<ans;
    return 0;
}
