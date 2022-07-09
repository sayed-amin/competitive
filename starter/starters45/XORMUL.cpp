/*
XORMUL.cpp
30 June 2022
Thu 04:58

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int g = gcd(x, y);
        x /= g;
        y /= g;
        int ans = 0;
        for (int a : {x, y})
        {
            for (int i = 2; i * i <= a; i++)
            {
                while (a % i == 0)
                {
                    ans += i;
                    a /= i;
                }
            }
            if (a > 1)
                ans += a;
        }
        cout << ans << endl;
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