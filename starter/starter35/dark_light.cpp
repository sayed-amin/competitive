#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        if (n == 0)
            cout << "off" << endl;
        else
        {
            if (n % 4 == 0)
                cout << "off" << endl;
            else
                cout << "on" << endl;
        }
    }
    else
    {
        if (n == 0 || n % 4 == 0)
            cout << "on" << endl;
        else
            cout << "ambiguous" << endl;
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