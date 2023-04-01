#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 10007

int n,ans;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i<100) ans++;
        else if(i!=1000)
        {
            int tmp=i;
            int p=tmp%10; tmp/=10;
            int q=tmp%10; tmp/=10;
            int r=tmp;
            ans+=(p-q==q-r);
        }
    }
    printf("%d",ans);
    return 0;
}
