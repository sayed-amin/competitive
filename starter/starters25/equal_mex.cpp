#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> a(2 * n);
      map<int, int> m;
      for (int i = 0; i < 2 * n; i++)
      {
         cin >> a[i];
         m[a[i]]++;
      }
      int flag = 1;

      for (int i = 0; i < n; i++)
      {
         if (m[i] == 0)
         {
            break;
         }
         else if (m[i] == 1)
         {
            flag = 0;
         }
      }
      if (flag == 1)
         cout << "yes" << endl;
      else
         cout << "no" << endl;
   }
   return 0;
}