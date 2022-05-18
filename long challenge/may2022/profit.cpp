#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int ra = n - x, rb = n - 1 - ra;
        int ca = n - y, cb = n - 1 - ca;
        int pp = min(n - x, n - y), mm = min(x - 1, y - 1);
        int pm = min(n - x, y - 1), mp = min(n - y, x - 1);
        cout << ra + rb + ca + cb + pp + pm + mp + mm << endl;
    }
    return 0;
}
