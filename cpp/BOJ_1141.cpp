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

int n;
vector<string> a,ans;

bool amel(string p, string q)
{
    for(int i=p.size(); i--; )
        if(p[i] != q[i]) return false;
    return true;
}

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i;
    sort(a.begin(), a.end());
    for(int i=a.size(); i--; )
    {
        bool flag=true;
        for(auto j:ans)
            if(amel(a[i], j)) {flag=false; break;}
        if(flag) ans.pb(a[i]);
    }
    cout<<ans.size();
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
