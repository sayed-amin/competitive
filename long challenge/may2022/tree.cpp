// not able to solve will try it later
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> > g;
vector<int> v1;
vector<int> subtree;
vector<int> res;
vector<multiset<long long> > values;
int dfs(int v, int par = -1)
{
    int c = 1;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        int ans = dfs(child, v);
        subtree[v] += ans + subtree[child];
    }
    return c;
}
void dfs2(int v, int par = -1)
{
    int max_sz = -1, big_child = -1;
    for (auto &child : g[v])
    {
        if (child == par)
            continue;
        if (subtree[child] > max_sz)
            max_sz = subtree[v], big_child = child;
        dfs2(child, v);
        res[v] = min(res[child], res[v]);
    }
    if (big_child != -1)
        swap(values[v], values[big_child]);
    multiset<long long> &cur = values[v];
    auto iter = cur.lower_bound(v1[v]);
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
    subtree.assign(n + 1, 0);
    res.assign(n + 1, 1e15);
    values.resize(n + 1);

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
    for (int i = 1; i < subtree.size(); i++)
    {
        // for (int j = 0; j < subtree[i].size(); j++)
        cout << subtree[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i < subtree.size(); i++)
    // {
    //     for (int j = 0; j < subtree[i].size(); j++)
    //         cout << subtree[i][j] << " ";
    //     cout << endl;
    // }
    // for (int i = 1; i < subtree.size(); i++)
    // {
    //     if (subtree.size() == 1)
    //         cout << -1 << " ";
    //     else
    //     {
    //         // cout << (v1[subtree[i][0]] ^ v1[subtree[i][1]]) << " ";
    //         // cout << (v1[i][0] ^ v1[i][1]) << " ";
    //     }
    // }
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