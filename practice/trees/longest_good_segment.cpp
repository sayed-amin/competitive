// binary lifting
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      ll n, k, s;
      cin >> n >> k;
      cin >> s;
      vector<ll> a(n + 1), go(n + 2), ans(n + 2);
      for (ll i = 1; i <= n; i++)
      {
         cin >> a[i];
         a[i] += a[i - 1];
      }
      for (ll i = 1; i <= 1 + n; i++)
      {
         go[i] = upper_bound(a.begin(), a.end(), a[i - 1] + s) - a.begin();
         ans[i] = i;
      }
      for (ll bit = 0; bit < 20; bit++)
      {
         if ((k >> bit) & 1ll)
         {
            for (int i = 1; i <= n + 1; i++)
               ans[i] = go[ans[i]];
         }
         for (ll i = 1; i <= n + 1; i++)
         {
            go[i] = go[go[i]];
         }
      }
      ll maxx = 0;
      for (ll i = 1; i <= n; i++)
      {
         maxx = max(maxx, ans[i] - i);
      }
      cout << maxx << endl;
   }
   return 0;
}