//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            int div1 = i, div2 = n / i;
            if (div2 == 2)
                ++ans;
            else
                ans += 2;
            if (div2 != div1 and div2 != n)
            {
                if (div1 == 2)
                    ++ans;
                else
                    ans += 2;
            }
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