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
vpii a,ans;

bool chk(pii p, pii q)
{
    return p.ss*q.ff == q.ss*p.ff;
}

bool lenchk(pii p, pii q)
{
    return p.ff*p.ff + p.ss*p.ss == q.ff*q.ff + q.ss*q.ss;
}

void amel(pii p)
{
    if(p.ff==0&&p.ss==0) return;
    for(auto i:ans) if(chk(p,i)) return;
    for(auto i:a)
        if(!chk(p,i))
        {
            bool flag=false;
            for(auto j:a)
                if(i!=j && lenchk(i, j) && p.ff * (i.ff - j.ff) == - p.ss *  (i.ss - j.ss))
                    {flag=true; break;}
            if(!flag) return;
        }
    ans.pb(p);
}

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i.ff>>i.ss;
    for(auto t=a.begin(); t!=a.end(); ++t) if(t->ff==0&&t->ss==0) {a.erase(t); break;}
    if(a.empty()) {cout<<-1; return;}
    for(int i=a.size();i--;)
        for(int j=i+1;j--;)
        {
            pii tmp={a[i].ff+a[j].ff, a[i].ss+a[j].ss};
            if(tmp.ff==0&&tmp.ss==0) tmp={a[i].ss-a[j].ss, a[j].ff-a[i].ff};
            amel(tmp);
        }
    cout<<ans.size();
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
