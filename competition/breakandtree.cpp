#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long

#define endl "\n"

int N, limit = 19, timer = 1;
vector<int> value;
vector<int> sum;   // sum[i] = sum of values of nodes in path from 1 to i.
vector<bool> mark; // mark[i] = 1, if ith node is changed by query 1.
vector<int> depth;
vector<int> newValue; // newValue[i] = new value assigned by query 2.
vector<int> startTime;
vector<int> finishTime;
vector<vector<int> > tree;
vector<bool> valueChanged; // valueChanged[i] = 1 if value of ith node was changed.
vector<vector<int> > table(1e5 + 5, vector<int>(20, 0));

void dfs(int src, int parent, int level = 1)
{
   startTime[src] = ++timer;
   depth[src] = level;
   sum[src] += value[src];
   for (int child : tree[src])
   {
      if (child != parent)
      {
         sum[child] += sum[src];
         dfs(child, src, level + 1);
      }
   }
   finishTime[src] = ++timer;
}
void preprocess()
{
   // Create Adjancency List repr of Tree.
   for (auto &i : tree)
      i.clear();
   for (int i = 2; i <= N; i++)
   {
      int parent = table[i][0];
      tree[parent].push_back(i);
      tree[i].push_back(parent);
   }
   // Update vectors with values of new tree.
   for (int i = 1; i <= N; i++)
   {
      sum[i] = 0;
      valueChanged[i] = 0;
      mark[i] = 0;
      value[i] = newValue[i];
   }
   // For node i, calculate 2^j-th parent.
   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= limit; j++)
      {
         table[i][j] = table[table[i][j - 1]][j - 1];
      }
   }
   timer = 1;
   dfs(1, -1);
}

int getLCA(int x, int y)
{
   if (depth[x] < depth[y])
   {
      swap(x, y);
   }
   for (int j = limit; j >= 0; j--)
   {
      if ((depth[x] - (1 << j)) >= depth[y])
      {
         x = table[x][j];
      }
   }
   if (x == y)
      return x;
   for (int j = limit; j >= 0; j--)
   {
      if (table[x][j] != table[y][j])
      {
         x = table[x][j];
         y = table[y][j];
      }
   }
   return table[x][0];
}
bool isAncestor(int u, int v)
{
   return ((startTime[u] <= startTime[v]) && (finishTime[v] <= finishTime[u]));
}

void solve()
{
   preprocess();
   int Q;
   cin >> Q;
   int sqrtLimit = 4 * sqrt(N), count = 0;
   vector<int> nodesToBeChecked;
   while (Q--)
   {
      if (count == sqrtLimit)
      {
         count = 0;
         preprocess();
         nodesToBeChecked.clear();
      }
      count++;
      int queryType, x, y;
      cin >> queryType >> x >> y;
      if (queryType == 1)
      {
         mark[x] = 1;
         table[x][0] = y;
         for (int j = 1; j <= limit; j++)
         {
            table[x][j] = table[table[x][j - 1]][j - 1];
         }
         depth[x] = depth[y] + 1;
      }
      else if (queryType == 2)
      {
         newValue[x] = y;
         if (valueChanged[x] == 0)
         {
            valueChanged[x] = 1;
            nodesToBeChecked.push_back(x);
         }
      }
      else
      {
         int lca = getLCA(x, y);
         int ans = 0LL;
         while (x != lca && mark[x] == 1)
         {
            ans += newValue[x];
            x = table[x][0];
         }
         while (y != lca && mark[y] == 1)
         {
            ans += newValue[y];
            y = table[y][0];
         }
         if (x == y)
         {
            ans += newValue[lca];
         }
         else
         {
            ans += (sum[x] + sum[y] - 2 * sum[lca] + newValue[lca]);
            for (int node : nodesToBeChecked)
            {
               if (node == lca)
                  continue;
               if (isAncestor(node, x) && !isAncestor(node, y))
               {
                  ans = ans - value[node] + newValue[node];
               }
               else if (isAncestor(node, y) && !isAncestor(node, x))
               {
                  ans = ans - value[node] + newValue[node];
               }
            }
         }
         cout << ans << endl;
      }
   }
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   value.resize(N + 1);
   tree.resize(N + 1);
   newValue.resize(N + 1);
   valueChanged.assign(N + 1, 0);
   mark.assign(N + 1, 0);
   depth.resize(N + 1);
   sum.assign(N + 1, 0);
   startTime.resize(N + 1);
   finishTime.resize(N + 1);
   for (int i = 2; i <= N; i++)
   {
      cin >> table[i][0];
   }
   for (int i = 1; i <= N; i++)
   {
      cin >> value[i];
      newValue[i] = value[i];
   }

   solve();
}