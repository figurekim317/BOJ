#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,a[55],b[55],cnt,e[55];

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
        if(!b[i])
        {
            cnt++;
            for(int j=i;!b[j];j=a[j]) b[j]=cnt;
        }
    if(--cnt)
    {
        for(int i=0,tmp=-1;;cnt--)
        {
            e[i]=1;
            if(i)
            {
                while(!e[a[i]]) i=a[i],e[i]=1;
                if(!cnt) {a[i]=tmp; break;}
                for(int j=0;;j++)
                    if(b[j]!=1&&!e[j]) {i=a[i]=j; break;}
            }
            else
            {
                for(;a[i]&&!~tmp;i=a[i])
                    for(int j=i+1;j<a[i];j++)
                        if(b[j]!=1) {tmp=a[i]; a[i]=j; break;}
                if(!~tmp)
                {
                    for(int j=i+1;;j++)
                        if(b[j]!=1) {tmp=a[i]; i=a[i]=j; break;}
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
