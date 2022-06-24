#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        for (int i = n; i >= 1; i--)
            cout << i << " ";
        cout << endl;
    }
    else if (n == 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n - 1 << " " << n - 2 << " " << n << " ";
        for (int i = n - 3; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << endl;
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