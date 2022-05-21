#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int> > > g1;
vector<int> c;
int dfs(int v, int par = -1, int blocked = false)
{
    int node = 1;
    for (auto child : g1[v])
    {
        if (par == child.first)
            continue;
        int x = dfs(child.first, v, (blocked || child.second));
        node += x;
        if (child.second && !blocked)
            c.push_back(x);
    }
    return node;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    g1.clear();
    c.clear();
    g1.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g1[v].push_back({u, w});
        g1[u].push_back({v, w});
    }
    dfs(1);

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int infected = n;
    if (infected <= k)
    {
        cout << 0 << endl;
        return;
    }
    for (auto i = 0; i < c.size(); i++)
    {
        infected -= c[i];
        if (infected <= k)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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