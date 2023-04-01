#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,w;
vector<char> a;

bool chk()
{
    for(int i=1,t=a.size(); i*w<=t; i++)
    {
        bool ret=true;
        for(int j=1;j<w;j++)
        {
            for(int k=1;k<=i;k++)
                if(a[t-k]!=a[t-j*i-k]) {ret=false; break;}
            if(!ret) break;
        }
        if(ret) return false;
    }
    return true;
}

bool amel()
{
    if(a.size()>=n) return true;
    for(int i=0;i<m;i++)
    {
        a.pb(i+'A');
        if(chk() && amel()) return true;
        a.pop_back();
    }
    return false;
}

void Solve()
{
    cin>>w>>n>>m;
    if(!amel()) {cout<<-1; return;}
    for(auto i:a) cout<<i;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
