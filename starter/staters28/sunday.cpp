#include <bits/stdc++.h>
#include <set>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s1, s2;
    s1 = {6, 13, 20, 27};
    s2 = {7, 14, 21, 28};
    int ans = 8;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (s1.count(a[i]) || s2.count(a[i]))
        {
            continue;
        }
        else
            ans++;
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