// C++ program for above approach
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int main()
{
   int n;
   n = 4;
   vector<int> a[n];
   a[3].push_back(1);
   a[3].push_back(1);
   a[3].push_back(1);
   a[3].push_back(1);
   for (auto i : a[3])
      cout << i << " ";

   return 0;
}
