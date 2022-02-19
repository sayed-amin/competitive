#include <iostream>
#include <map>

using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      map<int, int> m1, m2;
      for (int i = 0; i < n; i++)
      {
         int a, b;
         cin >> a >> b;
         m1[a]++;
         m2[b]++;
      }
      int ans = m1.size() + m2.size();
      cout << ans << endl;
   }
   return 0;
}