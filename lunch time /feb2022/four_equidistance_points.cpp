#include <iostream>
using namespace std;
int main()
{
    int d;
    cin >> d;
    if (d & 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << d << endl;
        cout << d / 2 << " " << d / 2 << endl;
        cout << -d / 2 << " " << d / 2 << endl;
    }

    return 0;
}