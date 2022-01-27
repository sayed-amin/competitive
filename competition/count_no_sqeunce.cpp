#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > table(1e5, vector<int>(20, 0));
vector<vector<int> > tree;
int main()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      cin >> table[i][0];
   }
}