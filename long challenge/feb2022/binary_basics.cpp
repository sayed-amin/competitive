#include <iostream>
using namespace std;

int main()
{
   // your code goes here
   int t;
   cin >> t;
   while (t--)
   {
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      if (!(n & 1))
      {
         int j = n - 1;
         int i = 0;
         int count = 0;

         while (i < j)
         {

            if (s[i] != s[j])
            {
               count++;
            }
            i++;
            j--;
         }
         if (count > k)
            cout << "NO" << endl;
         else if (count & 1)
            cout << "No" << endl;
         else
            cout << "yes" << endl;
      }
      else
      {
         int i = 0;
         int j = n - 1;

         int count = 0;
         while (i != j)
         {

            if (s[i] != s[j])
            {
               count++;
            }
            i++;
            j--;
         }
         if (count > k)
            cout << "No" << endl;
         else
            cout << "Yes" << endl;
      }
   }
   return 0;
}
