#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bit
{
    ll a[1<<22],siz;

    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
    }

    void add(ll pos,ll p)
    {
        while(pos<=siz)
        {
            a[pos]+=p;
            pos+= pos&-pos;
        }
    }

    ll sum(ll pos)
    {
        ll ret=0;
        while(pos)
        {
            ret+=a[pos];
            pos^= pos&-pos;
        }
        return ret;
    }
};

int n,m,k;
bit bb;
ll a[1<<22];

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    bb.init(n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i),bb.add(i,a[i]);
    for(ll i=0,x,y,z;i<m+k;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        x==1?bb.add(y,z-a[y]),a[y]=z:printf("%lld\n",bb.sum(z)-bb.sum(y-1));
    }
    return 0;
}
