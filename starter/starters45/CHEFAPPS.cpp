/*
CHEFAPPS.cpp
29 June 2022
Wed 20:02

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int a1 = 2 * n;
    vector<int> a(a1);
    int od = 0, e = 0;

    for (int i = 0; i < a1; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            od++;
    }
    e = a1 - od;
    // cout << od << " " << e << endl;
    sort(odd.begin(), odd.end());

    if (od > e)
    {
        cout << od - n << endl;
    }
    else
    {
        vector<int> odd;
        for (int i = 0; i < a1; i++)
        {
            if (a[i] & 1)
                continue;

            e++;
            if ((a[i] & (a[i] - 1)) == 0)
                odd.push_back(a[i] / 2);
            else
            {
                int op = 0;
                while (a[i] % 2 == 0)
                {
                    a[i] = a[i] / 2;
                    op++;
                }
                odd.push_back(op);
            }
        }
        int no_odd = e - n;
        int ans = 0;
        for (int i = 0; i < no_odd; i++)
        {
            ans += odd[i];
        }
        cout << ans << endl;
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