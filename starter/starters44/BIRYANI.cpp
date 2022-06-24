/*
BIRYANI.cpp
22 June 2022
Wed 20:00

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool isvalid(int r, int c)
{
    return r >= 1 and r <= 8 and c >= 1 and c <= 8;
}
void solve()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx[] = {-2, -1, 2, -1, -2, 1, 2, 1};
    int dy[] = {1, 2, 1, -2, -1, 2, -1, -2};

    vector<vector<int>> v(9, vector<int>(9, 0));
    for (int i = 0; i < 8; i++)
    {
        int x = x1 + dx[i];
        int y = y1 + dy[i];
        if (isvalid(x, y))
            v[x][y] = 1;
    }
    bool flag = 0;
    for (int i = 0; i < 8; i++)
    {
        int x = x2 + dx[i];
        int y = y2 + dy[i];
        // cout << 1 << endl;
        if (isvalid(x, y))
        {
            // cout << 1 << endl;
            if (v[x][y] == 1)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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