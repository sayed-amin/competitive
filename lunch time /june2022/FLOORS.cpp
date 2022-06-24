//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    string ans;
    if (n & 1)
    {

        for (int i = 0; i < (n / 2); i++)
        {
            ans.push_back('0');
        }
        ans.push_back('1');
        for (int i = 0; i < (n / 2); i++)
        {
            ans.push_back('0');
        }
        cout << ans << endl;
    }
    else
    {
        ans.push_back('1');
        for (int i = 0; i < n - 2; i++)
        {
            ans.push_back('0');
        }
        ans.push_back('1');
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