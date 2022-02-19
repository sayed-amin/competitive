#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll fast_exp(ll base, ll exp, ll mod)
{
   ll res = 1;
   while (exp)
   {
      if (exp % 2 == 0)
      {
         exp /= 2;
         base *= base;
         base %= mod;
      }
      else
      {
         exp--;
         res *= base;
         res %= mod;
      }
   }
   return res;
}
ll fact_inverse(ll a)
{
   return fact_inverse(a, 1000000007 - 2, 1000000007);
}
long long ncr(int n, int r)
{
   if (r > n)
      return 0;
   return (fact[n] * ((fact_inverse[r] * fact_inverse[n - r]) % MOD)) % MOD;
}
int main()
{
   pre();
   int n, m;
   cin >> n >> m;
   int b[n];
   int p = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> b[i];
      if (b[i] >= 1 && b[i] <= m)
      {
         p++;
      }
   }
   if (m < n)
   {
      cout << "0" << endl;
      return 0;
   }
   ll ans = (ncr(m, n) * fact[n]) % MOD;
   for (int j = 1; j <= p; j++)
   {
      ll val = ncr(p, j);
      val = (val * ncr(m - j, n - j)) % MOD;
      val = (val * fact[n - j]) % MOD;
      if (j & 1)
      {
         ans = (ans - val + MOD) % MOD;
      }
      else
      {
         ans = (ans + val) % MOD;
      }
   }
   cout << ans << endl;
   return 0;
}