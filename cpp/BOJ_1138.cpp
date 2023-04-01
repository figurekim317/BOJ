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
vi a;
list<int> ans;

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i;
    for(int i=n;i--;)
    {
        auto t=ans.begin();
        while(a[i]--) ++t;
        ans.insert(t, i+1);
    }
    for(auto i:ans) cout<<i<<' ';
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
