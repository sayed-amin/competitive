#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      string s;
      cin >> s;
      int flag = 0;
      map<char, int> m;
      for (int i = 0; i < n; i++)
      {
         m[s[i]]++;
      }
      string b;
      map<char, int>::iterator it;
      for (it = m.begin(); it != m.end(); it++)
      {
         int count = it->second;
         if (count > n / 2)
            flag = 1;
         while (count)
         {
            b += it->first;
            count--;
         }
      }
      if (n & 1)
         cout << "no" << endl;
      else
      {
         if (flag == 1)
            cout << "no" << endl;
         else
         {
            reverse(b.begin(), b.begin() + n / 2);
            cout << "yes" << endl;
            cout << b << endl;
         }
      }
   }
   return 0;
}