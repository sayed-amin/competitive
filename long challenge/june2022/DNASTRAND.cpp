/*
DNASTRAND.cpp
24 June 2022
Fri 15:23
no prerequisites
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            cout << 'T';
        if (s[i] == 'T')
            cout << 'A';
        if (s[i] == 'C')
            cout << 'G';
        if (s[i] == 'G')
            cout << 'C';
    }
    cout << endl;
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