#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAX 205
#define INF 987654321
#define MOD 1000000
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n,m,ans=0,mem[MAX];
char str[15][25];
bool tf[10];
vector<int>v;
vector<string> vs;

int kmp(int in)
{
    int ret=0;
    string smp=vs[in],pat=vs[in];
    smp.append(vs[in]);
    // 비교될 문자열(smp) = 만들어진 문자열*2를 한다.
    // 비교할 문자열(pat) = 만들어진 문자열
    
    int j = 0;
    for (int i = 0; i < smp.size()-1; i++)
    {
        while (j > 0 && smp.at(i) != pat.at(j))
            j = mem[j - 1];
        if (smp.at(i) == pat.at(j))
        {
            if (j == pat.size() - 1)
            {
                ret++;
                j=mem[j];
            }
            else
                j++;
        }
    }
    return ret;
}

void getpi(int in)
//pi값을 생성한다.
{
    int j = 0;
    for (int i = 1; i < vs[in].size(); i++)
    {
        while (j > 0 && vs[in].at(i) != vs[in].at(j))
            j = mem[j - 1];
        if (vs[in].at(i) == vs[in].at(j))
            mem[i] = ++j;
    }
    return ;
}

void make_string()
// 최초 문자열로 문자열을 만들어준다.
{
    if(v.size()==n)
    {
        string tmp;
        for(int i=0;i<v.size();i++)
            tmp.append(str[v[i]]);
        vs.push_back(tmp);
        return ;
    }
    for(int i=2;i<=n;i++)
        if(!tf[i])
        {
            tf[i]=true;
            v.push_back(i);
            make_string();
            v.pop_back();
            tf[i]=false;
        }
}

int main()
{
    scanf("%d",&n);
    v.push_back(1);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]);
    // 문자열 입력으로 받아오고
    make_string();
    // 문자열 조합으로 만들어준다.
    scanf("%d",&m);
    for(int i=0;i<vs.size();i++)
    {
        getpi(i);
        if(kmp(i)==m)
            ans+=n;
    }
    // 각각 kmp돌려준다.
    printf("%d",ans);
    return 0;
}
