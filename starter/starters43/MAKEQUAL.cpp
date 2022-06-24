//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int bit = 1;
    bool flag = true;
    for (int i = 0; i <= 30; i++)
    {
        if (a == b and b == c)
            break;
        bit = (1 << i);
        int count = 0;
        count = (((a & bit)) != 0) + ((b & bit) != 0) + ((c & bit) != 0);
        if (count == 0 || count == 3)
        {
            flag = false;
            break;
        }
        else if (count == 1)
        {
            if ((a & bit))
                a += bit;
            else if ((b & bit))
                b += bit;
            else
                c += bit;
        }
        else
        {
            if ((a & bit) == 0)
                a += bit;
            else if ((b & bit) == 0)
                b += bit;
            else
                c += bit;
        }
    }
    if (flag and a == b and b == c)
        cout << "yes" << endl;
    else
        cout << "NO" << endl;
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