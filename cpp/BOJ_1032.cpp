include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
char a[55][55];

bool amel(int p,char c)
{
    for(int i=2;i<=n;i++)
        if(a[i][p]!=c) return 0;
    return 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]),m=max(m,(int)strlen(a[i]));
    for(int i=0;i<m;i++)
    {
        char c=a[1][i];
        printf("%c",amel(i,c)?c:'?');
    }
    return 0;
}
