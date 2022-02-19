#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      double n, x, y, ans;
      cin >> n >> x >> y;
      double total_bus, total_car;
      if (x == y)
      {
         total_bus = ceil(n / 100);
         cout << total_bus * x << endl;
      }
      else if (x < y)
      {

         total_bus = ceil(n / 100);
         cout << total_bus * x << endl;
      }
      else
      {
         if (n > 100)
         {
            total_bus = floor(n / 100);
            double remaing = n - total_bus * 100;
            ans = total_bus * x;
            double rc = ceil(remaing / 4);
            double r = min(1 * x, rc * y);
            cout << ans + r << endl;
         }
         else
         {
            total_car = ceil(n / 4);
            cout << min(x, total_car * y) << endl;
         }
      }
   }
   return 0;
}