//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, x;
    cin >> n >> x;
    string ans;
    string temp;
    if (ceil(n / 2.0) < x)
        cout << -1 << endl;
    else
    {
        if (!(n & 1))
        {
            int total = ceil(n / 2.0);
            char last;
            for (int i = 0; i < x; i++)
            {
                ans.push_back('a' + i);
                last = 'a' + i;
            }
            int final = total - x;
            if (final)
            {
                while (final)
                {
                    ans.push_back('a');
                    final--;
                }
            }

            temp = ans;
            reverse(temp.begin(), temp.end());
            ans = ans + temp;

            cout << ans << endl;
        }
        else
        {
            int total = ceil(n / 2.0);
            char last;
            for (int i = 0; i < x - 1; i++)
            {
                ans.push_back('a' + i);
                last = 'a' + i;
            }
            int final = total - x;
            if (final)
            {
                while (final)
                {
                    ans.push_back('a');
                    final--;
                }
            }

            temp = ans;
            reverse(temp.begin(), temp.end());
            if (x != 1)
                ans = ans + 'z';
            else
                ans = ans + 'a';
            ans = ans + temp;

            cout << ans << endl;
        }
    }
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