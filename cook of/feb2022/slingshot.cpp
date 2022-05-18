// fenwick tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m, s;
const ll INF = 1e18;
struct fenwick
{
    int n;
    vector<ll> f;
    fenwick(int _n)
    {
        n = _n;
        f = vector<ll>(n + 1, -INF);
    }
    ll get(int r)
    {
        ll ans = 0;
        while (r > 0)
        {
            ans = max(f[r], ans);
            r &= (r - 1);
        }
        return ans;
    }
    void upd(int v, ll by)
    {
        while (v <= n)
        {
            f[v] = max(f[v], by);
            v &= (v | (v - 1)) + 1;
        }
    }
};
void solve()
{
    cin >> n >> m >> s;
    vector<vector<ll> > a(n + 1, vector<ll>(m + 1));
    vector<pair<int, pair<int, int> > > tt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            tt.emplace_back(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    sort(tt.begin(), tt.end());
    fenwick difA(n + m);
    fenwick difB(n + m);
    fenwick sumA(n + m);
    fenwick sumB(n + m);
    ll he = 0;
    for (auto &it : tt)
    {
        int x = it.second.first;
        int y = it.second.second;
        ll best = 0;
        best = max(best, difA.get(x - y + m - s - 1));
        best = max(best, difB.get(y - x + n - s - 1));
        best = max(best, sumA.get(x + y - s - 1));
        best = max(best, sumB.get(n + m + 1 - x - y - s - 1));
        best += it.first;
        he = max(he, best);
        difA.upd(x - y + m, best);
        difB.upd(y - x + n, best);
        sumA.upd(x + y, best);
        sumB.upd(n + m + 1 - x - y, best);
    }
    cout << he << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}