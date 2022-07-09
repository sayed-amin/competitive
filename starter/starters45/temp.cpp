/*
temp.cpp
29 June 2022
Wed 21:01

*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ith_a = a & (1 << i);
        int ith_b = b & (1 << i);
        if (a == b)
        {
            if (ith_a == 0 and ith_b == 0)
                ans = ans | (1 << i);
        }
        else if (a > b)
        {
            if (ith_a == 0 and ith_b == 0)
                ans = ans | (1 << i);
            else if (ith_a == 0 and ith_b == 1)
                ans = ans | (1 << i);
        }
        else
        {
            if (ith_a == 0 and ith_b == 0)
                ans = ans | (1 << i);
            else if (ith_b == 0 and ith_a == 1)
                ans = ans | (1 << i);
        }
    }
    cout << ans << endl;
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