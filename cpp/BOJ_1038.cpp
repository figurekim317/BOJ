#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 1000000007

int n;
set<ll> ans;


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    if(n>=1023) {printf("-1"); return 0;}
    for(int i=0;i<1<<10;i++)
    {
        ll tmp=0; int p=i;
        for(int j=9;j>=0;j--,p>>=1)
            if(p&1) tmp*=10ll,tmp+=(ll)j;
        ans.insert(tmp);
    }
    for(ll i:ans)
    {
        if(!n) {printf("%lld",i); return 0;}
        else n--;
    }
    return 0;
}
