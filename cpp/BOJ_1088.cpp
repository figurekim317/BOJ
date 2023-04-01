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

int n,a[55],b[55],m;
double c[55],ans=DBL_MAX;

void ansupd()
{
    ans=min(ans,*max_element(c,c+n)-*min_element(c,c+n));
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    cin>>m;
    for(int i=0;i<n;i++) b[i]=1,c[i]=(double)a[i];
    ansupd();
    while(m--)
    {
        int t=max_element(c,c+n)-c;
        b[t]++; c[t]=(double)a[t]/b[t];
        ansupd();
    }
    printf("%.14f",ans);
    return 0;
}