#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int log_a_to_base_b(int a, int b)
{
   return log(a) / log(b);
}

int main()
{
   // your code goes here
   ll t;
   cin >> t;
   while (t--)
   {
      ll k;
      cin >> k;
      ll count = 0;
      while (k % 2 == 0)
      {
         count++;
         k = k / 2;
      }
      cout << count << endl;
   }
   return 0;
}
