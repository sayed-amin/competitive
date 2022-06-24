// kruska;
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<bool> present(m, false);
    int pos = 0, ans = 0, c = 1;
    int x = 0;
    while (pos < m)
    {
        present[pos] = true;
        if (x < n - 1)
        {
            x++;
            ans += a[pos];
        }
        pos += c;
        c++;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (x == n - 1)
            break;
        if (present[i])
            continue;
        x++;
        ans += a[i];
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