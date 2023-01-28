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
vi parennt(100005);
ll start, ed;
ll a;
bool dfs(ll x, ll parent)
{
    visited[x] = 1;
    parennt[x] = parent;
    for (auto it : arr[x])
    {
        if (!visited[it])
        {
            if (dfs(it, x))
            {
                return true;
            }
        }
        else
        {
            if (it != parent)
            {
                start = x, ed = parennt[x];
                a = parennt[it];
                return true;
            }
        }
    }
    return false;
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
            visited[i] = 0;
            parennt[i] = -1;
            arr[i].clear();
        }
        forne(i, m)
        {
            read(x);
            read(y);
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        vector<ll> res;
        int cnt = 0;
        start = 0;
        ed = 0;
        forne(i, n)
        {

            if (!visited[i])
            {
                bool flag = dfs(i, -1);
                if (flag == true)
                {
                    cnt = 1;
                    break;
                }
            }
        }
        // cout << cnt << endl;
        cout << start << " " << ed << endl;
        res.clear();
        ll temp = start;
        if (cnt == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        while (parennt[start] != a)
        {
            res.push_back(start);
            start = parennt[start];
        }
        res.push_back(start);
        res.push_back(parennt[start]);
        res.push_back(temp);
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
