#include <iostream>
#include <string>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string s;
      cin >> s;
      s.pop_back();
      if (count(s.begin(), s.end(), '1') > 0)
         cout << "yes" << endl;
      else
         cout << "no" << endl;
   }
   return 0;
}