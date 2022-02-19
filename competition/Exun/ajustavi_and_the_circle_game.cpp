#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int m, x;
      cin >> m >> x;
      int prev = 1;
      cout << prev << " ";
      for (int i = 2; i <= x; i++)
      {
         int res = m % i;
         if (res == 0)
            res = i;
         if (res <= prev)
            prev++;
         cout << prev << " ";
      }
      cout << endl;
   }
   return 0;
}