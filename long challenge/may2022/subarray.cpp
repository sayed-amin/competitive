#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // unordered_map<int, int> m;
//     map<int, int, greater<int> > m;

//     for (int i = 0; i < n; i++)
//     {
//         int lenght = a[i];
//         int start_index = ((i - lenght + 1) >= 0) ? (i - lenght + 1) : 0;
//         auto pos = m.find(a[i]);
//         if (pos != m.end() and pos->second >= start_index)
//             start_index = pos->second + 1;
//         int end_index = (start_index + lenght - 1 >= n) ? n - 1 : start_index + lenght - 1;
//         if (end_index - start_index + 1 != lenght || start_index > end_index)
//             continue;
//         count += min((i - start_index + 1), (n - end_index));
//         m.insert({a[i], i});
//     }
//     cout << count << endl;
// }
int solve()
{
    int n;
    cin >> n;
    long long ans = (long long)n * (n + 1) / 2; // we calculate the number of subarrays that do not fulfill the given condition
    vector<vector<int> > arr_index(n + 1, vector<int>(1, -1));
    for (int i = 0; i < n; i++) // store indices of each number
    {
        int x;
        cin >> x;
        arr_index[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) // iterate over length
    {
        arr_index[i].push_back(n);
        for (int j = 1; j < (int)arr_index[i].size(); j++) // if i is found in some indices, then subarray between two consecutive indices does not contain i. So all smaller subarrays of len i in this subarray are invalid.
        {
            int l = arr_index[i][j] - arr_index[i][j - 1] - 1;
            ans -= max(0LL, l - i + 1);
        }
    }
    cout << ans << '\n';
    return 0;
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