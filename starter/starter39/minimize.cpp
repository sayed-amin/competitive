#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<vector<int> > g;
vector<vector<pair<int, int> > > g1;
vector<int> c;
void dfs(int v, int par = -1)
{
    c[v] += 1;
    for (auto child : g[v])
    {
        if (par == child)
            continue;
        dfs(child, v);
        c[v] += c[child];
    }
}
void solve()
{
    cin >> n >> k;
    g.resize(n + 1);
    c.assign(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // g1[v].push_back({u, w});
        // g1[u].push_back({v, w});
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
    }
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