#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string s = "";
      int n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
         s += 'a' + (i % 26);
      }
      cout << s << endl;
   }
}
