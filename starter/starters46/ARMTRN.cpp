/*
ARMTRN.cpp
08 July 2022
Fri 07:18
sorting
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totalsum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    // define rating as r
    for (int r = 0; r < n; r++)
    {
        ans = max(ans, sum * (((1000 * (n - r)) - (totalsum - sum))));
        sum += a[r];
    }
    cout << ans << endl;
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