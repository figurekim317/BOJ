#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,b[10],ans,len;
string a[10],r;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i],b[i]=i;
    cin>>m;
    do
    {
        r.clear();
        for(int i=0;i<n;i++) r+=a[b[i]];
        len=r.length();
        for(int i=1;i<=len;i++)
            if(len%i==0)
            {
                bool s=1;
                if(i!=len)
                {
                    for(int j=0;j<len;j++)
                        if(r[j]!=r[(j+i)%len]) {s=0; break;}
                }
                if(s)
                {
                    ans+=len/i==m;
                    break;
                }
            }
    }while(next_permutation(b,b+n));
    cout<<ans;
    return 0;
}