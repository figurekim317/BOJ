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

int n,m;
string w;

struct node
{
    vi a, b, c;
    bool operator<(const node rhs)const
    {
        for(int i = 0; i < c.size(); i++) if(c[i]!=rhs.c[i]) return c[i]<rhs.c[i];
        for(int i = 0; i < a.size(); i++) if(a[i]!=rhs.a[i]) return a[i]<rhs.a[i];
        return false;
    }
}r;
vector<node> ans;

bool amel(int &p, int &q, int &r, bool carried, bool carry, bool ped, bool qed, bool red)
{
    if(r>=0)
    {
        if(p>=0)
        {
            if(q>=0)
                return p+q+carried == r + carry * 10;
            else
            {
                q=r+carry*10 - (p+carried);
                return (!qed||q) && 0<=q && q<10;
            }
        }
        else
        {
            if(q>=0)
            {
                p=r+carry*10 - (q+carried);
                return (!ped||p) && 0<=p && p<10;
            }
            else
            {
                p= r+carry*10 - carried;
                if(p<0 || p>18) return false;
                q=0;
                if(p>9) q=p-9, p=9;
                if(!p&&!q&&(ped||qed)) return false;
                if(qed&&!q) p--,q++;
                return !ped||p;
            }
        }
    }
    else
    {
        if(p>=0)
        {
            if(q>=0)
            {
                r = p+q+carried - carry*10;
                return (!red||r) && 0<=r && r<10;
            }
            else
            {
                r= p+9+carried -carry*10;
                if(r<0 || r>18) return false;
                q=9;
                if(r>9) q-=r-9, r=9;
                return (!red||r) && (!qed||q);
            }
        }
        else
        {
            if(q>=0)
            {
                r= q+9+carried -carry*10;
                if(r<0 || r>18) return false;
                p=9;
                if(r>9) p-=r-9, r=9;
                return (!red||r) && (!ped||p);
            }
            else
            {
                if(carry&&!carried) r=8;
                else r=9;
                if(carry) p=q=9;
                else
                {
                    p= carried?8:9;
                    q=0;
                    if(qed) p--,q++;
                }
                return true;
            }
        }
    }
}

void Solve()
{
    cin>>w;
    for(auto &i:w) if(i=='?') i='0'-1;
    int tmp=0;
    for(;w[tmp]!='+';tmp++) r.a.pb(w[tmp]-'0');
    for(tmp++;w[tmp]!='=';tmp++) r.b.pb(w[tmp]-'0');
    for(tmp++;tmp<w.size();tmp++) r.c.pb(w[tmp]-'0');
    if(r.c.size() > max(r.a.size(), r.b.size()) + 1 || r.c.size() < min(r.a.size(), r.b.size())) {cout<<-1; return;}

    int a=r.a.size(), b=r.b.size(), c=r.c.size();
    for(int i=1<<c-1; i--;)
    {
        node tmp=r;
        bool carried, carry=false, flag=true;
        for(int j=1; flag && j<=c; j++)
        {
            carried = carry;
            carry = (i>>j-1) & 1;
            int h=0;
            if(j>a&&j>b)
                flag = amel(h, h, tmp.c[c-j], carried, carry, false, false, c!=1&&j==c);
            else if(j>a)
                flag = amel(h, tmp.b[b-j], tmp.c[c-j], carried, carry, false, b!=1&&j==b, c!=1&&j==c);
            else if(j>b)
                flag = amel(tmp.a[a-j], h, tmp.c[c-j], carried, carry, a!=1&&j==a, false, c!=1&&j==c);
            else
                flag = amel(tmp.a[a-j], tmp.b[b-j], tmp.c[c-j], carried, carry, a!=1&&j==a, b!=1&&j==b, c!=1&&j==c);
        }
        if(flag)
        {
            if(ans.empty()) ans.pb(tmp);
            else ans[0]=max(ans[0], tmp);
        }
    }
    if(ans.empty()) {cout<<-1; return;}
    for(auto i:ans[0].a) cout<<i;
    cout<<'+';
    for(auto i:ans[0].b) cout<<i;
    cout<<'=';
    for(auto i:ans[0].c) cout<<i;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
