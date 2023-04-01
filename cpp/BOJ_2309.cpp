#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 15746

int n,m,a[10],b[10]={1,1};

int main(){
   // freopen("input.txt","r",stdin);
    for(int i=0;i<9;i++) scanf("%d",a+i);
    sort(a,a+9);
    do
    {
        m=0;
        for(int i=0;i<9;i++) if(!b[i]) m+=a[i];
        if(m==100)
        {
            for(int i=0;i<9;i++) if(!b[i]) printf("%d\n",a[i]);
            return 0;
        }
    }while(prev_permutation(b,b+9));
    return 0;
}