// no prequisites
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
vector<vector<int>> g(N);
vector<int> value(N);
vector<int> ans(N);
vector<int> sum(N);

int final_ans;
void dfs(int v, int par = -1)
{

    ans[v] = value[v];
    sum[v] = 0;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        ans[v] = gcd(ans[v], ans[child]);
        sum[v] += ans[child];
    }
}
void dfs2(int u, int p, int beautytillparent)
{
    int beauty = beautytillparent;
    if (p != -1)
        beauty += sum[p] - ans[u];
    beautytillparent = beauty;
    for (auto x : g[u])
    {
        if (x == p)
            continue;
        dfs2(x, u, beautytillparent);
        beauty += ans[x];
    }

    final_ans = max(final_ans, beauty);
}

void solve()
{
    int n;
    final_ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);

    dfs2(1, -1, 0);
    cout << final_ans << endl;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}