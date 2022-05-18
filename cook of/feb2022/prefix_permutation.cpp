#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int vis[N];

int main()
{
   // your code goes here
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      for (int i = 1; i < N; i++)
         vis[i] = i;
      int max = 1;
      for (int i = 0; i < k; i++)
      {
         int y;
         cin >> y;
         if (y > max)
         {
            max = y;
         }
      }

      for (int i = 1; i <= max; i++)
      {
         cout << vis[i] << " ";
      }
      cout << endl;
   }
   return 0;
}
