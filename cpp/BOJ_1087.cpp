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
pii a[55],v[55];

void make(double &p,double &q,double x,double y)
{
    if(y<p||q<x) {p=q=-1; return;}
    p=max(p,x); q=min(q,y);
}

bool chk(double p)
{
    double lf=0,rg=DBL_MAX;
    for(int i=n;i--;)
        for(int j=i;j--;)
        {
            double dx=a[j].ff-a[i].ff,dy=a[j].ss-a[i].ss,vx=v[j].ff-v[i].ff,vy=v[j].ss-v[i].ss;
            make(lf,rg,min((p-dx)/vx,(-p-dx)/vx),max((p-dx)/vx,(-p-dx)/vx));
            make(lf,rg,min((p-dy)/vy,(-p-dy)/vy),max((p-dy)/vy,(-p-dy)/vy));
        }
    return lf>=0;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].ff>>a[i].ss>>v[i].ff>>v[i].ss;
    double lf=1e-9,rg=2000;
    while(rg-lf>=1e-12)
    {
        double mid=(lf+rg)/2;
        if(chk(mid)) rg=mid;
        else lf=mid;
    }
    printf("%.12f",lf);
    return 0;
}