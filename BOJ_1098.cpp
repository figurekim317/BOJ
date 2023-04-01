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

int n,m,k,a[12][12],c[12],cnt;
pii b[12],ans,now;

void amel(int p)
{
    cnt=now.ff*2;
    for(int i=p;i<n;i++) cnt+=k-c[i];
    if(cnt<ans.ff*2) return;
    if(p==n)
    {
        if(ans.ff!=now.ff||ans.ss>now.ss) ans=now;
        return;
    }
    if(k-c[p]>=3)
    {
        for(int i=p+1;i<n;i++)
            if(a[p][i]&&c[i]!=k)
                {
                    c[i]++;
                    now.ff++;
                    now.ss+=a[p][i];
                    for(int j=i+1;j<n;j++)
                        if(a[p][j]&&c[j]!=k)
                        {
                            c[j]++;
                            now.ff++;
                            now.ss+=a[p][j];
                            for(int l=j+1;l<n;l++)
                                if(a[p][l]&&c[l]!=k)
                                {
                                    c[l]++;
                                    now.ff++;
                                    now.ss+=a[p][l];
                                    amel(p+1);
                                    now.ss-=a[p][l];
                                    now.ff--;
                                    c[l]--;
                                }
                            now.ss-=a[p][j];
                            now.ff--;
                            c[j]--;
                        }
                    now.ss-=a[p][i];
                    now.ff--;
                    c[i]--;
                }
    }
    if(k-c[p]>=2)
    {
        for(int i=p+1;i<n;i++)
            if(a[p][i]&&c[i]!=k)
                {
                    c[i]++;
                    now.ff++;
                    now.ss+=a[p][i];
                    for(int j=i+1;j<n;j++)
                        if(a[p][j]&&c[j]!=k)
                        {
                            c[j]++;
                            now.ff++;
                            now.ss+=a[p][j];
                            amel(p+1);
                            now.ss-=a[p][j];
                            now.ff--;
                            c[j]--;
                        }
                    now.ss-=a[p][i];
                    now.ff--;
                    c[i]--;
                }
    }
    if(k-c[p]>=1)
    {
        for(int i=p+1;i<n;i++)
            if(a[p][i]&&c[i]!=k)
                {
                    c[i]++;
                    now.ff++;
                    now.ss+=a[p][i];
                    amel(p+1);
                    now.ss-=a[p][i];
                    now.ff--;
                    c[i]--;
                }
    }
    amel(p+1);
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i].ff>>b[i].ss;
    cin>>k>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(abs(b[i].ff-b[j].ff)+abs(b[i].ss-b[j].ss)>=m)
                a[i][j]=abs(b[i].ff-b[j].ff)+abs(b[i].ss-b[j].ss);
    amel(0);
    cout<<ans.ff<<' '<<ans.ss;
    return 0;
}