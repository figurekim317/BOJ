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

int n,lf,rg,b[35],s,ns,r;
string pre,a;

void amel(int p,int st,int ed)
{
    if(st>ed) return;
//    printf("%d %d %d\n",p,st,ed);
    if(!p)
    {
        for(st--;st<ed;st++) cout<<pre[st];
        return;
    }
    for(int i=0,now=0;now<ed&&i<a.length();i++)
    {
        if(a[i]=='$')
        {
            amel(p-1,max(1,st-now),min(b[p-1],ed-now));
            if(now>ed-b[p-1]) return;
            now+=b[p-1];
        }
        else
        {
            now++;
            if(st<=now) cout<<a[i];
        }
    }
}

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>pre>>a>>n>>lf>>rg;
    for(auto i:a) if(i=='$') s++; else ns++;
    if(s==1)
    {
        for(;lf<=rg;lf++)
            if(n*(a.length()-1)+pre.length()<lf) cout<<'-';
            else if(lf<=pre.length()) cout<<pre[lf-1];
            else cout<<a[(lf-pre.length()-1)%(a.length()-1)+1];
        return 0;
    }
    b[0]=pre.length();
    for(int i=1;;i++)
    {
        b[i]=b[i-1]*s+ns;
        if(b[i]>=(rg-ns)/s) {r=i; break;}
    }
//    for(int i=0;i<=r;i++) printf("%d: %d\n",i,b[i]);
    amel(r+1,lf,n<=r?b[n]:rg);
    if(n<=r) for(;rg>max(lf-1,b[n]);rg--) cout<<'-';
    return 0;
}
