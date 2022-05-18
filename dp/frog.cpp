#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> h;
vector<int> dp;
int m(int n)
{
    if (n == 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cost = 1e5;
    cost = min(cost, m(n - 1) + abs(h[n] - h[n - 1]));
    if (n > 2)
        cost = min(cost, m(n - 2) + abs(h[n] - h[n - 2]));
    return dp[n] = cost;
}
void solve()
{
    int n;
    cin >> n;
    h.assign(n + 1, 0);
    dp.assign(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    cout << m(n);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}