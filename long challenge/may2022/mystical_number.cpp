#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    // vector<vector<int> > dp(33, vector<int>(n + 1, 0));
    int dp[33][n + 1];
    for (int i = 1; i <= n; i++)
    {
        int g;
        cin >> g;
        for (int j = 0; j < 33; j++)
        {
            dp[j][i] = dp[j][i - 1];
        }
        int power = 32;
        if (g != 0)
            power = (log(g)) / log(2);
        dp[power][i]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int count = 0;
        int power = 32;
        if (x != 0)
            power = (log(x)) / log(2);
        count = dp[power][r] - dp[power][l - 1];
        int ans = (r - l + 1) - count;
        cout << ans << endl;
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