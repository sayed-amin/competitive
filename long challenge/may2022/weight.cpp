#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int max = a[i];
            int min = a[i];
            int m = 0;
            int v = 0;
            for (int k = i; k <= j; k++)
            {
                if (max <= a[k])
                {
                    max = a[k];
                    m = k;
                }
                if (min >= a[k])
                {
                    min = a[k];
                    v = k;
                }
            }
            ans += abs(m - v);
        }
    }
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