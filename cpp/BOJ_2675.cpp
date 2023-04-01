#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 25
#define M 0
#define MOD 15746

int n,m;
char a[N];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    while(n--)
    {
        cin>>m>>a;
        for(int i=0;a[i];i++)
            for(int j=m;j--;) cout<<a[i];
        puts("");
    }
    return 0;
}
