#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
const int V = 4;
int n, m;
vector<bool> vis;
vector<vector<int> > adj;
vector<int> components;
// no of connected components
int get_components(int idx)
{
   if (vis[idx])
      return 0;
   vis[idx] = true;
   int ans = 1;
   for (auto i : adj[idx])
   {
      if (!vis[i])
      {
         ans += get_components(i);
         vis[i] = true;
      }
   }
   return ans;
}
// cycle is present or not

bool iscycle(int src, vector<bool> &visited, int parents)
{
   visited[src] = true;
   for (auto i : adj[src])
   {
      if (i != parents)
      {
         if (visited[i])
            return true;
         if (!visited[i] and iscycle(i, visited, src))
         {

            return true;
         }
      }
   }
   return false;
}
// bipartite or not
bool isBipartite(int V)
{
   // vector to store colour of vertex
   // assigning all to -1 i.e. uncoloured
   // colours are either 0 or 1
   // for understanding take 0 as red and 1 as blue
   vector<int> col(V, -1);

   // queue for BFS storing {vertex , colour}
   queue<pair<int, int> > q;

   // loop incase graph is not connected
   for (int i = 0; i < V; i++)
   {

      // if not coloured
      if (col[i] == -1)
      {

         // colouring with 0 i.e. red
         q.push({i, 0});
         col[i] = 0;

         while (!q.empty())
         {
            pair<int, int> p = q.front();
            q.pop();

            // current vertex
            int v = p.first;
            // colour of current vertex
            int c = p.second;

            // traversing vertexes connected to current vertex
            for (int j : adj[v])
            {

               // if already coloured with parent vertex color
               // then bipartite graph is not possible
               if (col[j] == c)
                  return 0;

               // if uncooloured
               if (col[j] == -1)
               {
                  // colouring with opposite color to that of parent
                  col[j] = (c) ? 0 : 1;
                  q.push({j, col[j]});
               }
            }
         }
      }
   }
   // if all vertexes are coloured such that
   // no two connected vertex have same colours
   return 1;
}

int main()
{

   cout << "no of vertices and edadjers between them" << endl;
   cin >> n >> m;
   adj = vector<vector<int> >(n);

   for (int i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   bool cycle = false;
   vector<bool> visited(n, false);
   for (int i = 0; i < n; i++)
   {
      if (!visited[i] and iscycle(i, visited, -1))
      {
         cycle = true;
      }
   }
   if (cycle)
      cout << "cylcle is present in graph" << endl;
   else
      cout << "cycle is not present in graph" << endl;

   bool ans = isBipartite(V);
   // returns 1 if bipartite graph is possible
   if (ans)
      cout << "graph is bipartite\n";
   // returns 0 if bipartite graph is not possible
   else
      cout << "graph is not bipartite\n";

   vis = vector<bool>(n, false);
   for (int i = 0; i < n; i++)
   {
      if (!vis[i])
      {
         components.push_back(get_components(i));
      }
   }
   cout << "no of components is: ";
   cout << components.size();
   cout << endl;
   cout << "size of each components are : ";
   for (auto i : components)
      cout << i << " ";
   cout << endl;
   if (components.size() == 1)
      cout << "graph is connected" << endl;
   else
      cout << "graph is not connected" << endl;
   return 0;
}