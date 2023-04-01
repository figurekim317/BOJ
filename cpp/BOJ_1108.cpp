#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef pair<int, int> pii;
map<string, int> STOI;

int N,cnt,num,VC,SC;
string u, v,want;

vector<vector<int>> adj;
vector<vector<pii>> scc_adj;
vector<int> sccid, discovered;

vector<long long> cache;
stack<int> st;

int scc(int here) {
    int ret = discovered[here] = VC++;
    st.emplace(here);

    for (auto there : adj[here]) {
        if (discovered[there] == -1) ret = min(ret, scc(there));
        else if (sccid[there] == -1) ret = min(ret, discovered[there]);
    }

    if (ret == discovered[here]) {
        while (1) {
            int t = st.top();
            st.pop();
            sccid[t] = SC;
            if (t == here) break;
        }
        SC++;
    }
    return ret;
}

int main() {
    FAST;
    cin >> N;
    adj.resize(2501);
    rep(i, N) {
        cin >> u >> cnt;
        if (STOI.find(u) == STOI.end()) STOI[u] = num++;
        rep(j, cnt) {
            cin >> v;
            if (STOI.find(v) == STOI.end()) STOI[v] = num++;
            adj[STOI[v]].emplace_back(STOI[u]);
        }
    }
    cin >> want;
    if (STOI.find(want) == STOI.end()) STOI[want] = num++;

    discovered = sccid = vector<int>(2501, -1);
    rep(i, num) if (discovered[i] == -1) scc(i);

    scc_adj.resize(2501);
    rep(here,num) for(auto there : adj[here]){
        if (sccid[here] != sccid[there])
            scc_adj[sccid[here]].emplace_back(here, there);
    }

    int wt =STOI[want];
    cache.resize(2500, 1);
    for (int i = SC-1;i;--i) {
        for (auto [a,b] : scc_adj[i]){
            cache[b] += cache[a];
        }
    }
    cout << cache[wt];
    return 0;
}
 
