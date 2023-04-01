#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 61
#define MOD 10007

int n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++)
        {
            int flag=1;
            for(int r=3;r<=n;r*=3)
                if(r/3<=i%r&&i%r<r/3<<1&&r/3<=j%r&&j%r<r/3<<1) {flag=0; break;}
            cout<<(flag?"*":" ");
        }
    return 0;
}
