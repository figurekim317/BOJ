#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 1000000007

struct num
{
    int a[60];
    num()
    {
        for(int i=0;i<60;i++) a[i]=0;
    }
    num(int pos,int p)
    {
        for(int i=0;i<60;i++) a[i]=0;
        a[pos]=p;
    }
    int jari()
    {
        int ret=55;
        while(ret&&!a[ret]) ret--;
        return ret+1;
    }
    num operator+(const num &rhs)const
    {
        num ret;
        for(int i=0,b=0;i<55;i++)
        {
            ret.a[i]=(this->a[i]+rhs.a[i]+b)%36;
            b=(this->a[i]+rhs.a[i]+b>=36);
        }
        return ret;
    }
    bool operator<(const num &rhs)const
    {
        for(int i=55;i>=0;i--)
            if(this->a[i]!=rhs.a[i]) return this->a[i]<rhs.a[i];
        return 0;
    }
}a[N],ans;

int n,m,chg[N];
pair<num,int> d[N];

void numprint(num p)
{
    int v=p.jari();
    for(int i=v-1;i>=0;i--)
        printf("%c",p.a[i]<10?'0'+p.a[i]:'A'-10+p.a[i]);
    puts("");
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char s[55];
        scanf("%s",s);
        reverse(s,s+strlen(s));
        for(int j=0;s[j];j++) a[i].a[j]=s[j]<'A'?s[j]-'0':s[j]-'A'+10;
    }
    scanf("%d",&m);
    for(int i=0;i<36;i++) d[i].second=i;
    for(int i=1;i<=n;i++)
    {
        int v=a[i].jari();
        for(int j=0;j<v;j++)
            d[a[i].a[j]].first=d[a[i].a[j]].first+num(j,35-a[i].a[j]);
    }
    sort(d,d+36);
    for(int i=35;i>35-m;i--) chg[d[i].second]=1;
    for(int i=1;i<=n;i++)
    {
        int v=a[i].jari();
        for(int j=0;j<v;j++)
            if(chg[a[i].a[j]]) a[i].a[j]=35;
    }
    for(int i=1;i<=n;i++) ans=ans+a[i];
    numprint(ans);
    return 0;
}
