#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int x;
      cin >> x;
      x = x - 3;
      cout << x << " " << x + 2 << " " << x + 1 << endl;
   }
   return 0;
}