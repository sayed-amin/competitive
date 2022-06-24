//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n), v(n);
    multiset<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        s.insert({v[i], i});
    }

    int alice = 0, bob = 0;
    int flag = 1;
    while (!s.empty())
    {
        auto pos = s.end();
        pos--;
        int num = pos->second;
        int temp = pos->second;
        if (flag == 1)
        {
            auto pos = s.end();
            pos--;
            int num = pos->second;
            int temp = pos->second;
            alice += pos->first;
            flag = 0;
        }
        else
        {
            pos = s.begin();
            int num = pos->second;
            bob += pos->first;
            flag = 1;
        }
        s.erase({v[num], num});
        c[num] = c[num] - 1;
        if (c[num] > 0)
        {
            s.insert({v[num], num});
        }

        if (flag == 0)
        {
            num--;
            while (num >= 0 and !s.empty())
            {
                auto f = s.find({v[num], num});
                if (f != s.end())
                    s.erase({v[num], num});
                num--;
            }
        }
    }
    cout << alice << " " << bob << endl;
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