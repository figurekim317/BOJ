
#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long prime[80010],b[80010];
bool a[1100010],ans[1000010];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld",&n,&m);

    a[0]=a[1]=1; prime[0]=2;
    for(long long i=3,cnt=1;i*i<=m;i+=2)
        if(!a[i])
        {
            prime[cnt++]=i;
            for(long long j=i<<1;j*j<=m;j+=i) a[j]=1;
        }
    for(long long i=1001,cnt=0;i*i<=m;i+=2)
        if(!a[i]) b[cnt++]=i*i;

    for(int i=0;prime[i]&&prime[i]<1000;i++)
    {
        long long tmp=prime[i]*prime[i];
        for(long long j=tmp*(1+(n-1)/tmp);j<=m;j+=tmp)
            ans[j-n]=1;
    }

    for(int i=0;b[i];i++)
    {
        long long s=b[i]*(1+(n-1)/b[i]);
        if(s<=m) ans[s-n]=1;
    }

    int cnt=0;
    for(int i=0;i<=m-n;i++) cnt+=ans[i];
    printf("%lld",m-n+1-cnt);

    return 0;
}
