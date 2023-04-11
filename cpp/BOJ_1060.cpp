




typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

int n,m,a[55];

ll amel(int p)
{
    if(a[n-1]<p) return LLONG_MAX;
    int t=lower_bound(a,a+n,p)-a;
    if(a[t]==p) return 0;
    return ((ll)p-a[t-1])*((ll)a[t]-p)-1;
}

struct cmp
{
    bool operator()(const int lhs,const int rhs)const
    {
        return amel(lhs)==amel(rhs)?lhs<rhs:amel(lhs)<amel(rhs);
    }
};

set<int,cmp> ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    n++;
    cin>>m;
    sort(a,a+n);
    for(int i=0;i<n;i++)
        for(int j=max(1,a[i]-m);j<a[i]+m;j++) ans.insert(j);
    for(auto i:ans)
    {
        if(!m--) return 0;
        printf("%d ",i);
    }
    return 0;
}
