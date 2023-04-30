

include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 200010
#define M 3010

int n,m,p,q;
ll a[10],ans;

#define amel(X,Y) (((X)^(Y))&1)

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>p>>n>>q>>m;
    int nn=(n-1)/5*5+5,mm=m/5*5,pp=(p-1)/5*5+5,qq=q/5*5;
    if(n==0) nn=0;
    if(p==0) pp=0;
    if(pp>qq)
    {
        if(nn>mm) amel(nn/5,pp/5) ? a[m-n]+=q-p : a[q-p]+=m-n ;
        else
        {
            amel(nn/5,pp/5) ? a[nn-n]+=q-p : a[q-p]+=nn-n ;
            amel(mm/5,pp/5) ? a[q-p]+=m-mm : a[m-mm]+=q-p ;
        }
    }
    else
    {
        if(nn>mm)
        {
            amel(nn/5,pp/5) ? a[m-n]+=pp-p : a[pp-p]+=m-n ;
            amel(nn/5,qq/5) ? a[q-qq]+=m-n : a[m-n]+=q-qq ;
        }
        else
        {
            amel(nn/5,pp/5) ? a[nn-n]+=pp-p : a[pp-p]+=nn-n ;
            amel(nn/5,qq/5) ? a[q-qq]+=nn-n : a[nn-n]+=q-qq ;
            amel(mm/5,pp/5) ? a[pp-p]+=m-mm : a[m-mm]+=pp-p ;
            amel(mm/5,qq/5) ? a[m-mm]+=q-qq : a[q-qq]+=m-mm ;
        }
    }

    if(pp < qq)
    {
        int t=(qq-pp)/5;
        int v=t>>1,w=t>>1;
        if(t&1) amel(nn/5,pp/5) ? v++ : w++;
        if(nn>mm)
        {
            a[5]+=v*(m-n);
            a[m-n]+=w*5;
        }
        else
        {
            a[5]+=v*(nn-n); a[nn-n]+=w*5;
            v=t>>1; w=t>>1;
            if(t&1) amel(mm/5,pp/5) ? w++ : v++;
            a[5]+=v*(m-mm); a[m-mm]+=w*5;
        }
    }
    if(nn < mm)
    {
        int t=(mm-nn)/5;
        int v=t>>1,w=t>>1;
        if(t&1) amel(nn/5,pp/5) ? v++ : w++;
        if(pp>qq)
        {
            a[5]+=w*(q-p);
            a[q-p]+=v*5;
        }
        else
        {
            a[5]+=w*(pp-p); a[pp-p]+=v*5;
            v=t>>1; w=t>>1;
            if(t&1) amel(nn/5,qq/5) ? w++ : v++;
            a[5]+=w*(q-qq); a[q-qq]+=v*5;
        }
    }

    if(nn<mm && pp<qq)
        a[5]+=(ll)(mm-nn)/5*(qq-pp);

    ans=a[5]+a[4]+a[3];
    a[1]=max(0ll,a[1]-a[4]);
    if(a[3]>a[2]) a[1]=max(0ll,a[1]-(a[3]-a[2])*2);
    a[2]=max(0ll,a[2]-a[3]);
    ans+=a[2]+1>>1;
    a[1]=max(0ll,a[1]-(a[2]+1)/2);
    if(a[2]&1) a[1]=max(0ll,a[1]-2);
    ans+=(a[1]+4)/5;
    cout<<ans;

    /*
}//*/
    return 0;
}
