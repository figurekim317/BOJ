#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define MOD 1000000

int n,m;
list<int> a;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) a.push_back(i);
    printf("<");
    for(auto i=a.begin();n--;)
    {
        for(int j=1;j<m;j++)
        {
            i++;
            if(i==a.end()) i=a.begin();
        }
        printf("%d",*i);
        if(n) printf(", ");
        i=a.erase(i); if(i==a.end()) i=a.begin();
    }
    printf(">");
    return 0;
}
