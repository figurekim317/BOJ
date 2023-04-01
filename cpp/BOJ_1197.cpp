#include <bits/stdc++.h>
typedef long long int ll;
int p[10002];
typedef struct edge
{
    ll start, end, value;
    bool operator < (edge e1)
    {
        return value < e1.value;
    }
} edge;
std::vector<edge> ed;
int find(ll node)
{
    if(node==p[node])return node;
    return p[node]=find(p[node]);
}

void merge(ll node1, ll node2)
{
    ll a1 = find(node1);
    ll a2 = find(node2);
    if(a1==a2) return;
    p[a2]=a1;
}

int main(void)
{
    int v, e;
    int result = 0;
    scanf("%d %d", &v, &e);
    for(int i = 1; i <= v; i++) p[i] = i;
    for(int i = 0; i < e; i++)
    {
        int st, en, va;
        scanf("%d %d %d", &st, &en, &va);
        edge tmp;
        tmp.start = st;
        tmp.end = en;
        tmp.value = va;
        ed.push_back(tmp);
    }
    std::sort(ed.begin(), ed.end());
    for(int i = 0; i < e; i++)
    {
        if(find(ed[i].start)!=find(ed[i].end))
        {
            merge(ed[i].start, ed[i].end);
            result+=ed[i].value;
        }
    }
    printf("%d", result);
    return 0;
}