#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 200010
#define M 3010

int n,m,k;
set<pii> b;

struct segtree
{
    int a[100010<<2][2],siz;
    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
    }
    void setint(int pos,int p)
    {
        a[siz+pos/2][pos&1]=p;
    }
    void settree()
    {
        for(int j=2;j--;)
            for(int i=siz;i--;)
                a[i][j]=min(a[i*2][j],a[i*2+1][j]);
    }
    int findmin(int lf,int rg)
    {
        int ret=INT_MAX,i=lf&1;
        lf>>=1; rg>>=1;
        lf+=siz; rg+=siz;
        while(lf<rg)
        {
            if(lf&1) ret=min(ret,a[lf++][i]);
            else if(rg%2==0) ret=min(ret,a[rg--][i]);
            else lf>>=1,rg>>=1;
        }
        return min(ret,a[lf][i]);
    }
}p,q;

int main(){
   // freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n>>m>>k;
    if(n==0) {printf("0"); return 0;}
    if(n+m<k) {printf("-1"); return 0;}
    if(n&1&&k%2==0) {printf("-1"); return 0;}

    int lf=n,rg=n,ans=0;
    n+=m;
    p.init(n>>1); q.init(n>>1);
    for(int i=0,t;i<=n;i++)
    {
        p.setint(i,abs(i-k));
        t=max(0,k-(n-i));
        q.setint(i,-(i-t+k-t));
    }
    p.settree(); q.settree();
    for(;0<lf;ans++)
    {
        if(!b.insert({lf,rg}).ss) {ans=-1; break;}
        int llf=p.findmin(lf,rg),rrg=-q.findmin(lf,rg);
        lf=llf; rg=rrg;
//        printf("%d %d\n",lf,rg);
    }
    cout<<ans;
    
    /*
}//*/
    return 0;
}
