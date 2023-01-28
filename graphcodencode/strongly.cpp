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

vi ar[1001];
vi tr[1001];
vi visited(1001);
vi order;
vi scc;
void dfs(ll node)
{
    visited[node] = 1;
    for (auto it : ar[node])
    {
        if (!visited[it])
            dfs(it);
    }
    order.push_back(node);
}
void dfs1(ll node)
{
    visited[node] = 1;
    for (auto it : tr[node])
    {
        if (!visited[it])
            dfs1(it);
    }
    scc.push_back(node);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while (test--)
    {
        read(n);
        read(m);
        forne(i, n)
        {
            visited[i] = 0;
            ar[i].clear();
            tr[i].clear();
        }
        order.clear();
        forne(i, m)
        {
            read(x);
            read(y);
            ar[x].push_back(y);
            tr[y].push_back(x);
        }
        forne(i, n)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        reversal(order);
        forne(i, n)
        {
            visited[i] = 0;
        }
        forne(i, n)
        {
            if (!visited[order[i]])
            {
                scc.clear();
                dfs1(order[i]);
                cout << "dfs1 called" << order[i] << "stronglly component are" << endl;
                for (auto it : scc)
                {
                    cout << it << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
