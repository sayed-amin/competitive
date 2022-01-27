#include <iostream>
#include <cmath>
using namespace std;
int log_a_to_base_b(int a, int b)
{
   return log(a) / log(b);
}

int main()
{
   // your code goes here
   int t;
   cin >> t;
   while (t--)
   {
      int k;
      cin >> k;
      if (k & 1)
         cout << "0";
      else
      {
         cout << log_a_to_base_b(k, 2) << endl;
      }
   }
   return 0;
}
