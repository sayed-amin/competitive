#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int binary_exp(int x, int y)
{
    if (y == 0)
        return 1;
    int res = binary_exp(x, y / 2);
    if (y & 1)
        return (x * ((res * res) % MOD)) % MOD;
    return (res * res) % MOD;
}
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n % 2 == 0)
    {
        int ans = binary_exp(2, n);
        ans--;
        while (ans < 0)
            ans += MOD;
        ans = (ans * 2) % MOD;
        ans = (ans + binary_exp(2, n - 1)) % MOD;
        int temp = binary_exp(2, n / 2);
        temp--;
        while (temp < 0)
            temp += MOD;
        temp = (temp * 4) % MOD;

        ans -= temp;
        while (ans < 0)
            ans += MOD;

        // Ya we got our final answer.
        cout << ans << "\n";
    }
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