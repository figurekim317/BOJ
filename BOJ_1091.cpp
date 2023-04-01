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

int n,a[55],w[55],now[55],tmp[55];

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",w+i);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) now[i]=i%3;
    for(int ans=0;ans<180010;ans++)
    {
        if(!memcmp(w,now,sizeof(int)*n)) {printf("%d",ans); return 0;}
        for(int i=0;i<n;i++) tmp[i]=now[a[i]];
        memcpy(now,tmp,sizeof(tmp));
    }
    printf("-1");
    return 0;
}