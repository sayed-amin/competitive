/*
GRPASSN.cpp
08 July 2022
Fri 06:20
map
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if (i->second < i->first)
        {
            cout << "No" << endl;
            return;
        }
        else if (i->second > i->first)
        {
            if (i->second % i->first != 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
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