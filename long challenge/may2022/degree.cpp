#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int a[n];
    bool even = true, odd = true;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            even = false;
        if (!(a[i] & 1))
            odd = false;
        if (max < a[i])
            max = a[i];
    }
    if (even)
    {
        cout << max / 2 << endl;
    }
    else if (odd)
    {
        cout << ceil((max) / 2.0) << endl;
    }
    else
    {
        if (max & 1)
        {
            cout << ceil((max) / 2.0) << endl;
        }
        else
            cout << max / 2 << endl;
    }

    // if (n == 1)
    //     cout << 0 << endl;
    // else
    // {
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         if (a[i] != 0)
    //         {
    //             cout << i << endl;
    //             break;
    //         }
    //     }
    // }
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