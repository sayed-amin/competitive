/*
PRIME_XOR.cpp
08 July 2022
Fri 06:54

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int x, y;
    cin >> x >> y;
    int z = x ^ y;
    vector<int> ans;
    ans.push_back(2);
    if (x & 1)
        ans.push_back(x ^ 2);

    if (y & 1)
        ans.push_back(y ^ 2);

    if (z & 1)
        ans.push_back(z ^ 2);

    // check for even
    // if (!(x & 1))
    //     ans.push_back(ans[0] ^ 2);

    // if (!(y & 1))
    //     ans.push_back(ans[0] ^ 2);

    // if (!(z & 1))
    //     ans.push_back(ans[0] ^ 2);

    sort(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << endl;
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