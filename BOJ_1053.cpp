





typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

string a;
int ans[55][55],m,dap=INT_MAX;

int main()
{
  //  freopen("input.txt","r",stdin);
    cin>>a;
    if(a.empty()) {printf("0"); return 0;}
    m=a.length();
    for(int i=m-1;i>=0;i--)
        for(int j=i;j>=0;j--)
        {
            swap(a[i],a[j]);
            memset(ans,0,sizeof(ans));
            for(int k=1;k<m;k++)
                for(int l=0;l<m-k;l++)
                {
                    ans[l][l+k]=min(ans[l+1][l+k],ans[l][l+k-1])+1;
                    ans[l][l+k]=min(ans[l][l+k],ans[l+1][l+k-1]+(a[l]!=a[l+k]));
                }
            dap=min(dap,ans[0][m-1]+(j!=i?1:0));
            swap(a[i],a[j]);
        }
    cout<<dap;
    return 0;
}
