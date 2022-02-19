#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string s;
      int n;
      cin >> n;
      cin >> s;
      if (n & 1)
      {
         cout << "yes" << endl;
      }
      else
      {
         int c0, c1;
         c0 = 0;
         c1 = 0;
         for (int i = 0; i < n; i++)
         {
            if (s[i] == '0')
               c0++;
            else
               c1++;
         }
         if (c0 == c1 || c0 == n || c1 == n || (c0 % 2 == 0 && c1 % 2 == 0))
            cout << "yes" << endl;
         else
            cout << "no" << endl;
      }
   }
   return 0;
}