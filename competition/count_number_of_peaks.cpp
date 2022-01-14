#include <iostream>
#include <climits>
#include <math.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      if (n == 1)
      {
         cout << "0" << endl;
         continue;
      }
      int ans = 10 * (n - 2) * pow(3, n - 3);
      cout << ans << endl;
   }
}