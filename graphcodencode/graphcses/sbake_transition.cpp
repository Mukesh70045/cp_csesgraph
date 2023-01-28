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
ll arr[1000][1000];
bool vis[1000][1000];
ll level[1000][1000];
ll mx;
ll ans;
bool isvalid(ll x, ll y)
{
    // if it is one base indexed;
    // if (input[x][y] == '#')
    //     return false;
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (vis[x][y] == true)
        return false;
    return true;
}
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
void bfs()
{
    queue<pair<ll, ll>> mxq;

    forne(i, n)
    {
        forne(j, m)
        {
            if (arr[i][j] == mx)
            {
                // cout << mx << endl;
                mxq.push({i, j});
                vis[i][j] = true;
                level[i][j] = 0;
                // cout << i << " " << j << endl;
            }
        }
    }
    while (!mxq.empty())
    {
        ll curr_x = mxq.front().first;
        ll curr_y = mxq.front().second;
        mxq.pop();
        for (int i = 0; i < 8; i++)
        {
            if (isvalid(curr_x + dx[i], curr_y + dy[i]))
            {
                level[curr_x + dx[i]][curr_y + dy[i]] = level[curr_x][curr_y] + 1;
                vis[curr_x + dx[i]][curr_y + dy[i]] = true;
                mxq.push({curr_x + dx[i], curr_y + dy[i]});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        forne(i, n)
        {
            forne(j, m)
            {

                arr[i][j] = 0;
                vis[i][j] = false;
                level[i][j] = 0;
            }
        }

        forne(i, n)
        {
            forne(j, m)
            {
                cin >> arr[i][j];
            }
        }
        mx = 0;
        forne(i, n)
        {
            forne(j, m)
            {
                mx = max(arr[i][j], mx);
            }
        }
        ans = -1;
        // cout << mx << endl;
        bfs();
        forne(i, n)
        {
            forne(j, m)
            {
                ans = max(level[i][j], ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
