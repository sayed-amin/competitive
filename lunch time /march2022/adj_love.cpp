#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> odd, even;
    int a[n];
    int fle = 1, flo = 1;
    int oc = 0, ec = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
        {
            fle = 0;
            odd.insert(a[i]);
            oc++;
        }
        else
        {
            flo = 0;
            ec++;
            even.insert(a[i]);
        }
    }
    if (fle == 1)
        cout << -1 << endl;
    else if (flo == 1)
    {
        if (n & 1)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        if (oc == 1)
            cout << -1 << endl;
        else
        {
            if (!(n & 1))
            {
                if (oc == n - 1)
                    cout << -1 << endl;
                else
                {
                    for (auto i : odd)
                    {
                        cout << i << " ";
                    }
                    for (auto i : even)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                for (auto i : odd)
                {
                    cout << i << " ";
                }
                for (auto i : even)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
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