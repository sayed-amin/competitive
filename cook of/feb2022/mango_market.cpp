#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;
    int total = n * (n - 1);
    total /= 2;
    int missing = total - m;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int nr;
        cin >> nr >> nr;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int nr;
            cin >> nr >> nr;
            m++;
            missing--;
        }
        else if (ch == '-')
        {
            int nr;
            cin >> nr >> nr;
            m--;
            missing++;
        }
        else
        {
            cout << sum + m - missing << endl;
        }
    }
    return 0;
}
