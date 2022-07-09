/*
GCDANDLCM.cpp
26 June 2022
Sun 17:58

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a * a <= n; a++)
    {
        for (int lcm = a; lcm * lcm <= n; lcm += a)
        {
            int lcm_sq = lcm * lcm;
            int a_sq = a * a;
            int b = (n - lcm_sq - a_sq) * lcm_sq;
            if (b <= 0)
            {
                continue;
            }
            int deno = a_sq + lcm_sq;
            if (b % deno != 0)
                continue;
            int b_sq = b / deno;
            int num = sqrt(b_sq);
            if (num * num != b_sq)
                continue;
            int g = gcd(a, num);
            int g_sq = g * g;
            if (a_sq + b_sq + lcm_sq + g_sq == n)
                ans++;
        }
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