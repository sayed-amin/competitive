#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
   freopen("/Users/amin/Documents/template/input.txt", "r", stdin);
   freopen("/Users/amin/Documents/template/output.txt", "w", stdout);
#endif
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