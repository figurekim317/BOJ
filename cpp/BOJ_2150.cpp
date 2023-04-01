#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 100010
#define M 100010
#define MOD 1000000009
#define MAX_V 10010

int dis[MAX_V + 5], scc[MAX_V + 5], v,c;
stack<int> st;
vector< vector<int> > vt;
vector< vector<int> > res;

int dfs_scc(int now)
{
    int ret = dis[now] = c++;
    st.push(now);
    for (int i : vt[now])
    {
        if (! ~ dis[i])
            ret = min(ret, dfs_scc(i));
        else if (! ~ scc[i])
            ret = min(ret, dis[i]);
    }
    if (ret == dis[now])
    {
        vector<int> tmp;
        for(int siz = res.size(), t = -1 ; t != now ; )
        {
            t = st.top(); st.pop();
            scc[t] = siz;
            tmp.push_back(t);
        }
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
    }
    return ret;
}

void SCC() // edge 2D vector or list needed
{
    memset(dis, -1, sizeof(dis));
    memset(scc, -1, sizeof(scc));
    for (int i = 1 ; i <= v ; i++)
        if (! ~ dis[i])
            dfs_scc(i);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int n,m,x,y,e;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d", &v, &e);
    vt.resize(v + 1);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
    }
    SCC();
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for (auto i:res) {
        for (auto h : i)
            printf("%d ", h);
        printf("-1\n");
    }
    return 0;
}
