#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 15746

int n,m,a[30];
char c;

int main(){
    //freopen("input.txt","r",stdin);
    while(~scanf(" %c",&c)) c<'a'?a[c-'A']++:a[c-'a']++;
    m=max_element(a,a+26)-a;
    for(int i=0;i<26;i++) if(i!=m&&a[i]==a[m]) {printf("?"); return 0;}
    printf("%c",m+'A');
    return 0;
}
