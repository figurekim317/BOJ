#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000007

ll n,a[25];
int m,len,firlen,b[15];

void makearr(ll p)
{
    for(len=0;p;p/=10ll) a[len++]=p%10ll;
}

ll makeint()
{
    ll ret=0;
    for(int i=len-1;i>=0;i--) ret*=10ll,ret+=a[i];
    return ret;
}

ll small(int p)
{
    p=max(p,m);
    memset(a,0,sizeof(a));
    len=p;
    for(int i=0;i<m-2;i++) a[i]=(ll)m-i-1;
    a[p-1]=1ll;
    return makeint();
}

ll big(int p)
{
    memset(a,0,sizeof(a));
    len=p;
    for(int i=0;i<m;i++) a[i]=(ll)i+10-m;
    for(int i=m;i<p;i++) a[i]=9ll;
    return makeint();
}

ll amel(int p)
{
    memset(b,0,sizeof(b));
    for(int i=p;i<firlen;i++) b[a[i]]=1;
    int cnt=0;
    for(int i=0;i<10;i++) cnt+=b[i];
    if(m<cnt||cnt+p<m) return 0;
    cnt=m-cnt;
    for(int i=0,j=cnt;i<10&&j;i++) if(!b[i]) b[i]=2,j--;
    for(int i=0;i<cnt;i++)
        for(int j=9;j>=0;j--)
            if(b[j]==2) {b[j]=1; a[i]=(ll)j; break;}
    int tmp=0;
    while(!b[tmp]) tmp++;
    for(int i=cnt;i<p;i++) a[i]=(ll)tmp;
    return makeint();
}

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%lld %d",&n,&m);
    makearr(n); firlen=len; a[0]--;
    for(int i=0;i<firlen;i++)
        for(a[i]++;a[i]<10ll;a[i]++) if(amel(i)) {printf("%lld\n",amel(i)); return 0;}
    printf("%lld\n",small(firlen+1));
    return 0;
}
