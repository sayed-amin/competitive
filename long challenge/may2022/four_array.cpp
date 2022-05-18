#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(a) for (int i = 0, i < a; i++)
void solve()
{
    int sa, sb, sc, sd, k;
    cin >> sa >> sb >> sc >> sd >> k;
    int a[sa], b[sb], c[sc], d[sd];
    for (int i = 0; i < sa; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < sb; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < sc; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < sd; i++)
    {
        cin >> a[i];
    }
    map<int, int> m;
    for (int i = 0; i < sa; i++)
    {
        for (int j = 0; j < sb; j++)
        {
            for (int k = 0; k < sc; k++)
            {
                for (int l = 0; l < sd; l++)
                {
                    
                }
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
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}