#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   // your code goes here
   int t;
   cin >> t;
   while (t--)
   {
      int n, w;
      cin >> n >> w;
      vector<int> a(n);
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         sum += a[i];
      }
      if (sum < w)
         cout << 0 << endl;
      else
      {
         sort(a.begin(), a.end());
         int count = 0;
         for (int i = n - 1; i >= 0; i--)
         {
            w -= a[i];
            count++;
            if (w <= 0)
            {
               break;
            }
         }
         cout << n - count << endl;
      }
   }
   return 0;
}
