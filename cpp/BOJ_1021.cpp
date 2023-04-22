#include

 <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[60],ans;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int cnt=n,s,fr=0;m;m--,cnt--)
    {
        scanf("%d",&s); s--;
        int tmp=0;
        for(int i=fr;i!=s;i++,i%=n) tmp+=!a[i];
        ans+=min(tmp,cnt-tmp);
        a[s]=1; fr=(s+1)%n;
    }
    printf("%d",ans);
    return 0;
}
