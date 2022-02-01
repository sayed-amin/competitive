#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, x, n) for (int i = x; i < n; i++)
#define br cout << endl
#define vi vector<int>
using namespace std;

int tcp(int pr, int pt)
{
   for (int i = 0; i < 21; i++)
   {
      if ((pt & (1 << i)) > 0)
         pr ^= (1 << i);
   }
   return pr;
}
//this is my solve funtion
void part()
{
   int n;
   cin >> n;
   vector<int> res;

   map<int, int> m;
   m[0] = 1;
   int pt = 1;
   int pr = 0;
   for (int i = 0; i < n; i++)
   {
      // cout<<ptr<<endl;
      while (s[tcp(pr, pt)] == 1)
      {
         pt++;
      }
      pr = fun(pr, pt);
      m[prev] = 1;
      res.push_back(pt);
      pt++;
   }

   for (auto x : res)
      cout << x << " ";
   cout << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   fastio int t;
   t = 1;
   cin >> t;
   while (t--)
   {
      part();
   }
}