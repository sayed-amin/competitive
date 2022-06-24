//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> occ;
    int cnt = 0;
    long long prf = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prf ^= a[i];
        if (occ[prf]++ == 0)
        {
            cnt++;
        }
    }
    long long tot = prf;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        prf ^= a[i];
        if (occ[prf]++ == 0)
        {
            cnt++;
        }
        if (--occ[prf ^ tot] == 0)
        {
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
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