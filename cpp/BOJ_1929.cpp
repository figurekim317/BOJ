#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000

int n,m;
bool a[N];

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    if(n<3) printf("2\n"),n=3;
    for(int i=3;i<=m;i+=2)
        if(!a[i])
            for(int j=i*3;j<=m;j+=i<<1) a[j]=1;
    for(int i=n;i<=m;i++)
        if(i&1&&!a[i]) printf("%d\n",i);
    return 0;
}
