#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, n) for (ll i = 0; i < n; i++)
#define forn(i, n) for (ll i = 1; i < n; i++)
#define forne(i, n) for (ll i = 1; i <= n; i++)
#define revn(i, n) for (ll i = n - 1; i >= 0; i--)
#define sortl(v) sort(v.begin(), v.end())
#define countset(n) __builtin_popcountll(n)
#define maxelement(v) *max_element(v.begin(), v.end())
#define minelement(v) *min_element(v.begin(), v.end())
#define f(map) for (auto it : map)
#define read(n) \
    ll n;       \
    cin >> n;
const int inf = 1e9 + 7;
bool visited[10001][10001];
ll n,
    m;
bool isvalid(ll x, ll y)
{
    // if it is one base indexed;
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    if (visited[x][y])
        return false;
    return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(ll x, ll y)
{
    visited[x][y] = true;
    cout << x << " " << y << endl;
    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {

        cin >> n >> m;
        dfs(1, 1);
    }

    return 0;
}
