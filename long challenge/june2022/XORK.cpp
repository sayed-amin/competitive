/*
REVSORT.cpp
24 June 2022
Fri 22:02
subbarray sorting
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int miin = 1e15;
    int kth_bit = log2(k) + 1;
    vector<int> a(n), bit(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= k)
        {
            cout << 1 << endl;
            return;
        }
        bit[i] = log2(a[i]) + 1;
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (kth_bit > bit[i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
    }
    else
        cout << -1 << endl;
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