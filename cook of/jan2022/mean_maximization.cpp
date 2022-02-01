#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <ios>
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
      sort(a, a + n);
      double sum = 0;
      for (int i = 0; i < n - 1; i++)
         sum += a[i];
      sum = sum / (n - 1);
      sum = sum + a[n - 1];
      cout << fixed << setprecision(6.0) << sum << endl;
   }
   return 0;
}