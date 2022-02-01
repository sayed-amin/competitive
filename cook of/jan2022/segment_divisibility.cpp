#include <iostream>
using namespace std;
int N = 501;
int main()
{
   int a[N];

   for (int i = 1; i <= N; i++)
      a[i] = i;

   for (int i = 2; i <= N; i = i + 2)
      swap(a[i], a[i - 1]);
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;

      for (int i = 1; i <= n; i++)
         cout << a[i] << " ";
      cout << endl;
   }
   return 0;
}