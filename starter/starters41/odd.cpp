//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int flag = 1;
    int Max = -1;
    int Min = 1e11;
    for (int i = 0; i < n; i++)
    {
        Max = max(Max, b[i]);
        Min = min(Min, b[i]);
        if (Max == b[i] || Min == b[i])
            continue;
        else
            flag = 0;
    }
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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