#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010

int n;
pii a[N];

struct vect
{
    int x,y,z;
    vect()
    {
        x=0; y=0; z=0;
    }
    vect(int p,int q,int r)
    {
        x=p; y=q; z=r;
    }
    vect vecplus(vect p)
    {
        return vect(x+p.x,y+p.y,z+p.z);
    }
    vect vecminus(vect p)
    {
        return vect(x-p.x,y-p.y,z-p.z);
    }
    vect crossp(vect p)
    {
        return vect(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    double dotp(vect p)
    {
        return (double)x*p.x+y*p.y+z*p.z;
    }
    double siz()
    {
        return sqrt(x*x+y*y+z*z);
    }
    void consmul(int c)
    {
        x*=c; y*=c; z*=c;
    }
};

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
    return hull.size()-1;
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    int ans=amel();
    reverse(a+1,a+n+1);
    ans+=amel();
    printf("%d",ans);
    return 0;
}
