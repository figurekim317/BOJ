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

int n,a[55],m,b[10010];

bool chk(int p)
{
    if(p*n<m) return 0;
    for(int i=n-1,j=m-p-1;i--&&j>=0;j-=p)
        if(b[j]>a[i]) return 0;
    return 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    cin>>m;
    for(int i=0;i<m;i++) scanf("%d",b+i);
    sort(a,a+n); sort(b,b+m);
    if(a[n-1]<b[m-1]) {printf("-1"); return 0;}
    int lf=1,rg=m;
    while(lf<rg)
    {
        int mid=lf+rg>>1;
        if(chk(mid)) rg=mid;
        else lf=mid+1;
    }
    cout<<lf;
    return 0;
}