#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            m[s]++;
        }
        int a = 0, b = 0;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (i->first == "START38")
                a = i->second;
            else
                b = i->second;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
