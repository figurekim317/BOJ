#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 15746

int n,m;

bool amel(int p)
{
    if(p<3) return (p&2);
    if(!(p&1)) return 0;
    for(int i=3;i*i<=p;i+=2) if(p%i==0) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(~scanf("%d",&n)) m+=amel(n);
    printf("%d",m);
    return 0;
}
