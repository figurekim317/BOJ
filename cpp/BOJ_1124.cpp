#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 200010
#define M 3010

int n,m,p[100010]={-1,-1},a[100010],ans;
list<int> prime;

int main(){
  //  freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n>>m;
    prime.pb(2);
    for(int i=3;i<=m;i+=2)
    {
        if(!~p[i]) continue;
        prime.pb(i);
        for(int j=i*3;j<=m;j+=i<<1) p[j]=-1;
    }
    for(int i=2;i<=m;i++)
    {
        if(i&1 && ~p[i]) a[i]=1;
        else
        {
            for(auto j:prime)
                if(i%j==0) {a[i]=a[i/j]+1; break;}
        }
        if(n<=i && (a[i]==2 || (a[i]&1 && ~p[a[i]]))) ans++;
    }
    cout<<ans;

    /*
}//*/
    return 0;
}
