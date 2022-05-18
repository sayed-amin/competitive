#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int temp = n;
    int ans = 0;
    int flag;
    ans = temp % 10;
    temp = temp / 10;
    if (ans & 1)
    {
        flag = 0;

        while (temp)
        {
            ans = temp % 10;
            temp = temp / 10;
            if (ans & 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        flag = 1;
        while (temp)
        {
            ans = temp % 10;
            temp = temp / 10;
            if (!(ans & 1))
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            cout << "yes" << endl;
        else
            cout << "No" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}