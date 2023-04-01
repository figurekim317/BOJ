#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 200010
#define MOD 10007

int n,m,a[N];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    queue<int> bfs;
    bfs.push(n); a[n]=1;
    while(!bfs.empty())
    {
        int p=bfs.front(); bfs.pop();
        if(p==m) break;
        if(p-1>=0&&!a[p-1]) a[p-1]=a[p]+1,bfs.push(p-1);
        if(p+1<=m&&!a[p+1]) a[p+1]=a[p]+1,bfs.push(p+1);
        if(p<<1<N&&!a[p<<1]) a[p<<1]=a[p]+1,bfs.push(p<<1);
    }
    printf("%d",a[m]-1);
    return 0;
}
