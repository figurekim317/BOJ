#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 310
#define MOD 1000000007

int n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=n;!m||i!=n;m++)
    {
        int tmp=i%10+i/10;
        i=i%10*10+tmp%10;
    }
    printf("%d",m);
    return 0;
}
