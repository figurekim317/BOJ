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

ll n,apre,asuf,bpre,bsuf;
string a,b;

int main(){
    freopen("input.txt","r",stdin);
    cin>>a>>b>>n;
    while(apre<a.length()&&a[apre]=='0') apre++;
    while(asuf<a.length()&&a[a.length()-asuf-1]=='0') asuf++;
    while(bpre<b.length()&&b[bpre]=='0') bpre++;
    while(bsuf<b.length()&&b[b.length()-bsuf-1]=='0') bsuf++;
    if(apre==a.length())
    {
        if(bpre==b.length())
        {
            printf("0");
        }
        else
        {
            if(apre*1000000+bpre>=n) printf("0");
            else if(apre*1000000+bpre+bsuf>=n) printf("%lld",apre*1000000+b.length()-bsuf);
            else printf("-1");
        }
    }
    else
    {
        if(bpre==b.length())
        {
            for(int i=0,now=0;i<a.length();i++)
            {
                if(a[i]=='1')
                {
                    if(now>=n) {printf("%d",i-now); return 0;}
                    now=0;
                }
                else now++;
            }
            if(apre+asuf>=n) printf("%d",a.length()-asuf);
            else
            {
                int t=(n-apre-asuf-1)/b.length()+1;
                ll ans=(ll)a.length()*1000000*t+(ll)b.length()*t*(t-1)/2-asuf;
                if(ans+n>10000000000000000ll) printf("-1");
                else printf("%lld",ans);
            }
        }
        else
        {
            for(int i=0,now=0;i<a.length();i++)
            {
                if(a[i]=='1')
                {
                    if(now>=n) {printf("%d",i-now); return 0;}
                    now=0;
                }
                else now++;
            }
            if(apre+asuf>=n) printf("%d",a.length()-asuf);
            else if(asuf+bpre>=n) printf("%d",a.length()*1000000-asuf);
            else
            {
                for(int i=0,now=0;i<b.length();i++)
                {
                    if(b[i]=='1')
                    {
                        if(now>=n) {printf("%d",a.length()*1000000+i-now); return 0;}
                        now=0;
                    }
                    else now++;
                }
                if(bsuf+apre>=n) printf("%d",a.length()*1000000+b.length()-bsuf);
                else if(bsuf+bpre>=n) printf("%d",a.length()*2000000+b.length()*2-bsuf);
                else printf("-1");
            }
        }
    }


    return 0;
}
