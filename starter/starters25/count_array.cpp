// dp and counting
// graph
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
vector<vector<int> > dp;
int power(int x, int y)
{
    int res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
void preprocess(int n, int m)
{
    dp.assign(n + 1, vector<int>(2, 0ll));
    dp[1][0] = 0;
    dp[1][1] = m;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] * (m - 2)) % MOD + (dp[i - 1][1] * (m - 1)) % MOD;
        dp[i][0] %= MOD;
        dp[i][1] = dp[i - 1][0];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 1ll;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= 1;
    }
    preprocess(n, m);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        int curr = i, count = 0;
        while (vis[curr] == 0)
        {
            count++;
            vis[curr] = 1;
            curr = a[curr];
        }
        if (vis[curr] == 2)
        {
            ans = (ans * power(m - 1, count)) % MOD;
        }
        else
        {
            int cyclelen = 1;
            for (int j = a[curr]; j != curr; j = a[j])
                cyclelen++;
            ans = (dp[cyclelen][0] * ans) % MOD;
            ans = (ans * power(m - 1, count - cyclelen)) % MOD;
        }
        curr = i;
        while (vis[curr] != 2)
        {
            vis[curr] = 2;
            curr = a[curr];
        }
    }
    ans %= MOD;
    cout << ans << endl;
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