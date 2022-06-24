/*
JOGGING.cpp
22 June 2022
Wed 20:32

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int m = 1e9 + 7;
vector<int> p;
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << (p[n - 1] * k) % m << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    p.push_back(1);
    for (int i = 0; i < 1000010; i++)
    {
        int x = p[p.size() - 1] * 2;
        x %= m;
        p.push_back(x);
    }
    while (t--)
    {
        solve();
    }
    return 0;
}