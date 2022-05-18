#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x, y;
    cin >> x >> y;
    int a = 500 - x * 2;
    int b = 1000 - (x + y) * 4;
    int total = a + b;
    a = 1000 - y * 4;
    b = 500 - (x + y) * 2;
    cout << max(total, a + b) << endl;
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