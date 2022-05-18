#include <bits/stdc++.h>
using namespace std;

void solve()
{
   int n;
   int p = 1;
   string s;
   cin >> n >> s;
   if (s[0] == '0' || s[1] == '0' || s[n] == '0')
   {
      cout << "No\n";
      return;
   }
   vector<int> v;
   v.push_back(0);
   for (int i = 2; i < s.size() - 1; i++)
   {
      if (s[i] == '0')
         v.push_back(i);
      else
      {
         v.push_back(p);
         p = i;
      }
   }
   v.push_back(p);
   cout << "Yes\n";
   for (auto it : v)
      cout << it << " ";
   cout << endl;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }
}