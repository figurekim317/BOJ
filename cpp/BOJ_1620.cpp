#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char *,int> pci;
#define N 100010
#define M 25
#define MOD 10007

int n,m;
pci a[N];
char s[N][M],b[M];

bool comp(pci lhs,pci rhs)
{
    return strcmp(lhs.first,rhs.first)>0;
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]),a[i].second=i,a[i].first=s[i];
    sort(a+1,a+n+1,comp);
    while(m--)
    {
        scanf("%s",b);
        if(b[0]>'9')
            printf("%d\n",lower_bound(a+1,a+n+1,make_pair(b,0),comp)->second);
        else
        {
            int t=0;
            for(int i=0;b[i];i++) t*=10,t+=b[i]-'0';
            printf("%s\n",s[t]);
        }
    }
    return 0;
}
