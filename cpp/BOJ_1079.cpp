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

int n,m,a[20][20],b[20],c[20],ans;

void amel(int p)
{
    if(c[m]) {ans=max(ans,p); return;}
    for(int i=0;i<n;i++)
        if(i!=m&&!c[i])
        {
            c[i]=1;
            for(int j=0;j<n;j++) b[j]+=a[i][j];
            int die=-1;
            for(int j=0;j<n;j++) if(!c[j]&&(!~die||b[die]<b[j])) die=j;
            c[die]=1;
            amel(p+1);
            c[i]=c[die]=0;
            for(int j=0;j<n;j++) b[j]-=a[i][j];
        }
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",b+i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",a[i]+j);
    cin>>m;
    if(n&1) c[max_element(b,b+n)-b]=1;
    amel(0);
    cout<<ans;
    return 0;
}