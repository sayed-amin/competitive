#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int count = 0;
    if (n == 1)
        cout << 1 << endl;
    else if (n == 2)
    {
        if (a[0] == a[1])
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] == a[i - 1])
            {
                a[i - 1] = -1;
                count++;
            }
            else if (a[i] == a[i + 1])
            {
                a[i] = -1;
                count++;
            }
        }
        cout << n - count << endl;
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