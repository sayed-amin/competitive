#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}
void solve()
{
    int w;
    cin >> w;

    map<int, int> m;
    set<int> powerof2;
    int count = 0;
    for (int i = 0; i < w; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        int n = i->first;
        // cout << n;
        if (!isPowerOfTwo(n))
        {
            while (n)
            {
                int nearest = floor(log2(n));
                auto pos = powerof2.find(nearest);
                n = n - pow(2, nearest);
                if (pos == powerof2.end())
                {
                    powerof2.insert(nearest);
                    count++;
                }
            }
        }
        else
        {
            int b = ceil(log2(n));

            auto pos = powerof2.find(b);
            if (pos == powerof2.end())
            {
                powerof2.insert(b);
                count++;
            }
        }
    }
    cout << count << endl;
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