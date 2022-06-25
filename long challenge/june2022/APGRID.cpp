/*
APGRID.cpp
24 June 2022
Fri 22:54

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> row(m + 1);
    vector<int> additon(m + 1);
    for (int i = 1; i <= m; i++)
    {
        row[i] = i;
        if (i == 1)
            additon[i] = 2;
        if (i > 1)
            additon[i] = additon[i - 1] + 2;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << row[j] << " ";
            row[j] += additon[j];
        }
        cout << endl;
    }
}
int32_t main()
{

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}