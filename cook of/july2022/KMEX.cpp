/*
KMEX.cpp
03 July 2022
Sun 20:13

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> count(101);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count[x]++;
    }
    int remove = 0;
    int total = 0;
    for (int i = 0; i < k; i++)
    {
        if (count[i] == 0)
        {
            // cout << 1;
            cout << "no" << endl;
            return;
        }
        remove += count[i] - 1;
        total += count[i];
    }
    int after = 0;
    for (int i = k + 1; i <= n; i++)
    {
        after += count[i];
    }
    if (total > m)
    {
        int to_remove = total - m;
        // cout << 2;
        if (to_remove <= remove)
            cout << "yes" << endl;
        else
        {
            cout << "no" << endl;
        }
    }
    else
    {
        int to_add = m - total;
        // cout << 3;
        if (after >= to_add)
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