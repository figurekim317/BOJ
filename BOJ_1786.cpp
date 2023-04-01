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

void KMP_fail (int fail[], string P)
{
    for (int len = P.size(), cmp = 0, i = 1 ; i < len ; i++)
    {
		while (cmp > 0 && P[i] != P[cmp])
			cmp = fail[cmp-1];
		if (P[i] == P[cmp])
			fail[i] = ++cmp;
	}
}

vector<int> KMP (string T, string P) // in string T, find P
{
    vector<int> ret;
    int fail[P.size() + 5] = {0};
    KMP_fail(fail, P);
    for (int Tlen = T.size(), Plen = P.size(), cmp = 0, i = 0 ; i < Tlen ; i++)
    {
		while (cmp > 0 && T[i] != P[cmp])
			cmp = fail[cmp - 1];
		if (T[i] == P[cmp])
		{
			if (cmp == Plen - 1)
			{
				ret.push_back(i - cmp + 1);
				cmp = fail[cmp];
			}
			else cmp++;
		}
	}
	return ret;
}

int n,m;
string T,P;

int main(){
   // freopen("input.txt","r",stdin);
    getline(cin, T);
	getline(cin, P);
    auto p=KMP(T,P);
    printf("%d\n",p.size());
    for(auto i:p) printf("%d ",i);
    return 0;
}
