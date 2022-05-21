#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1)
    {
        int mid = floor(n / 2.0);
        int temp = n - 1;
        int count = 0;
        for (int i = 0; i <= mid; i++)
        {
            if (s[i] != s[temp])
                count++;
            temp--;
        }
        cout << count << endl;
    }
    else
    {
        int mid = floor(n / 2.0);
        int temp = n - 1;
        int count = 0;
        for (int i = 0; i <= mid; i++)
        {
            if (s[i] != s[temp])
                count++;
            temp--;
        }
        cout << count << endl;
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