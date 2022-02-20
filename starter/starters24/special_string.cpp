// binary lifting
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
void solve(int n, string s, int m)
{
   vector<int> index(26, n); // index[i] cointain last occurence of character i
   vector<int> next(n, n);   // store the first occurence of next character
   for (int i = n - 1; i >= 0; i--)
   {
      int curr = s[i] - 'a';
      next[i] = index[(curr + 1) % 26];
      index[curr] = i;
   }
   int limit = log2(m) + 1;
   vector<vector<int> > dp(n + 1, vector<int>(limit + 1, n));
   for (int i = 0; i <= n - 1; i++)
   {
      dp[i][0] = next[i];
   }
   for (int i = n - 1; i >= 0; i--)
   {
      for (int j = 1; j <= limit; j++)
      {
         dp[i][j] = dp[dp[i][j - 1]][j - 1];
      }
   }
   int ans = 1e9;
   for (int i = 0; i <= n - 1; i++)
   {
      if (s[i] != 'a')
         continue;
      int j = i, depth = m - 1;
      for (int k = limit; k >= 0; k--)
      {
         if (depth - (1 << k) >= 0)
         {
            j = dp[j][k];
            depth -= (1 << k);
         }
      }
      if (j != n)
         ans = min(ans, j - i + 1 - m);
   }
   if (ans != 1e9)
      cout << ans << endl;
   else
      cout << -1 << endl;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      string s;
      cin >> s;
      int m;
      cin >> m;
      solve(n, s, m);
   }
   return 0;
}