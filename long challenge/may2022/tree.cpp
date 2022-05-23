#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INT_SIZE 32;
vector<vector<int> > g;
vector<int> v1;
vector<vector<int> > subtree;
vector<vector<int> > v;
int minXOR(vector<int> &arr, int n)
{
    // Sort given array
    sort(arr.begin(), arr.end());

    int minXor = INT_MAX;
    int val = 0;

    // calculate min xor of consecutive pairs
    for (int i = 0; i < n - 1; i++)
    {
        val = arr[i] ^ arr[i + 1];
        minXor = min(minXor, val);
    }

    return minXor;
}
void dfs(int v, int par = -1)
{
    subtree[v].push_back(v);
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        subtree[v].push_back(child);
        for (auto i : subtree[child])
        {
            if (i == child)
                continue;
            subtree[v].push_back(i);
        }
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
    v.resize(n + 1);

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
    for (int i = 0; i < subtree.size(); i++)
    {
        for (int j = 0; j < subtree[i].size(); j++)
            v[i].push_back(v1[subtree[i][j]]);
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].size() == 1)
            cout << -1 << " ";
        else
        {

            cout << minXOR(v[i], v[i].size()) << " ";
        }
    }
    cout << endl;
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