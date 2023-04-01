#include <cstdio>
#include <utility>
#include <vector>
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

int n,m;
bool now,flag;
pdd u[110],v[110],st,pre;
vector<pair<pii,pdd> > a;
double ans;

pair<bool,pdd> meet(int p,int q)
{
    pdd ret,x1=u[p],x2=u[(p+1)%n],y1=v[q],y2=v[(q+1)%m];

    if((x1.ff-x2.ff)*(y1.ss-y2.ss)==(x1.ss-x2.ss)*(y1.ff-y2.ff)) return {false,{0,0}};

    ret.ff=((-x2.ff+y2.ff)*(y1.ss-y2.ss)-(-x2.ss+y2.ss)*(y1.ff-y2.ff))/
        ((x1.ff-x2.ff)*(y1.ss-y2.ss)-(x1.ss-x2.ss)*(y1.ff-y2.ff));
    ret.ss=-((-x2.ff+y2.ff)*(x1.ss-x2.ss)-(-x2.ss+y2.ss)*(x1.ff-x2.ff))/
        ((y1.ff-y2.ff)*(x1.ss-x2.ss)-(y1.ss-y2.ss)*(x1.ff-x2.ff));

    if(ret.ff<0||ret.ff>=1||ret.ss<0||ret.ss>=1) return {false,{ret.ff,ret.ss}};

    return {true,{ret.ff*x1.ff+(-ret.ff+1)*x2.ff,ret.ff*x1.ss+(-ret.ff+1)*x2.ss}};
}

double surface(pdd p,pdd q,pdd r)
{
    return ((p.ff-q.ff)*(p.ss-r.ss)-(p.ss-q.ss)*(p.ff-r.ff))*0.5;
}

void amel(pdd p)
{
    if(flag) ans+=surface(a[0].ss,pre,p);
    pre=p; flag=1;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%lf %lf",&u[i].ff,&u[i].ss);
    for(int i=0;i<m;i++) scanf("%lf %lf",&v[i].ff,&v[i].ss);
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            auto tmp=meet(i,j);
            if(tmp.ff) a.pb({{i,j},tmp.ss}),cnt++;
        }
        if(cnt<2) continue;
        int j=a.size()-1;
        if((u[i].ff-a[j-1].ss.ff)*(a[j-1].ss.ff-a[j].ss.ff)+
            (u[i].ss-a[j-1].ss.ss)*(a[j-1].ss.ss-a[j].ss.ss)<0)
            {
                auto tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
            }
    }
    if(a.empty())
    {
        pdd inf={1010,1010},tmp;
        bool cnt=0;
        tmp=u[1]; u[1]=inf;
        for(int i=0;i<m;i++)
        {
            auto t=meet(0,i);
            if(t.ff) cnt=!cnt;
        }
        u[1]=tmp;
        if(cnt)
        {
            for(int i=2;i<n;i++) ans+=surface(u[0],u[i-1],u[i]);
            printf("%.9f",ans);
            return 0;
        }
        tmp=v[1]; v[1]=inf;
        for(int i=0;i<n;i++)
        {
            auto t=meet(i,0);
            if(t.ff) cnt=!cnt;
        }
        v[1]=tmp;
        if(cnt)
        {
            for(int i=2;i<m;i++) ans+=surface(v[0],v[i-1],v[i]);
            printf("%.9f",ans);
            return 0;
        }
        printf("0");
        return 0;
    }
    auto t=surface(u[a[0].ff.ff],a[0].ss,v[(a[0].ff.ss+1)%m]);
    if(t!=0) now=t>0;
    else
    {
        t=surface(v[a[0].ff.ss],a[0].ss,u[(a[0].ff.ff+1)%n]);
        now=t<0;
    }

    for(int i=0,ii=a.size();i<ii;i++)
    {
        if(i) amel(a[i].ss);
        for(int j=now?a[i].ff.ss:a[i].ff.ff,jj=now?a[(i+1)%ii].ff.ss:a[(i+1)%ii].ff.ff;j!=jj;)
        {
            j++; j%=(now?m:n);
            amel(now?v[j]:u[j]);
        }
        now=!now;
    }
    printf("%.9f",ans);
    return 0;
}