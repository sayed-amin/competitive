#include <iostream>
#include <vector>
using namespace std;
void print_output(vector<pair<int, int> > ops)
{
   cout << ops.size() << endl;
   for (auto [x, y] : ops)
   {
      cout << x + 1 << " " << y + 1 << endl;
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> a(n);
      bool isodd = false, odd = false, even = false;
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         if (a[i] & 1)
         {
            isodd = true;
            if (i & 1)
               odd = true;
            else
               even = true;
         }
      }
      if (!isodd)
         cout << -1 << endl;
      else
      {
         vector<pair<int, int> > op1, op2;
         if (odd)
         {
            int oddpos = -1;
            for (int i = 1; i < n; i++)
            {
               if ((a[i] & 1) && (i & 1))
               {
                  oddpos = i;
               }
            }
            for (int i = 0; i < n; i++)
            {
               if (!(i & 1) and (a[i] & 1))
               {
                  op1.push_back({i, oddpos});
               }
               else if ((i & 1) and !(a[i] & 1))
               {
                  op1.push_back({i, oddpos});
               }
            }
         }
         if (even)
         {
            int evenpos = -1;
            for (int i = 0; i < n; i++)
            {
               if ((a[i] & 1) && !(i & 1))
               {
                  evenpos = i;
               }
            }
            for (int i = 0; i < n; i++)
            {
               if (!(i & 1) and !(a[i] & 1))
               {
                  op2.push_back({i, evenpos});
               }
               else if ((i & 1) and (a[i] & 1))
               {
                  op2.push_back({i, evenpos});
               }
            }
         }
         int ans1 = op1.size(), ans2 = op2.size();
         if (odd & even)
         {
            if (ans1 < ans2)
               print_output(op1);
            else
               print_output(op2);
         }
         else if (odd)
         {
            print_output(op1);
         }
         else
            print_output(op2);
      }
   }
   return 0;
}