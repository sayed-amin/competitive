/*
XORPERM.cpp
03 July 2022
Sun 21:09

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<bool> vis(1e5 + 10, 0);
    if (n == 3)
        cout << -1 << endl;
    else
    {
        if (n % 2 == 0)
        {
            for (int i = 2; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << 1 << endl;
        }
        else
        {
            cout << 1 << " " << n << " ";
            for (int i = 2; i <= n - 1; i++)
                cout << i << " ";
            cout << endl;
        }
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