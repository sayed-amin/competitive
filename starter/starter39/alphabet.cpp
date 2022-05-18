#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'c' || s[i] == 'g' || s[i] == 'l' || s[i] == 'r')
            ans = (ans * 2) % mod;
    }
    cout << ans % mod << endl;
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