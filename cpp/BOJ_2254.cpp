#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
#define N 1010

int n,ans;
pll prison,a[N];
vector<pll> b;

bool chk(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-y1*x2<0;
}

bool clockwise(pll st,pll mid,pll p)
{
    return chk(mid.first-st.first,mid.second-st.second,p.first-mid.first,p.second-mid.second);
}

void amel()
{
    vector<pll> hull;
    for(int i=1;i<=n;i++)
    {
        while(hull.size()>=2&&!clockwise(hull[hull.size()-2],hull.back(),a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    b.insert(b.end(),hull.begin(),hull.end());
    b.pop_back();
}

bool inside()
{
    if(b.size()<3) return 0;
    bool flag=clockwise(b[0],prison,b[1]);
    for(int i=1;i<b.size()-1;i++)
        if(flag!=clockwise(b[i],prison,b[i+1])) return 0;
    return 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %lld %lld",&n,&prison.first,&prison.second);
    for(int i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].first,&a[i].second);
    while(1)
    {
        b.clear();
        sort(a+1,a+n+1);
        amel();
        reverse(a+1,a+n+1);
        amel();
        b.push_back(b[0]);
        if(!inside()) break;
        ans++;
        sort(b.begin(),b.end());
        vector<pll> tmp;
        for(int i=1;i<=n;i++)
            if(!binary_search(b.begin(),b.end(),a[i])) tmp.push_back(a[i]);
        n=0;
        for(pll i:tmp) a[++n]=i;
    }
    printf("%d",ans);
    return 0;
}
