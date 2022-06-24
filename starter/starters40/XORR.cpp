//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        m[(v[i].first ^ v[i].second)]++;
    }
    for (auto p : m)
    {

        ans += (p.second * (p.second - 1)) / 2;
    }
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