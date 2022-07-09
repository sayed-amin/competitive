/*
abc.cpp
08 July 2022
Fri 15:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, x;
    cin >> n >> x;
    if (x >= n)
        cout << 0 << endl;
    else
        cout << ceil((n - x) / 4.0) << endl;
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