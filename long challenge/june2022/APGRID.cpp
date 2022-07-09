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
    if (n < m)
    {
        for (int i = 0; i < m; i++)
            cout << i + 1 << " ";
        cout << endl;
        int add = n + 2;
        for (int i = 1; i < n; i++)
        {
            int temp = add;
            cout << temp << " ";
            for (int j = 1; j < m; j++)
            {
                temp += i + 1;
                cout << temp << " ";
            }
            add += n + 1;
            cout << endl;
        }
    }
    else
    {
        int add = m + 1;
        int sum;
        for (int i = 0; i < n; i++, add++)
        {
            int sum = i + 1;
            cout << sum << " ";
            for (int j = 1; j < m; j++)
            {
                sum += add;
                cout << sum << " ";
            }
            cout << endl;
        }
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