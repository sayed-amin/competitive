/*
REVSORT.cpp
24 June 2022
Fri 22:02
subbarray sorting
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int miin = 1e15;
    vector<int> pre(n, 0), suff(n, 0), a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            pre[i] = a[i];
        }
        if (i > 0)
            pre[i] = pre[i - 1] ^ a[i];
        // cout << pre[i] << " ";
        if (a[i] >= k)
        {
            miin = min(miin, 1ll);
        }
    }
    // cout << endl;
    suff[n - 1] = a[n - 1];
    // cout << suff[n - 1] << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] ^ a[i];
        //  cout << suff[i] << " ";
    }
    int ans = 0;
    // cout << endl;
    for (int i = 0; i < n; i++)
    {

        if (pre[i] >= k)
        {
            miin = min(miin, (i + 1));
        }
        if (suff[i] >= k)
            miin = min(miin, (n - i));
    }
    if (miin != 1e15)
        cout << miin << endl;
    else
        cout << -1 << endl;
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