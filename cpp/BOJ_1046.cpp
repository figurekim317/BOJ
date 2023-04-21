#include <cstdio>
#include <set>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second

int n,m,x,y,cnt;
bool a[51][51];
double ans=1;

bool cmp(const pii lhs,const pii rhs)
{
    return lhs.ss*rhs.ff<rhs.ss*lhs.ff;
}

struct piicmp
{
    bool operator()(const pii lhs,const pii rhs)const
    {
        return cmp(lhs,rhs);
    }
};

void swap(int &p,int &q)
{
    int tmp=p;
    p=q;
    q=tmp;
}

void cwrot()
{
    bool b[51][51];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[j][n+1-i]=a[i][j];
    swap(x,y);
    y=n+1-y;
    swap(n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]=b[i][j];
}

int main(){
    scanf("%d %d",&n,&m);
    char c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf(" %c",&c);
            if(c=='*') x=i,y=j;
            else if(c=='#') a[i][j]=1,cnt++;
        }
    for(int rot=4;rot--;cwrot())
    {
        for(int j=y+1;j<=m;j++)
            if(a[x][j]) break;
            else ans+=1;
        set<pii,piicmp> s;
        for(int i=x+1;i<=n;i++)
            for(int j=y+1;j<=m;j++)
                s.insert({2*i-2*x-1,2*j-2*y-1}),
                s.insert({2*i-2*x-1,2*j-2*y+1}),
                s.insert({2*i-2*x+1,2*j-2*y-1}),
                s.insert({2*i-2*x+1,2*j-2*y+1});
        for(int i=x;i<=n;i++)
            for(int j=y;j<=m;j++)
            {
                if(a[i][j])
                {
                    while(1)
                    {
                        auto t=s.upper_bound({2*i-2*x+1,2*j-2*y-1});
                        if(t==s.end()||!cmp(*t,{2*i-2*x-1,2*j-2*y+1})) break;
                        s.erase(t);
                    }
                }
                else if(i!=x&&j!=y)
                {
                    auto lf=s.lower_bound({2*i-2*x+1,2*j-2*y-1});
                    auto rg=lf;
                    for(;rg!=s.end()&&!cmp({2*i-2*x-1,2*j-2*y+1},*rg);++rg);
                    if(lf==rg) continue;
                    --rg;
                    if((double)(2*i-2*x+1)*rg->ss/rg->ff+2*y<=(double)2*j+1)
                    {
                        ans+=((double)rg->ss/rg->ff-(double)lf->ss/lf->ff)*(2*i-2*x+1)*(2*i-2*x+1)/8;
                    }
                    else if((double)(2*j-2*y+1)*lf->ff/lf->ss+2*x<=(double)2*i+1)
                    {
                        ans+=((double)lf->ff/lf->ss-(double)rg->ff/rg->ss)*(2*j-2*y+1)*(2*j-2*y+1)/8;
                    }
                    else
                    {
                        pii mid={2*i-2*x+1,2*j-2*y+1};
                        ans+=((double)mid.ss/mid.ff-(double)lf->ss/lf->ff)*(2*i-2*x+1)*(2*i-2*x+1)/8;
                        ans+=((double)mid.ff/mid.ss-(double)rg->ff/rg->ss)*(2*j-2*y+1)*(2*j-2*y+1)/8;
                    }

                    if((double)(2*i-2*x-1)*lf->ss/lf->ff+2*y>=(double)2*j-1)
                    {
                        ans-=((double)rg->ss/rg->ff-(double)lf->ss/lf->ff)*(2*i-2*x-1)*(2*i-2*x-1)/8;
                    }
                    else if((double)(2*j-2*y-1)*rg->ff/rg->ss+2*x>=(double)2*i-1)
                    {
                        ans-=((double)lf->ff/lf->ss-(double)rg->ff/rg->ss)*(2*j-2*y-1)*(2*j-2*y-1)/8;
                    }
                    else
                    {
                        pii mid={2*i-2*x-1,2*j-2*y-1};
                        ans-=((double)rg->ss/rg->ff-(double)mid.ss/mid.ff)*(2*i-2*x-1)*(2*i-2*x-1)/8;
                        ans-=((double)lf->ff/lf->ss-(double)mid.ff/mid.ss)*(2*j-2*y-1)*(2*j-2*y-1)/8;
                    }
                }
            }
    }
    printf("%.9f",(double)n*m-cnt-ans);
    return 0;
}
