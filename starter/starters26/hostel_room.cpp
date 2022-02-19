#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // your code goes here
   int t;
   cin >> t;
   while (t--)
   {
      int n, x;
      cin >> n >> x;
      int a[n + 1];
      for (int i = 1; i <= n; i++)
      {
         cin >> a[i];
      }
      int sum = 0;
      int ans1 = x;
      int ans[n];
      int maX = 0;
      for (int i = 1; i <= n; i++)
      {
         ans1 += a[i];
         ans[i] = ans1;
         maX = max(maX, ans1);
      }
      cout << maX << endl;
   }
   return 0;
}
