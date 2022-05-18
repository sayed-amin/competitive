#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int> > t(2000);
void solve()
{
    int n;
    cin >> n;
    int a[n];
    int m = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            o++;
        else
            m++;
    }

    if ((t[n].first == o and t[n].second == m) || (t[n].first == m and t[n].second == o) || (o == m) || (o - m) == 1 || (m - o) == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int flag = 1;
    t[3].first = 2;
    t[3].second = 1;
    t[4].first = 2;
    t[4].second = 2;
    for (int i = 5; i <= 1000; i++)
    {
        if (i & 1)
        {
            t[i].first = t[i - 2].first + 1;
            t[i].second = t[i - 2].second + 1;
        }
        else
        {
            if (flag)
            {
                t[i].first = t[i - 2].first + 2;
                t[i].second = t[i - 2].second;
                flag = 0;
            }
            else
            {
                t[i].first = t[i - 2].first;
                t[i].second = t[i - 2].second + 2;
                flag = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}