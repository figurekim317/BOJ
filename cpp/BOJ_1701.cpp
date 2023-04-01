#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 5010
#define M 25
#define MOD 10007

int n,m,fail[N],ans;
string a;

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>a;
    for(int i=0;a[i];i++)
    {
        memset(fail,0,sizeof(fail));
        fail[i+1]=i;
        for(int j=i+1,p=i;a[j];j++)
        {
            while(p!=i&&a[p]!=a[j]) p=fail[p];
            if(a[p]==a[j]) p++;
            fail[j+1]=p;
        }
        ans=max(ans,*max_element(fail+i+2,fail+a.size()+1)-i);
    }
    cout<<ans;
    return 0;
}
