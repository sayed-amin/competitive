#include <iostream>
#include <vector>
using namespace std;
const int max_ai = 500000;

#define endl "\n"
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin >> t;
   while (t--)
   {
      int n, x;
      cin >> n >> x;
      if (n == 1)
      {
         cout << x << endl;
         continue;
      }
      vector<int> ans(n);
      int temp = 0;
      for (int i = 0; i < n - 1; i++)
      {
         ans[i] = i;
         temp ^= ans[i];
      }
      int last = x ^ temp;
      int set_18 = (1LL << 18);
      if (last >= (n - 1) && last <= max_ai)
      {
         ans[n - 1] = last;
      }
      else
      {
         ans[n - 1] = last ^ set_18;
         if ((ans[0] ^ set_18) == ans[n - 1])
            ans[1] ^= set_18;
         else
            ans[0] ^= set_18;
      }
      for (auto ele : ans)
      {
         cout << ele << " ";
      }
      cout << endl;
   }
   return 0;
}