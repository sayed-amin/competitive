/*
SLOWSOLN.cpp
08 July 2022
Fri 18:35

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int mt, mn, sn;
    cin >> mt >> mn >> sn;
    if ((mt * mn) <= sn)
    {
        cout << mn * mn * mt << endl;
    }
    else
    {
        if (sn % mn == 0)
        {
            int ans = sn / mn;
            cout << ans * mn * mn << endl;
        }
        else
        {
            int ans = sn / mn;
            int a = sn % mn;
            cout << ans * mn * mn + a * a << endl;
        }
    }
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