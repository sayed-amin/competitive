/*
per.cpp
03 July 2022
Sun 22:01

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int x = n;
    int miin = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << x-- << " ";
        else
            cout << miin++ << " ";
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