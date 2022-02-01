#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main()
{
   vector<int> prime = seiveofearthoness(SIZE);

   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int ind = lower_bound(prime.begin(), prime.end(), n - 1) - prime.begin();
      if (prime[ind] > n - 1)
         ind--;
      ll sum = 0;
      ll max_sum = ll(n) * ll(prime[ind]);
      ll rem_nodes = n;
      for (int i = ind; i >= 0; i--)
      {
         ll unknow = min(rem_nodes, max_sum / prime[i]);
         if(i>= and )
      }
   }
}