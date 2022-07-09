/*
SEGFAULT.cpp
03 July 2022
Sun 22:24

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        p[i].first = l;
        p[i].second = r;
        a[l] += 1;
        if (r != n)
            a[r + 1] -= 1;
    }
    for (int i = 2; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    // for (auto i : a)
    //     cout << i << " ";
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == n - 1 and !(p[i].first <= i and i <= p[i].second))
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    ;
    for (auto i : ans)
        cout << i << endl;
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