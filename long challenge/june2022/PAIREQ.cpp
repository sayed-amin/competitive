/*
PAIREQ.cpp
24 June 2022
Fri 15:28

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    vector<int> pregcd(n, 0);
    vector<int> suffgcd(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            ans = a[i];
            pregcd[i] = a[i];
        }
        if (i > 0)
        {
            ans = gcd(a[i], ans);
            pregcd[i] = gcd(pregcd[i - 1], a[i]);
        }
    }

    suffgcd[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffgcd[i] = gcd(a[i], suffgcd[i + 1]);
    }
    // cout << suffgcd[0] << " " << pregcd[n - 1];
    // cout << endl;
    // cout << ans << endl;
    if (ans == 1)
    {
        int count = 0;
        if (pregcd[n - 2] > 1)
            count++;
        if (suffgcd[1] > 1)
            count++;
        for (int i = 1; i <= n - 2; i++)
        {
            if (gcd(pregcd[i - 1], suffgcd[i + 1]) > 1)
                count++;
        }
        if (count == 0)
            cout << 0 << endl;
        else
            cout << count << endl;
    }
    else
        cout << n << endl;
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