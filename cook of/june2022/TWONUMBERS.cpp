#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define all(_obj) _obj.begin(), _obj.end()
#define F first
#define S second
#define pll pair<ll, ll>
#define vll vector<ll>
ll INF = 1e18;
const int N = 3e5 + 11, mod = 1e9 + 7;
ll max(ll a, ll b) { return ((a > b) ? a : b); }
ll min(ll a, ll b) { return ((a > b) ? b : a); }
inline ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll a[N], maxbeauty, g[N], sumofg[N];
vll v[N];
void dfsforgcd(int u, int p = -1)
{
    g[u] = a[u];
    sumofg[u] = 0;
    for (auto x : v[u])
    {
        if (x == p)
            continue;
        dfsforgcd(x, u);
        g[u] = gcd(g[u], g[x]);
        sumofg[u] += g[x];
    }
}
void dfs(int u, int p, ll beautytillparent)
{
    ll beauty = beautytillparent;
    if (p != -1)
        beauty += sumofg[p] - g[u];
    beautytillparent = beauty;
    for (auto x : v[u])
    {
        if (x == p)
            continue;
        dfs(x, u, beautytillparent);
        beauty += g[x];
    }

    maxbeauty = max(maxbeauty, beauty);
}
void sol(void)
{
    int n;
    cin >> n;
    maxbeauty = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], v[i].clear();
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfsforgcd(1);
    dfs(1, -1, 0);

    cout << maxbeauty << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
        sol();
}
