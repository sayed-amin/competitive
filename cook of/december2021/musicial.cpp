#include <iostream>
// this is a trial for github 2222
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      n--;
      int ans = 0;
      for (int i = 1; i * i <= n; i++)
      {
         if (n % i == 0)
         {
            ans++;
            if (i * i != n)
               ans++;
         }
      }
      cout << ans << endl;
   }
   return 0;
}