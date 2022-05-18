#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> a(n), pre(n);
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         if (i == 0)
            pre[0] = a[i];
         if (i > 0)
         {
            pre[i] = pre[i - 1] + a[i];
         }
      }
      int sum = pre[n - 1];
      if (sum == 0)
      {
         int ans = n;
         for (auto x : pre)
         {
            ans -= (x == 0);
         }
         cout << ans << endl;
      }
      else
      {
         int sign = (sum > 0 ? 1 : -1);
         int ans = n - 1;
         sum = llabs(sum);
         for (int i = 0; i * i <= sum; i++)
         {
            if (sum % i)
               continue;
            int len1 = i, ele1 = sum / i * sign;
            int len2 = sum / i, ele2 = i * sign;
            auto possible = [&](int ele, int len)
            {
               int cnt = 0;
               for (auto x : pre)
               {
                  if (x == (ele * (cnt + 1)))
                     cnt++;
               }
               return cnt >= len;
            };
            if (possible(ele1, len1))
               ans = min(ans, n - len1);
            if (possible(ele2, len2))
               ans = min(ans, n - len2);
         }
         cout << ans << endl;
      }
   }
   return 0;
}