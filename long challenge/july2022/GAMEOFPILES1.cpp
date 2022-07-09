/*
GAMEOFPILES1.cpp
08 July 2022
Fri 15:51

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    int count = 0;
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            c1++;
    }
    //  sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        ans += a[i] - 1;
    }
    if (c1 == 0)
    {
        if ((ans & 1))
        {
            cout << "chef" << endl;
        }
        else
        {
            cout << "CHEFINA" << endl;
        }
    }
    else
    {
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