#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 200010
vector<int> G[SIZE];
vector<long long> dist;
vector<long long> pre;
void dfs(int i, int p, int d)
{
   bool isleaf = true;
   for (auto j : G[i])
   {
      if (j == p)
         continue;
      isleaf = false;
      dfs(j, i, d + 1);
   }
   if (isleaf)
   {
      dist.push_back(d);
   }
}
int main()
{

   cin.tie(NULL)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      int a[m];
      for (int i = 1; i < n; i++)
      {
         int u, v;
         cin >> u >> v;
         G[u].push_back(v);
         G[v].push_back(u);
      }
      for (int i = 0; i < m; i++)
         cin >> a[i];
      dfs(1, -1, 0);
      sort(dist.begin(), dist.end());
      pre.push_back(dist[0]);
      for (int i = 1; i <= dist.size(); i++)
      {
         pre.push_back(pre[i - 1] + dist[i]);
      }
      long long ans = 0;
      int prev = 0;
      for (int i = 0; i < m; i++)
      {
         int sec = a[i] - prev;
         int ind = lower_bound(dist.begin(), dist.end(), sec) - dist.begin();
         ind = ind - 1;
         if (ind >= 0)
            ans = ans + (long long)sec * (ind + 1) - pre[ind];
         prev = a[i];
      }
      cout << ans << "\n";
      dist.clear();
      pre.clear();
      for (int i = 0; i < n; i++)
         G[i].clear();
   }
   return 0;
}