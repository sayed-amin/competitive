#include <bits/stdc++.h>
using namespace std;
#define int long long
int maxSum(vector<int> &arr, int n, int k)
{
    for (auto i : arr)
    {
        cout << i << endl;
    }

    int ans = 0;
    map<int, int> sor;
    for (int i = 0; i < k; i++)
    {
        sor.insert({arr[i], i});
    }
    auto st = sor.begin();
    auto en = sor.end();
    en--;
    // cout << st->second << " " << en->second << endl;
    ans += abs(st->second - en->second);
    int x = 0;
    auto po = sor.lower_bound(arr[x]);
    //   sor.erase({arr[0], 0});
    for (auto i = po; i != sor.begin(); i--)
    {
        if (i->second == 0)
        {
            sor.erase(i);
            break;
        }
    }

    for (int j = k; j < n; j++)
    {

        x++;
        sor.insert({arr[k], j});
        auto st = sor.begin();
        auto en = sor.end();
        en--;
        // cout << st->second << " " << en->second << endl;

        ans += abs(st->second - en->second);
        auto po = sor.lower_bound(arr[x]);
        //   sor.erase({arr[0], 0});
        for (auto i = po; i != sor.begin(); i--)
        {
            if (i->second == x)
            {
                sor.erase(i);
                break;
            }
        }
        if (po == sor.begin())
        {
            if (po->second == x)
            {
                sor.erase(po);
            }
        }
    }

    return ans;
}
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
    map<int, int> m;

    // int ans = 0;
    // map<int, int> m;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int max = a[i];
    //         int min = a[i];
    //         int m = 0;
    //         int v = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             if (max <= a[k])
    //             {
    //                 max = a[k];
    //                 m = k;
    //             }
    //             if (min >= a[k])
    //             {
    //                 min = a[k];
    //                 v = k;
    //             }
    //         }
    //         ans += abs(m - v);
    //     }
    // }
    // cout << ans << endl;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += maxSum(a, n, i);
        // cout << maxSum(a, n, i) << endl;
        // cout << ans << endl;
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