#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, n) for (ll i = 0; i < n; i++)
#define forn(i, n) for (ll i = 1; i < n; i++)
#define forne(i, n) for (ll i = 1; i <= n; i++)
#define revn(i, n) for (ll i = n - 1; i >= 0; i--)
#define sortl(v) sort(v.begin(), v.end())
#define reversal(v) reverse(v.begin(), v.end())
#define countset(n) __builtin_popcountll(n)
#define maxelement(v) *max_element(v.begin(), v.end())
#define minelement(v) *min_element(v.begin(), v.end())
#define vi vector<ll>
#define f(map) for (auto it : map)
#define read(n) \
    ll n;       \
    cin >> n;
const int inf = 1e9 + 7;
ll n, m;
vector<ll> visited(100005);
vi arr[100005];
vi clr(100005);

ll color;
bool dfs(ll node, ll color)
{
    visited[node] = 1;
    clr[node] = color;
    for (auto it : arr[node])
    {
        if (!visited[it])
        {
            if (dfs(it, 1 - color) == false)
            {
                return false;
            }
        }
        else
        {
            if (clr[it] == clr[node])
            {
                return false;
            }
        }
    }
    return true;
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
        forne(i, n)
        {
            arr[i].clear();
            visited[i] = 0;
            clr[i] = -1;
        }
        forne(i, m)
        {
            read(x);
            read(y);
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        color = 0;
        int cnt = 0;
        forne(i, n)
        {
            if (!visited[i])
            {
                if (!dfs(i, 1))
                {
                    cnt = 1;
                    break;
                }
            }
        }
        if (cnt)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        forne(i, n)
        {
            if (clr[i] == 0)
            {
                clr[i] = 2;
            }
        }
        forne(i, n)
        {
            cout << clr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
