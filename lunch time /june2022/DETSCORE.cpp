//
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int total = 0;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        total ^= a[i];
    }
    if (n % 2 == 0)
    {
        total = a[0];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == total)
            swap(a[i], a[0]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (a[i] ^ total) << " ";
    }
    cout << endl;
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