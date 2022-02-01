#include <iostream>
#include <vector>
using namespace std;
#define int long long
int lis(vector<int> &a)
{
   vector<int> lis;
   for (auto &x : a)
   {
      auto it = upper_bound(lis.begin(), lis.end(), x);
      if (it == lis.end())
         lis.push_back(x);
      else
         *it = x;
   }
   return lis.size();
}
int32_t main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      vector<int> a(n), b(m);
      for (int &x : a)
         cin >> x;
      for (int &x : b)
         cin >> x;
      cout << lis(a) + lis(b) << endl;
   }
   return 0;
}