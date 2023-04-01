#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010

int n;
pii a[N];
vector<pii> b;

bool chk(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-y1*x2<0;
}

bool clockwise(pii st,pii mid,pii p)
{
    return chk((ll)mid.first-st.first,(ll)mid.second-st.second,
        (ll)p.first-mid.first,(ll)p.second-mid.second);
}

int amel()
{
    vector<pii> hull;
    for(int i=1;i<=n;i++)
    {
        while(hull.size()>=2&&!clockwise(hull[hull.size()-2],hull.back(),a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    b.insert(b.end(),hull.begin(),hull.end());
    b.pop_back();
    return hull.size()-1;
}

bool comp(pii lhs,pii rhs)
{
    return lhs.second==rhs.second?lhs.first<rhs.first:lhs.second>rhs.second;
}

int main(){
   // freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1,comp); b.clear();
        amel();
        reverse(a+1,a+n+1);
        amel();
        printf("%d\n",b.size());
        for(auto i:b) printf("%d %d\n",i.first,i.second);
    }
    return 0;
}
