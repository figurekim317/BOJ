#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
vector<string> d;
vector<vi> cnt;

void Solve()
{
    for(string i; ; )
    {
        cin>>i;
        if(i=="-") break;
        d.pb(i);
    }
    for(auto i:d)
    {
        vi tmp(26,0);
        for(auto j:i) tmp[j-'A']++;
        cnt.pb(tmp);
    }
    for(string c; ; )
    {
        cin>>c;
        if(c=="#") break;
        vi v(26,0);
        for(auto i:c) v[i-'A']++;
        vector<pair<int,char> > ans;
        vi s;
        for(auto i:cnt)
        {
            int fl=1;
            for(int j=26;fl&&j--;) fl=i[j]<=v[j];
            s.pb(fl);
        }
        for(auto i:c)
        {
            int t=0;
            for(int j=s.size();j--;) t+=cnt[j][i-'A']&&s[j];
            ans.pb(mp(t,i));
        }
        sort(ans.begin(),ans.end());
        ans.resize(unique(ans.begin(),ans.end())-ans.begin());
        string w;
        for(auto t:ans)
            if(t.ff==ans[0].ff) w.pb(t.ss);
        cout<<w<<' '<<ans[0].ff<<' ';
        w.clear();
        for(auto t:ans)
            if(t.ff==ans.back().ff) w.pb(t.ss);
        cout<<w<<' '<<ans.back().ff<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
