#include <bits/stdc++.h>
using namespace std;

int n,m;
char a[210];

int main(){
    //freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++,n=0,memset(a,0,sizeof(char)*210))
    {
        scanf("%s",a);
        for(int i=0;a[i];i++) a[i]-='0',n++;
        int flag=0;
        for(int i=0;i<n;)
        {
            if(!a[i]&&a[i+1]) {i+=2; continue;}
            if(!a[i]&&!a[i+1]) {flag=1; break;}
            if(a[i+1]||a[i+2]) {flag=1; break;}
            while(i<n&&!a[++i]) ;
            if(i>=n) {flag=1; break;}
            if(!a[i+1]) {i++; continue;}
            while(i<n&&a[++i]) ;
            if(i>=n) break;
            if(a[i+1]) {i+=2; continue;}
            i--;
        }
        printf(flag?"NO\n":"YES\n");
    }
    return 0;
}
