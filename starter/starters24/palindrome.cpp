#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long
int main(){
   vector<int> subs[1024];
   for (int i = 0; i < 1024;i++)
   {
      for (int j = 0; j < 1024;j++){
         if((j&i)==i){
            subs[j].push_back(i);
         }
      }
   }
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      string s;
      cin >> s;
      int ct[10] = {0};
      for (int i = 0; i < n;i++){
         ct[s[i] - '0']++;
      }
      int a[n + 1];
      a[0] = 0;
      for (int i = 0; i < n;i++){
         cin >> a[i + 1];
      }
   }
}