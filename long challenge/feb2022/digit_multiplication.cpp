// matrix exponentiation
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define int long long

#define endl "\n"
#define f(i, k) for (int i = 0; i < k; i++)
int MOD = (1e9) + 7;
void prepocess(vector<vector<int> > &F, int k)
{ // f[c][j] represents the count of j in c*k
   f(c, 10)
   {
      f(j, 10)
      {
         int x = c * k;
         if (x == 0 and x == j)
         {
            F[c][j] += 1;
            continue;
         }
         while (x > 0)
         {
            if (x % 10 == j)
               F[c][j]++;
            x /= 10;
         }
      }
   }
}
vector<vector<int> > multiply(vector<vector<int> > &A, vector<vector<int> > &B, int N)
{
   vector<vector<int> > product(N, vector<int>(N, 0));
   f(i, N)
   {
      f(j, N)
      {
         f(k, N)
         {
            product[i][j] += (A[i][k] * B[k][j]);
            product[i][j] %= MOD;
         }
      }
   }
   return product;
}
vector<vector<int> > power(vector<vector<int> > &F, int N)
{
   vector<vector<int> > ans(10, vector<int>(10, 0));
   f(i, 10)
       ans[i][i] = 1;
   while (N)
   {
      if (N & 1)
      {
         ans = multiply(ans, F, 10);
      }
      N >>= 1;
      F = multiply(F, F, 10);
   }
   return ans;
}
void solve()
{
   int n, k, m;
   cin >> n >> k >> m;
   string s;
   cin >> s;
   vector<vector<int> > F(10, vector<int>(10, 0LL));
   prepocess(F, k);
   vector<int> count(10, 0LL);
   for (char ch : s)
   {
      count[ch - '0']++;
   }
   vector<vector<int> > matrix = power(F, m);
   int total = 0;
   f(i, 10)
   {
      f(j, 10)
      {
         total += (count[i] * matrix[i][j]);
         total %= MOD;
      }
   }
   cout << total << endl;
}
signed main()
{
   int t;
   cin >> t;
   while (t--)
   {
      solve();
   }
   return 0;
}