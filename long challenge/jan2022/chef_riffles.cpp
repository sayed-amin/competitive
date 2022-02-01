#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   
   int t;
   cin >> t;
   while (t--)
   {
      int f = 0;
      int n, k;
      cin >> n >> k;
      vector<int> Original(n + 1);
      vector<int> New(n + 1);
      vector<int> store(n + 1);
      vector<int> ty[n + 1];
      for (int i = 1; i <= n; i++)
         Original[i] = i;
      store = Original;

      while (1)
      {
         int temp = ceil(n / 2);
         int count = 1;

         for (int j = 1; j <= n; j++)
         {
            if (j & 1)
            {
               New[count] = Original[j];
               count++;
            }
            else
            {
               temp++;
               New[temp] = Original[j];
            }
         }
         Original = New;
         f++;
         ty[f] = Original;
         if (store == Original)
         {
            k = k % f;
            break;
         }
      }
      for (auto i : ty[k])
      {
         
         cout << i << " ";
      }

      cout << endl;
   }
   return 0;
}