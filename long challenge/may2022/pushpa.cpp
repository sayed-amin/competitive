#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        m[h]++;
    }
    int ans = 0;
    map<int, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++)
    {
        ans = max(ans, i->first + i->second - 1);
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