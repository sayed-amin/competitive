/*
Untitled-1.cpp
26 June 2022
Sun 23:03

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n = 1e10 + 1;
    int m = 1e10;
    int t = 1e5 + 1;
    cout << (m % n) % t << endl;
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