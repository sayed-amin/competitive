#include <iostream>
#include <map>
#include <iterator>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while ((t--))
   {
      int m, x;
      cin >> m >> x;

      for (int i = 1; i <= x; i++)
      {
         map<int, int> mp;
         map<int, int>::iterator it, p;
         for (int j = 1; j <= i; j++)
         {
            mp[j]++;
         }
         int ans;
         while (mp.size() != 1)
         {
            it = mp.begin();

            it = mp.find(((it->first) + m - 1) % mp.size());

            mp.erase(it);
         }
         it = mp.begin();
         cout << it->first << endl;
      }
   }
   return 0;
}