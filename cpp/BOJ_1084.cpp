#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n;
ll a[15],b[15],m,ans;

int main(){
    freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++) scanf("%lld",a+i);
        scanf("%lld",&m);
        auto t=min_element(a,a+n);
        if(m<*t)
        {
            printf("0\n\n\n");
            continue;
        }
        if(n==1||m<*min_element(a+1,a+n))
        {
            printf("1\n0\n0\n");
            continue;
        }
        if(t==a) ans=(m-*min_element(a+1,a+n))/(*t)+1;
        else ans=m/(*t);
        printf("%lld\n",ans);
        for(int i=n-1;i>=0;i--)
        {
            ll tmp=*min_element(a,a+i);
            if(tmp>=a[i])
            {
                b[i]=m/a[i];
                break;
            }
            ll lf=0,rg=m/a[i];
            while(lf<rg)
            {
                ll mid=lf+rg+1>>1;
                if(mid+((m-a[i]*mid)/tmp)==ans) lf=mid;
                else rg=mid-1;
            }
            b[i]=lf;
            ans-=lf;
            m-=lf*a[i];
        }
//        for(int i=0;i<n;i++) printf("%lld ",b[i]); printf("\n");
        for(int i=n-1,now=50;i>=0&&now>0;i--)
        {
            if(b[i]>=(ll)now)
            {
                while(now--) printf("%d",i);
                break;
            }
            for(int j=b[i];j--;) printf("%d",i);
            now-=(int)b[i];
        }
        printf("\n");
        list<int> r;
        for(int i=0,now=50;i<n&&now>0;i++)
        {
            if(b[i]>=(ll)now)
            {
                while(now--) r.push_front(i);
                break;
            }
            for(int j=b[i];j--;) r.push_front(i);
            now-=(int)b[i];
        }
        for(auto i:r) printf("%d",i);
        printf("\n");
    }
    return 0;
}