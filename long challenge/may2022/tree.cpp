// not able to solve will try it later
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) int((x).size())
vector<vector<int>> g;
vector<int> v1;
vector<set<int>> subtree;
vector<int> res;
const int inf = 1e17;
void dfs(int v, int par = -1)
{
    res[v] = inf;
    subtree[v].insert(v1[v]);
    for (int child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        res[v] = min(res[v], res[child]);
        if ((int)subtree[v].size() < (int)subtree[child].size())
            swap(subtree[v], subtree[child]);

        for (auto &e : subtree[child])
        {
            auto it = subtree[v].lower_bound(e);

            if (it != subtree[v].end())
            {
                res[v] = min(res[v], e ^ *it);
            }
            if (it != subtree[v].begin())
            {
                --it;
                res[v] = min(res[v], e ^ *it);
            }
            subtree[v].insert(e);
        }
        subtree[child].clear();
    }
}
void solve()
{
    int n;
    cin >> n;
    g.clear();
    v1.clear();
    subtree.clear();
    g.resize(n + 1);
    v1.resize(n + 1);
    subtree.resize(n + 1);
    res.resize(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        if (res[i] == inf)
            res[i] = -1;
        cout << res[i] << ' ';
    }
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}