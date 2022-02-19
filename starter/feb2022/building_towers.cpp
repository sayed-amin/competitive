#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      long long int x, m;
      cin >> x >> m;
      long long n = ceil(log2(x)) + 1;
      if (m < n)
         cout << 0 << endl;
      else
         cout << m - n + 1 << endl;
   }
   return 0;
}