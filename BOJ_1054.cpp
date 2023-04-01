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

int n,f[10010],x[1050][15],y[1050][15],z[1050][15],w[1050][15],ee[15];
string a[15];
ll ans,pre[1050][1750],suf[1050][1750],ppre[1050][1750],ssuf[1050][1750];
bool chk[1050][1050],len[1050][15];
map<string,int> e;
set<string> b;
list<int> d[15];

//bool chk(string p,string q)
//{
//    int j=min(p.length(),q.length()),k=q.length();
//    for(int i=0;i<j;i++)
//        if(p[i]!=q[k-i-1]) return 0;
//    return 1;
//}

bool ispel(string p)
{
    for(int i=0,j=p.length();i<j>>1;i++)
        if(p[i]!=p[j-i-1]) return 0;
    return 1;
}

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n;
    b.insert("");
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=1,k=a[i].length();j<=k;j++)
            for(int t=0;t<=k-j;t++)
                b.insert(a[i].substr(t,j));
    }

    int cc=0;
    for(auto i:b) e[i]=cc++;
    for(int i=0;i<n;i++) ee[i]=e[a[i]];

    for(int i=1,cnt;i<1<<n;i++)
    {
        cnt=0;
        for(int j=0;i>>j;j++)
            cnt+=1&(i>>j);
        f[i]=d[cnt].size();
        d[cnt].pb(i);
    }

    for(auto i:e)
        for(auto j:e)
        {
            int k=min(i.ff.length(),j.ff.length()),l=j.ff.length();
            bool flag=1;
            for(int u=0;u<k;u++)
                if(i.ff[u]!=j.ff[l-u-1]) {flag=0; break;}
            chk[i.ss][j.ss]=flag;
        }

    for(auto i:e)
        for(int j=0;j<n;j++) len[i.ss][j]=i.ff.length()>a[j].length();
    for(auto i:e)
        for(int j=0,p=i.ff.length();j<n;j++)
            if(len[i.ss][j])
                x[i.ss][j]=e[i.ff.substr(a[j].length(),p-a[j].length())],z[i.ss][j]=e[i.ff.substr(0,p-a[j].length())];
    for(auto i:e)
        for(int j=0,p=i.ff.length();j<n;j++)
            if(!len[i.ss][j])
                y[i.ss][j]=e[a[j].substr(0,a[j].length()-p)],w[i.ss][j]=e[a[j].substr(p,a[j].length()-p)];

    for(auto i:e) pre[i.ss][0]=suf[i.ss][0]=ispel(i.ff);
    for(int i=1;i<=n;i++)
    {
        for(auto j:d[i])
            for(int k=0;k<cc;k++)
                for(int l=0;j>>l;l++)
                    if(1&(j>>l))
                    {
                        if(chk[k][ee[l]])
                            ppre[k][f[j]]+=len[k][l]?pre[x[k][l]][f[j^(1<<l)]]:
                                                suf[y[k][l]][f[j^(1<<l)]];
                        if(chk[ee[l]][k])
                            ssuf[k][f[j]]+=len[k][l]?suf[z[k][l]][f[j^(1<<l)]]:
                                                pre[w[k][l]][f[j^(1<<l)]];
//                        if(x>y)
//                        {
//                            if(chk[k.ss][a[l]]) preret+=pre[e[k.ff.substr(y,x-y)]][f[j^(1<<l)]];
//                            if(chk(a[l],k.ff)) sufret+=suf[e[k.ff.substr(0,x-y)]][f[j^(1<<l)]];
//                        }
//                        else
//                        {
//                            if(chk(k.ff,a[l])) preret+=suf[e[a[l].substr(0,y-x)]][f[j^(1<<l)]];
//                            if(chk(a[l],k.ff)) sufret+=pre[e[a[l].substr(x,y-x)]][f[j^(1<<l)]];
//                        }
                    }
        for(int j=d[i].size();j--;) ans+=ppre[0][j];
        memcpy(pre,ppre,sizeof(pre));
        memcpy(suf,ssuf,sizeof(suf));
        memset(ppre,0,sizeof(ppre));
        memset(ssuf,0,sizeof(ssuf));
    }
    cout<<ans;
    return 0;
}
