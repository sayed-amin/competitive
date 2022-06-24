/*
atat.cpp
22 June 2022
Wed 22:20

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, x;
    cin >> n;

    vector<int> minimum(n + 1, 0), maximuml(n + 1, 0), maximumr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        minimum[0] += 1;
        minimum[x] -= 1;
        maximuml[0] += (n - x + 1);
        maximuml[x] -= (n - x + 1);
        maximumr[n - 1] += (n - x);
        maximumr[x] -= (n - x);
    }
    for (int i = 1; i <= n; i++)
    {
        minimum[i] += minimum[i - 1];
        maximuml[i] += maximuml[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
        maximumr[i] += maximumr[i + 1];
    for (int i = 0; i < n; i++)
    {
        int ans = maximuml[i] + maximumr[i];
        cout << minimum[i] << " " << ans << endl;
    }
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