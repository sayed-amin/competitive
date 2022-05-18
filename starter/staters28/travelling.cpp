#include <bits/stdc++.h>
#include <set>
using namespace std;
//
int N = 2 * 1e5;
vector<vector<int> > adj(N + 1);
vector<bool> vis;
int Max = 0;
void dfs(int vertex)
{
    if (vertex > Max)
        Max = vertex;

    if (vis[vertex])
        return;
    vis[vertex] = true;

    for (int child : adj[vertex])
    {

        dfs(child);
    }
}
void solve()
{

    int n, m;
    cin >> n >> m;
    vis.assign(n, 0);

    int max = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (max <= u)
        {
            max = u;
        }
        else if (max < v)
        {
            max = v;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    set<int> rem, M;
    int p = Max;

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            rem.insert(i);
        }
        if (vis[i])
            continue;
        else
        {
            Max = 0;
            dfs(i);
            M.insert(Max);
            count++;
        }
    }
    int ans = 0;

    if (rem.size() == 0)
        cout << ans << endl;
    else if (m == 0)
    {
        if (n == 2)
            cout << 1 << endl;
        else
            cout << n - 1 << endl;
    }
    else
    {
        if (count == 0)
        {
            for (auto i = rem.begin(); i != rem.end(); i++)
            {
                int j = abs(max - *i);
                j *= j;
                ans += j;
                if (max < *i)
                    max = *i;
            }
            cout << ans << endl;
        }
        else
        {
            for (auto i = M.begin(); i != M.end(); i++)
            {
                int j = abs(p - *i);
                j *= j;
                ans += j;
                if (p < *i)
                    p = *i;
            }l
            cout << ans << endl;
        }
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