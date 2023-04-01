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

int n,b[55][55],d[55][30],r[55];
string c,a[55];

int main(){
    freopen("input.txt","r",stdin);
    cin>>c>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0,k=0;i<n;i++,k=0)
        for(auto j:a[i]) d[i][j-'a']++;
    for(int i=0;i<c.length();i++)
        for(int j=0;j<n;j++)
        {
            if(i+a[j].length()>c.length()) {b[i][j]=-1; continue;}
            int tmp[30]={};
            for(int k=i,kk=i+a[j].length();k<kk;k++) tmp[c[k]-'a']++;
            if(memcmp(d[j],tmp,sizeof(tmp))) {b[i][j]=-1; continue;}
            for(int k=i,kk=i+a[j].length();k<kk;k++) b[i][j]+=c[k]!=a[j][k-i];
        }
    memset(r,-1,sizeof(r)); r[0]=0;
    for(int i=1;i<=c.length();i++)
        for(int j=0;j<n;j++)
        {
            int t=i-a[j].length();
            if(t>=0&&~b[t][j]&&~r[t]&&(!~r[i]||r[t]+b[t][j]<r[i])) r[i]=r[t]+b[t][j];
        }
    printf("%d",r[c.length()]);
    return 0;
}