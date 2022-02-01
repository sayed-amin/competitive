#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, k, x;
      cin >> n >> k >> x;
      int flag = 0;
      for (int i = 0; i < n; i++)
         cout << n - x << " ";
      cout << endl;
   }
   return 0;
}