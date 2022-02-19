#include <iostream>
using namespace std;
bool check(int b[], int n, int m)
{
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += b[i];
   }
   if (sum == m)
      return true;
   else
      return false;
}
int gcd(int a, int b)
{
   // Everything divides 0
   if (a == 0)
      return b;
   if (b == 0)
      return a;

   // base case
   if (a == b)
      return a;

   // a is greater
   if (a > b)
      return gcd(a - b, b);
   return gcd(a, b - a);
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      int a[n], b[n];
      int c[n];
      int gc;
      cin >> n >> m;
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         b[i] = a[i];
      }
      for (int i = 0; i < n; i++)
      {
         b[i] = a[i];
         while (a[i] != 0)
         {

            if (check(b, n, m))
            {
               gc = gcd(0, a[i] - b[i]);
            }
            b[i]--;
         }
      }
      cout << gc << endl;
   }
   return 0;
}