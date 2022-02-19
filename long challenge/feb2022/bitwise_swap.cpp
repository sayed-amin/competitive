#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      int flag = 0;

      for (int i = 0; i < n - 1; i++)
      {

         for (int j = i + 1; j < n; j++)
         {
            if ((a[i] & a[j]) != 0 && a[i] > a[j])
            {
               swap(a[i], a[j]);
            }
         }
      }
      for (int i = 0; i < n - 1; i++)
      {
         if (a[i] > a[i + 1])
            flag = 1;
      }
      if (flag)
         cout << "no" << endl;
      else
         cout << "yes" << endl;
   }
   return 0;
}