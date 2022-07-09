/*
GAMEOFPILES2.CPP
09 July 2022
Sat 11:43

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        ans += a[i] - 1;
    }
    if ((ans & 1))
        cout << "chef" << endl;
    else
        cout << "CHEFINA" << endl;
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