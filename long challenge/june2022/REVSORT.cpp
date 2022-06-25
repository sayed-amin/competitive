/*
REVSORT.cpp
24 June 2022
Fri 22:02
subbarray sorting
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> pre(n, 0), suff(n, 0), a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            pre[i] = a[i];
        if (i > 0)
            pre[i] = pre[i - 1] + a[i];
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + a[i];
    }
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "yes" << endl;
    else
    {
        bool flag = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] <= a[i + 1])
                continue;
            if (a[i] > a[i + 1])
            {
                if (a[i] + a[i + 1] <= x)
                    swap(a[i], a[i + 1]);
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
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