#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<char> ans(2 * n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int turn = 1;

    int first = 0, end = 2 * n - 1;

    int ab = 0, ae = n - 1;
    int bb = 0, be = n - 1;

    int count = 2 * n - 1;
    for (int i = 0; i < 2 * n; i++)
    {

        if (!(i & 1))
        {

            if (a[ab] < b[bb] and ab <= ae)
            {
                ans[first] = a[ab];
                first++;
                ab++;
            }
            else
            {
                ans[end] = a[ae];
                end--;
                ae--;
            }
        }
        else
        {
            if (a[ab] < b[bb] && ab <= ae)
            {
                ans[first] = b[bb];
                first++;
                bb++;
            }
            else
            {
                ans[end] = b[be];
                end--;
                be--;
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
        cout << ans[i];
    cout << endl;
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