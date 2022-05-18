#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, x;
    cin >> n >> x;
    int health[n];
    int max = -1;
    int count = 0;
    int ans = 0;
    map<int, int> m;
    map<int, int>::iterator i;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    for (i = m.begin(); i != m.end(); i++)
    {
        if (i->first > max)
            max = i->first;
        if (i->first > x)
        {
            ans += (ceil((i->first * 1.0) / x)) * i->second;
        }
        else if (i->first <= x)
        {
            ans += i->second;
        }
    }
    if (max < ans)
        cout << max << endl;
    else
        cout << ans << endl;
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