#include <iostream>
#include <string>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int x;
      cin >> x;
      string s;
      cin >> s;
      int c, n, d;
      c = n = d = 0;
      for (auto i = 0; i < s.size(); i++)
      {
         if (s[i] == 'C')
            c++;
         else if (s[i] == 'N')
            n++;
         else
            d++;
      }
      c = c * 2 + d;
      n = n * 2 + d;
      if (c > n)
         cout << 60 * x << endl;
      else if (c < n)
      {
         cout << 40 * x << endl;
      }
      else if (c == n)
         cout << 55 * x << endl;
   }
   return 0;
}