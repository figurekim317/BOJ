#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m;
vector<int> s;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    if(!n) {cout<<'0'; return 0;}
    if(m>0)
    {
        if(n<0) n=-n,cout<<'-';
        for(;n;n/=m)
            s.insert(s.begin(),n%m);
    }
    else
    {
        m=-m;
        for(int i=1;n;n/=m,i*=-1)
        {
            int t=(i*(n%m)+m)%m;
            s.insert(s.begin(),t);
            n-=t*i;
        }
    }
    for(auto i:s) cout<<i;
    return 0;
}