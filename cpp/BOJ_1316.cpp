#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define M 61
#define MOD 10007

int n,m,a[30];

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(string s;n--;)
    {
        memset(a,-1,sizeof(a));
        cin>>s;
        int flag=1;
        for(int i=0;s[i];i++)
            if(a[s[i]-'a']<0||a[s[i]-'a']==i-1) a[s[i]-'a']=i;
            else {flag=0; break;}
        m+=flag;
    }
    cout<<m;
    return 0;
}
