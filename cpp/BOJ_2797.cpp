#include <bits/stdc++.h>
using namespace std;

int tmp1[300010],tmp2[300010];
int n,k,h[300010],t[300010],m[300010],vis[300010];
queue<int> que;

int dfs(int p)
{
    if(vis[p]) return m[p];
    vis[p]=1;
    int val=m[p];
    if(p&&h[p-1]<=h[p]) val+=dfs(p-1);
    if(p<n-1&&h[p]>=h[p+1]) val=max(val,m[p]+dfs(p+1));
    return m[p]=val;
}


int main(){
    scanf("%d %d",&n,&k); k--;
    for(int i=0;i<n;i++) scanf("%d",tmp1+i);
    for(int i=0;i<n;i++)
    {
        char c;
        scanf(" %c",&c);
        if(c=='T') tmp2[i]=1;
    }

    int idx=0;
    h[0]=tmp1[0]; t[0]=tmp2[0]; m[0]++;
    for(int i=1;i<n;i++)
    {
        if(tmp1[i]==h[idx]) t[idx]|=tmp2[i];
        else h[++idx]=tmp1[i],t[idx]=tmp2[i];
        m[idx]++;
        if(i==k) k=idx;
    }
    n=idx+1;

    for(int i=0;i<n;i++)
        if(t[i])
        {
            int x=i;
            while(x&&!t[x-1]&&h[x-1]>=h[x]) t[--x]=1;
            x=i;
            while(x<n-1&&!t[x+1]&&h[x]<=h[x+1]) t[++x]=1;
        }

   /*
    for(int i=0;i<n;i++)
        if(!t[i]&&(!i||h[i-1]>h[i])&&(i==n-1||h[i]<h[i+1])) que.push(i);
    while(!que.empty())
    {
        int i=que.front();
        if(i<n-1&&h[i]<=h[i+1]) m[i+1]+=m[i],que.push(i+1);
        if(i&&h[i-1]>=h[i]) m[i-1]+=m[i],que.push(i-1);
        que.pop();
    }//*/

    for(int i=0;i<n;i++)
        if(!t[i]&&!vis[i]) dfs(i);


    if(!t[k]) printf("%d",m[k]);
    else
    {
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
            t[i]?cnt+=m[i]:ans=max(ans,m[i]);
        printf("%d",cnt+ans);
    }
    return 0;
}
