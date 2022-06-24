//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), s(n), suffix(n), prefix(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    prefix[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i] != p[i - 1])
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] != s[i + 1])
            suffix[i] = suffix[i + 1] + 1;
        else
            suffix[i] = suffix[i + 1];
    }
    // // suffix[0] = 1e2;
    reverse(suffix.begin(), suffix.end());
    if (prefix == suffix)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    // for (int i = 0; i < n; i++)
    //     cout << prefix[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << suffix[i] << " ";
    // cout << endl;
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