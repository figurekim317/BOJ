#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 10010
#define MOD 1000000000

int n,m,ans;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1,big=0,x=0,y=0;i<=n;i++)
    {
        scanf("%d",&m);
        int tx=big+m,ty=x+m;
        ans=max(ans,tx);
        ans=max(ans,ty);
        big=max(big,x);
        big=max(big,y);
        x=tx; y=ty;
    }
    printf("%d",ans);
    return 0;
}
