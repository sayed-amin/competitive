#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> b(2 * n);
      int odd = 0, even = 0;
      for (int i = 0; i < 2 * n; i++)
      {
         cin >> b[i];
         if (b[i] & 1)
            odd++;
         else
            even++;
      }
      if (!(even & 1) && !(odd & 1))
         cout << "yes" << endl;
      else if (!(even & 1) && (odd & 1))
         cout << "no" << endl;
      else if ((even & 1) && !(odd & 1))
         cout << "yes" << endl;
      else if ((even & 1) && (odd & 1))
         cout << "no" << endl;
   }
   return 0;
}