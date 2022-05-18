#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > p(11);
    for (int i = 1; i < 11; i++)
    {
        p[i].first = i;
        p[i].second = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;

        (p[a].second)++;
    }
    // for (int i = 1; i < 11; i++)
    // {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    int max = 0;
    int ans = 0;
    for (int i = 1; i < 11; i++)
    {
        if (max < p[i].second)
        {
            max = p[i].second;
            ans = i;
        }
    }
    // cout << max;
    int maxc = 0;
    for (int i = 1; i < 11; i++)
    {
        if (max == p[i].second)
            maxc++;
    }
    if (maxc <= 1)
        cout << ans << endl;
    else
        cout << "confused" << endl;
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