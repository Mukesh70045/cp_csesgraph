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
vector<ll> visited(100000 + 5);
vector<ll> arr[100000 + 5];
vector<ll> dist(100000 + 5);
vector<ll> parennt(100000 + 5);
bool bfs(ll x)
{
    queue<ll> q;
    q.push(x);
    visited[x] = 1;
    dist[x] = 0;
    parennt[x] = -1;
    while (q.empty() == false)
    {
        ll curr = q.front();
        q.pop();
        for (auto it : arr[curr])
        {
            if (visited[it] == 0)
            {
                parennt[it] = curr;
                visited[it] = 1;
                dist[it] = (dist[curr] + 1);
                q.push(it);
            }
        }
    }
    if (dist[n] != -1)
    {
        return true;
    }
    else
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
            arr[i].clear();
            dist[i] = -1;
            parennt[i] = -1;
        }
        forne(i, m)
        {
            read(x);
            read(y);
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        bool flag = bfs(1);
        if (!flag)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<ll> ans;
        ll temp = n;
        while (parennt[temp] != -1)
        {
            ans.push_back(temp);
            temp = parennt[temp];
        }
        ans.push_back(1);
        reversal(ans);
        cout << dist[n] + 1 << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
