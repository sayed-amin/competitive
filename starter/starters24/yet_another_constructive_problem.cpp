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
      int a = x;
      int b = x | (1 << 28);
      int c = x | (1 << 29);
      cout << a << " " << b << " " << c << endl;
   }

   return 0;
}