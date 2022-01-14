#include <iostream>

using namespace std;
#define int long long int
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
         int j;
         cin >> j;
         sum += j; /* code */
      }
      cout << sum / n << endl;
   }
   return 0;
}